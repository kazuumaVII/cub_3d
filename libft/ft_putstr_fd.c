/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrance <frfrance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:11:46 by alesanto          #+#    #+#             */
/*   Updated: 2020/01/04 15:10:16 by frfrance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *str, int fd)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	if (fd == -1)
		write(1, "\0", 1);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	if (fd == 1)
		write(1, "\0", 1);
	if (fd == 1 || fd == -1)
		i++;
	return (i);
}
