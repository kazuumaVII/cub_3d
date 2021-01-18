/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrance <frfrance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 11:51:56 by frfrance          #+#    #+#             */
/*   Updated: 2020/05/04 15:11:24 by frfrance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_flag(char *str, t_struct *p)
{
	int	i;

	i = 0;
	if (*str)
	{
		while (str[i] == '-' || str[i] == '0')
		{
			if (str[i] == '-')
				p->t = -1;
			else
			{
				p->o = 1;
				p->z = 1;
				p->t = 1;
			}
			i++;
		}
	}
	return (i);
}

int	ft_width_nb(char *str, t_struct *p)
{
	int		i;

	i = 0;
	p->t == 0 ?
		p->t = 1 : 0;
	p->t *= ft_atoi(str);
	p->o *= p->t;
	p->z *= 2;
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}

int	ft_width(char *str, va_list *ptr, t_struct *p)
{
	int i;
	int j;

	i = 0;
	if (ft_isdigit(str[i]))
		i = ft_width_nb(str, p);
	else if (str[i] == '*')
	{
		i++;
		p->t == 0 ?
			p->t = 1 : 0;
		j = va_arg(*ptr, unsigned);
		if (j < 0)
			p->t *= p->t < 0 ? -j : j;
		else
			p->t *= j;
		p->o *= p->t;
	}
	return (i);
}

int	ft_precision(char *str, va_list *ptr, t_struct *p)
{
	int i;

	i = 0;
	if (str[i] == '.')
	{
		str++;
		p->prec = 0;
		if (ft_isdigit(str[i]))
		{
			p->prec = ft_atoi(str);
			while (ft_isdigit(str[i]))
				i++;
		}
		else if (str[i] == '*')
		{
			p->prec = va_arg(*ptr, unsigned);
			i++;
		}
		i++;
	}
	return (i);
}
