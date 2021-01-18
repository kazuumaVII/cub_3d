/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrance <frfrance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:58:59 by frfrance          #+#    #+#             */
/*   Updated: 2020/01/27 15:08:03 by frfrance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup_c(int c)
{
	char	*str;
	int		i;
	char	j;

	j = (char)c;
	i = 0;
	if (!j)
	{
		if (!(str = malloc(1 * sizeof(char))))
			return (NULL);
	}
	else
	{
		if (!(str = malloc(1 * sizeof(char))))
			return (NULL);
	}
	if (j)
		str[i++] = j;
	str[i] = '\0';
	return (str);
}
