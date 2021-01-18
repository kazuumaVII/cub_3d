/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrance <frfrance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:12:21 by alesanto          #+#    #+#             */
/*   Updated: 2020/02/26 13:24:56 by frfrance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *str)
{
	int		i;
	char	*dest;

	i = 0;
	if (!str)
	{
		dest = ft_strdup("(null)");
		return (dest);
	}
	if (!(dest = malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (NULL);
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
