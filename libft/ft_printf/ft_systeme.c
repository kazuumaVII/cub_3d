/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_systeme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrance <frfrance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 11:58:58 by frfrance          #+#    #+#             */
/*   Updated: 2020/05/04 15:09:49 by frfrance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		ft_string(char str, t_struct *p)
{
	char	*tmp;

	if (str == 's' && p->prec >= 0)
	{
		tmp = ft_substr(p->tab, 0, p->prec);
		free(p->tab);
		p->tab = tmp;
	}
}

void		ft_prec_nb(t_struct *p)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = p->n;
	if (p->prec > (ft_strlen(p->tab) - j))
	{
		tmp = ft_calloc(sizeof(char*), (p->prec + j + 1));
		if (j == 1)
			tmp[i++] = '-';
		while (p->prec-- > (ft_strlen(p->tab)) - j)
		{
			tmp[i++] = '0';
			p->z = 0;
		}
		tmp[i] = '\0';
		tmp = ft_strjoin(tmp, &p->tab[j], 1);
		free(p->tab);
		p->tab = tmp;
	}
}

void		ft_space_f(char str, t_struct *p)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	j = (p->t > 0) ? p->t : -p->t;
	tmp = ft_calloc(sizeof(char), (j + 1));
	if (!ft_strlen(p->tab) && str == 'c')
		j--;
	while (j-- > ((!ft_strlen(p->tab) ? 0 : ft_strlen(p->tab))))
		tmp[i++] = ' ';
	tmp[i] = '\0';
	if (p->t > 0)
		p->tab = ft_strjoin(tmp, p->tab, 3);
	else
		p->tab = ft_strjoin(p->tab, tmp, 3);
}

void		ft_ex(char str, t_struct *p)
{
	char	*tmp;

	if (ft_find_f(str, VALID_FLAGS_V2))
	{
		if (p->prec == 0 && p->tab[0] == '0')
		{
			tmp = ft_strdup("");
			free(p->tab);
			p->tab = tmp;
		}
		if (p->prec == -1)
		{
			p->prec = p->tab[0] == '-' ?
				p->o - 1 : p->o;
		}
	}
}

void		ft_systm(char str, t_struct *p)
{
	int i;

	i = 0;
	if (str == 'c' && !ft_strlen(p->tab))
		i = 1;
	ft_ex(str, p);
	ft_string(str, p);
	if (ft_find_f(str, VALID_FLAGS_V2))
	{
		p->tab[0] == '-' ? p->n = 1 : 0;
		ft_prec_nb(p);
	}
	if (str == 'p')
		p->tab = ft_strjoin("0x", p->tab, 2);
	if (((p->z != 0 && (str == '%' || str == 's')) || (p->z == 1
			&& (str == 'c' || str == 'd' || str == 'i' || str == 'u'
			|| str == 'x' || str == 'X'))) && (p->t > 0))
		ft_zero_s(p, str);
	else if (p->t != 0 && p->w != 1)
		ft_space_f(str, p);
	if (str == 'c' && i == 1 && p->t < 0)
		p->c = -1;
	else if (str == 'c' && i == 1)
		p->c = 1;
}
