/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_t.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrance <frfrance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:00:29 by frfrance          #+#    #+#             */
/*   Updated: 2020/01/27 15:03:12 by frfrance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_t(char *s, int fd)
{
	if (!s || !fd)
		return (0);
	write(fd, s, ft_strlen(s));
	return ((int)ft_strlen(s));
}
