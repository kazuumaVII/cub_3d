/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrance <frfrance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 20:20:02 by frfrance          #+#    #+#             */
/*   Updated: 2020/06/01 17:26:32 by frfrance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			ft_str_to_tab(char *str, t_list **tab)
{
	t_list		*new_e;
	char		*tmp;

	if (!(tmp = ft_not_skip_space(str)))
		return (0);
	new_e = ft_lstnew(tmp);
	ft_lstadd_back(tab, new_e);
	return (1);
}

char		*ft_not_skip_space(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	j = 0;
	i = -1;
	if (!(tmp = ft_calloc(sizeof(char), ft_strlen(str) + 1)))
		return (NULL);

	while (str[++i])
	{
		tmp[j] = str[i];
		j++;
	}
	tmp[j] = '\0';
	return (tmp);
}
