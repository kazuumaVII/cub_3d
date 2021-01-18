/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrance <frfrance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 12:23:29 by frfrance          #+#    #+#             */
/*   Updated: 2020/05/04 15:07:30 by frfrance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int			ft_find_f(char c, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void		ft_zero_s(t_struct *p, char str)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	j = (p->t > 0) ? p->t : -p->t;
	tmp = ft_calloc(sizeof(char), (j + 1));
	if (!ft_strlen(p->tab) && str == 'j')
		j--;
	while (j-- > ((!ft_strlen(p->tab) ? 0 : ft_strlen(p->tab))))
		tmp[i++] = '0';
	tmp[i] = '\0';
	tmp = ft_strjoin(tmp, p->tab, 1);
	free(p->tab);
	p->tab = tmp;
}
