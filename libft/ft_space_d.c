/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrance <frfrance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 16:37:35 by frfrance          #+#    #+#             */
/*   Updated: 2020/05/04 15:11:39 by frfrance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_space_d(char *str)
{
	char		*temp;
	int			i;

	i = 0;
	if (!ft_strlen(str))
		NULL;
	while (str[i] == ' ')
		i++;
	temp = ft_strdup(str + i);
	return (temp);
}
