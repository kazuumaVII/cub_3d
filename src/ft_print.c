/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrance <frfrance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 10:57:17 by frfrance          #+#    #+#             */
/*   Updated: 2020/05/04 20:51:08 by frfrance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_print_cub_3d(t_all *all)
{
	int	i;

	i = 0;
	ft_printf("-----------------------------------------------------\n");
	ft_printf("|Resolution x|%d\n", all->prsg.x_r);
	ft_printf("|Resolution y|%d\n", all->prsg.y_r);
	ft_printf("\n");
	ft_printf("|Texture Nord   |%s\n", all->text.t_no.name);
	ft_printf("|Texture Sud    |%s\n", all->text.t_so.name);
	ft_printf("|Texture Ouest  |%s\n", all->text.t_we.name);
	ft_printf("|Texture Est    |%s\n", all->text.t_ea.name);
	ft_printf("\n");
	ft_printf("|Texture Sprite |%s\n", all->text.t_s.name);
	ft_printf("\n");
	ft_printf("|Couleur sol    |%d\n", all->prsg.t_f);
	ft_printf("|Couleur ciel   |%d\n", all->prsg.t_c);
	ft_printf("\n");
	ft_printf("\t\tMap utilise\n");
	while (all->prsg.t_m[i])
		ft_printf("%s\n", all->prsg.t_m[i++]);
	ft_printf("-----------------------------------------------------\n");
}
