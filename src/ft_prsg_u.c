/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prsg_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrance <frfrance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:47:57 by frfrance          #+#    #+#             */
/*   Updated: 2020/06/01 17:02:51 by frfrance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int				ft_check_color(char *tmp)
{
	int		i;
	int		v;
	int		j;

	i = -1;
	j = 0;
	v = 0;
	while (tmp[++i])
	{
		if (!ft_isdigit(tmp[0]))
			j = 1;
		if (tmp[i] == ',')
			v++;
		if (!ft_isdigit(tmp[i]) && tmp[i] != ',')
			j = 1;
		if (tmp[i] == ',' && (!tmp[i + 1] || !tmp[i - 1]))
			j = 1;
		if (tmp[i] == ',' && tmp[i + 1] && tmp[i - 1])
			if (!ft_isdigit(tmp[i + 1]) || !ft_isdigit(tmp[i - 1]))
				j = 1;
	}
	if (v != 2)
		j = 1;
	return (j);
}

void			ft_verif_color(char *str)
{
	char	*tmp;
	int		error;

	error = 0;
	if (!ft_strlen(str))
		ft_print_exit("\nError\nCouleur manquante");
	if (!(tmp = ft_skip_space(str)))
		exit(0);
	if (ft_check_color(tmp))
		error = 1;
	free(tmp);
	if (error)
		ft_print_exit("\nError\nCouleur non valide");
}

void			ft_verif_resolution(t_all *all)
{
	if (all->prsg.x_r <= 0 || all->prsg.y_r <= 0)
		ft_print_exit("\nError\nMettre une resolution valide");
	ft_res_bmp(&all->prsg.x_r);
	ft_res_bmp(&all->prsg.y_r);
	if (all->prsg.x_r > 2560)
		all->prsg.x_r = 2560;
	if (all->prsg.y_r > 1440)
		all->prsg.y_r = 1440;
}

int				ft_check_res(t_all *all, char *str, t_prsg *prsg)
{
	if (str[0] == 'F')
	{
		prsg->t_f = ft_conver_color(str + 1);
		all->prsg.verif_f++;
	}
	else if ((int)prsg->t_f == -1)
		ft_print_exit("\nError\nCouleur manquante");
	else if (str[0] == 'C')
	{
		prsg->t_c = ft_conver_color(str + 1);
		all->prsg.verif_c++;
	}
	else if ((int)prsg->t_c == -1)
		ft_print_exit("\nError\nCouleur manquante");
	else if (all->prsg.verif_f != 1 || all->prsg.verif_c != 1)
		return (-1);
	else
		return (0);
	return (1);
}

void			ft_parsing(char *str, t_all *all, t_list **tab)
{
	if (ft_strlen(str))
	{
		if (!*tab && ft_center_prsg(str, all))
			return ;
		else if (!ft_str_to_tab(str, tab))
			exit(0);
		if (!*tab)
			ft_print_exit("\nError\nAucun parametre");
	}
	else if (*tab)
		ft_print_exit("\nError\nMauvais parametre donne");
}
