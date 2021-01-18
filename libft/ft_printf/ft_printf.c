/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrance <frfrance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 11:25:01 by frfrance          #+#    #+#             */
/*   Updated: 2020/05/04 15:08:04 by frfrance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_type(char type, va_list *ptr, t_struct *p)
{
	if (type == 'c')
		p->tab = ft_strdup_c(va_arg(*ptr, int));
	else if (type == '%')
		p->tab = ft_strdup_c('%');
	else if (type == 's')
		p->tab = ft_strdup(va_arg(*ptr, char*));
	else if (type == 'd' || type == 'i')
		p->tab = ft_itoa_base_l(va_arg(*ptr, int), "0123456789");
	else if (type == 'u')
		p->tab = ft_itoa_base_l(va_arg(*ptr, unsigned), "0123456789");
	else if (type == 'x')
		p->tab =
			ft_itoa_base_l(va_arg(*ptr, unsigned), "0123456789abcdef");
	else if (type == 'X')
		p->tab =
			ft_itoa_base_l(va_arg(*ptr, unsigned), "0123456789ABCDEF");
	else if (type == 'p')
		p->tab = ft_itoa_base_l(va_arg(*ptr,
					long long int), "0123456789abcdef");
}

int		ft_arguments(char *str, va_list *ptr, t_struct *p)
{
	int i;

	i = 0;
	i += ft_flag(&str[i], p);
	if (*str && !(ft_isdigit(str[i])) && str[i] != '*')
		p->w = 1;
	i += ft_width(&str[i], ptr, p);
	i += ft_precision(&str[i], ptr, p);
	if (ft_find_f(str[i], VALID_FLAGS))
	{
		ft_type(str[i], ptr, p);
		ft_systm(str[i], p);
		return (++i);
	}
	return (0);
}

void	ft_struct_reset(t_struct *p)
{
	p->t = 0;
	p->o = 0;
	p->prec = -1;
	p->tab = NULL;
	p->n = 0;
	p->w = 0;
	p->z = 0;
	p->c = 0;
}

int		ft_center(char *str, va_list *ptr)
{
	t_struct	p;
	int			len;

	len = 0;
	while (*str)
	{
		ft_struct_reset(&p);
		if (*str == '%')
		{
			str++;
			str += ft_arguments(str, ptr, &p);
			if (p.tab)
				len += ft_putstr_t(p.tab, 1);
		}
		if (!p.tab && *str)
		{
			ft_putchar_fd(*str, 1);
			len++;
			str++;
		}
		free(p.tab);
	}
	return (len);
}

int		ft_printf(const char *argff, ...)
{
	va_list		ptr;
	char		*str;
	int			len;

	va_start(ptr, argff);
	str = (char *)argff;
	len = ft_center(str, &ptr);
	va_end(ptr);
	return (len);
}
