/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrance <frfrance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:07:57 by frfrance          #+#    #+#             */
/*   Updated: 2020/05/04 21:19:50 by frfrance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_res_bmp(int *res)
{
	int		r;

	if (*res % 2)
		*res += 1;
	r = *res % 100;
	if (r == 14 || r == 50 || r == 70 || r == 90 || r == 26
		|| r == 66 || r == 86 || r == 6 || r == 30 || r == 18
		|| r == 38 || r == 78 || r == 98 || r == 58)
		*res += 2;
}

void	ft_flag_bmp(char *str)
{
	if (ft_strlen(str) != 6 || str[0] != '-' || str[1] != '-' ||
		str[2] != 's' || str[3] != 'a' || str[4] != 'v' || str[5] != 'e')
		ft_print_exit("\nError\nMauvais argument bmp");
}

void	ft_flag_xpm(char *str)
{
	int i;

	i = ft_strlen(str) - 1;
	if (str[i] != 'M' || str[i - 1] != 'P' || str[i - 2] != 'X' ||
		str[i - 3] != '.')
	{
		ft_printf("\nError\n%s\nNom texture incorrect\n", str);
		exit(0);
	}
}

void	ft_flag_map(char *str)
{
	int i;

	i = ft_strlen(str) - 1;
	if (str[i] != 'b' || str[i - 1] != 'u' || str[i - 2] != 'c' ||
		str[i - 3] != '.')
	{
		ft_printf("\nError\nNom de map incorrect\n");
		exit(0);
	}
}
