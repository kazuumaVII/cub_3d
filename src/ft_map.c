/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrance <frfrance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:18:20 by frfrance          #+#    #+#             */
/*   Updated: 2020/05/04 21:14:09 by frfrance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_pop(t_all *all)
{
	if (all->curs.pop == 'W')
	{
		all->curs.di_x = 0;
		all->curs.di_y = -1;
	}
	else if (all->curs.pop == 'E')
	{
		all->curs.di_x = 0;
		all->curs.di_y = 1;
	}
	else if (all->curs.pop == 'N')
	{
		all->curs.di_x = -1;
		all->curs.di_y = 0;
	}
	else if (all->curs.pop == 'S')
	{
		all->curs.di_x = 1;
		all->curs.di_y = 0;
	}
}

void	ft_repop(char *str, t_all *all, int i)
{
	int j;

	j = -1;
	while (str[++j])
	{
		if (ft_find_c("NSEW", str[j]) != -1)
		{
			all->curs.pop = str[j];
			all->curs.po_y = j + 0.5;
			all->curs.po_x = i + 0.5;
			all->curs.ori_x = i;
			all->curs.ori_y = j;
			ft_init_pop(all);
			if (all->curs.spwan)
				ft_print_exit("\n\tError\nJoueur deja spawn");
			all->curs.spwan++;
		}
	}
}

void	ft_zero_space(char **str, int i, int j)
{
	if (str[i][j] != ' ' && str[i][j] != '1')
	{
		if (str[i][j + 1] == ' ' || !str[i][j + 1] || str[i][j - 1] == ' '
			|| !str[i][j - 1] || str[i - 1][j] == ' ' || !str[i - 1][j] ||
			str[i + 1][j] == ' ' || !str[i + 1][j])
			ft_print_exit("\nError\nMap non valide");
	}
}

void	ft_verif_line(char *str, int option)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] != '1' && str[i] != ' ')
		{
			if (option == 0)
				ft_print_exit("\nError\nMap premiere ligne");
			else
				ft_print_exit("\nError\nMap derniere ligne");
		}
	}
}

void	ft_verif_map(t_all *all)
{
	int	i;
	int	j;
	int error;

	error = 0;
	i = 0;
	while (all->prsg.t_m[i])
	{
		j = -1;
		if (!i)
			ft_verif_line(all->prsg.t_m[0], 0);
		if (all->prsg.t_m[i + 1])
		{
			while (all->prsg.t_m[i][++j])
			{
				if (ft_find_c("012XWESN ", all->prsg.t_m[i][j]) == -1)
					ft_print_exit("\n\tError\nCaractere");
				ft_zero_space(all->prsg.t_m, i, j);
			}
			ft_repop(all->prsg.t_m[i], all, i);
		}
		else
			ft_verif_line(all->prsg.t_m[i], 1);
		i++;
	}
}
