/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hud.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrance <frfrance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:57:48 by frfrance          #+#    #+#             */
/*   Updated: 2020/05/04 20:50:46 by frfrance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_life_or_dead(t_all *all)
{
	if (all->hud.pdv <= 0)
	{
		ft_printf("\nYou dead mon pote\n4heures de TIG\n");
		ft_close_win(all);
	}
	else if (all->prsg.t_m[(int)all->curs.po_x][(int)all->curs.po_y] == 'X')
	{
		ft_printf("GG mon pote\nTa dead ca chacal\nMet pouce bleue\n");
		ft_close_win(all);
	}
}

void	ft_barre_life(t_all *all, t_hud *hud)
{
	hud->lb_start_x = (all->prsg.x_r / 20) * 7;
	hud->lb_start_y = (all->prsg.y_r / 20) * 19.3;
	hud->lb_w = (all->prsg.x_r / 20) * 6;
	hud->lb_h = (all->prsg.y_r / 20) * 0.4;
	hud->lb_end_x = (hud->lb_start_x + hud->lb_w);
	hud->lb_end_y = (hud->lb_start_y + hud->lb_h);
	hud->lb_x = hud->lb_start_x - 1;
	while (++hud->lb_x < hud->lb_end_x)
	{
		hud->lb_y = hud->lb_start_y - 1;
		while (++hud->lb_y < hud->lb_end_y)
		{
			if (hud->lb_x == hud->lb_start_x || hud->lb_y == hud->lb_start_y ||
			hud->lb_x == hud->lb_end_x - 1 || hud->lb_y == hud->lb_end_y - 1)
				ft_put_pixel_j(all, hud->lb_y, hud->lb_x, 0x212121);
			else if (hud->pdv_r && (hud->lb_x - hud->lb_start_x) /
				(hud->lb_end_x - hud->lb_start_x) <
				(float)hud->pdv / (float)hud->pdv_r)
				ft_put_pixel_j(all, hud->lb_y, hud->lb_x, 0x641E16);
		}
	}
}
