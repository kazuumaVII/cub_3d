/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrance <frfrance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 10:52:08 by frfrance          #+#    #+#             */
/*   Updated: 2020/03/10 14:58:45 by frfrance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_skip_space(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	j = 0;
	i = -1;
	while (str[++i])
		if (str[i] == ' ')
			j++;
	if (!(tmp = ft_calloc(sizeof(char), i - j + 1)))
		return (NULL);
	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] != ' ')
		{
			tmp[j] = str[i];
			j++;
		}
	}
	tmp[j] = '\0';
	return (tmp);
}
