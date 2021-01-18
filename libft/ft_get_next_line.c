/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrance <frfrance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:40:03 by frfrance          #+#    #+#             */
/*   Updated: 2020/05/04 15:05:14 by frfrance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_refresh_stock(char *stock, int i)
{
	char			*temp;

	if (stock[i])
	{
		temp = ft_strdup(stock + i + 1);
		free(stock);
	}
	else
	{
		free(stock);
		temp = NULL;
	}
	return (temp);
}

int			ft_free_all(int ret, char **buffer, char **stock)
{
	if (ret >= 0 && (*buffer || *stock))
	{
		if (*buffer)
			free(*buffer);
		if (ret == 0 && *stock)
			free(*stock);
	}
	if (ret == -1)
	{
		if (!*buffer)
			free(*buffer);
		if (*stock)
			free(*stock);
	}
	return (ret);
}

int			ft_get_next_line(int fd, char **line)
{
	static char		*stock;
	char			*buffer;
	int				ret;
	int				i;

	if (BUFFER_SIZE <= 0 || !line || fd < 0 ||
		!(buffer = (char *)ft_calloc(sizeof(char), (BUFFER_SIZE + 1))))
		return (ft_free_all(-1, &buffer, &stock));
	if (!stock)
		stock = (char *)ft_calloc(sizeof(char), 1);
	while (!ft_strchr(buffer, '\n') && (ret = read(fd, buffer, BUFFER_SIZE)))
	{
		if (ret == -1)
			return (ft_free_all(-1, &buffer, &stock));
		buffer[ret] = '\0';
		stock = ft_strjoin(stock, buffer, 1);
	}
	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	*line = ft_substr(stock, 0, i);
	stock = ft_refresh_stock(stock, i);
	if (ret || stock)
		return (ft_free_all(1, &buffer, &stock));
	return (ft_free_all(0, &buffer, &stock));
}
