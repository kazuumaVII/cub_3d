/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:14:45 by alesanto          #+#    #+#             */
/*   Updated: 2019/11/07 14:59:33 by alesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;
	size_t		size_len;

	i = 0;
	if (!s)
		return (0);
	if (start > (unsigned int)ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	size_len = ft_strlen(s);
	if (start < size_len)
	{
		while (i < len)
		{
			str[i] = s[start];
			i++;
			start++;
		}
	}
	str[i] = '\0';
	return (str);
}
