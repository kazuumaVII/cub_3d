/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrance <frfrance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:02:23 by frfrance          #+#    #+#             */
/*   Updated: 2020/01/27 15:12:29 by frfrance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa_base(long long int n, char *base)
{
	char		*str;

	if (!(str = (char *)ft_calloc(sizeof(char), 2)))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		str[1] = '\0';
		str = ft_strjoin(str, ft_itoa_base(-n, base), 3);
	}
	else if (n >= (long long int)ft_strlen(base))
	{
		free(str);
		str = ft_strjoin(ft_itoa_base(n / ft_strlen(base), base),
			ft_itoa_base(n % ft_strlen(base), base), 3);
	}
	else if (n < (long long int)ft_strlen(base) && n >= 0)
	{
		str[0] = base[n];
		str[1] = '\0';
	}
	return (str);
}
