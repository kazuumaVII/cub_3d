/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrance <frfrance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 13:14:44 by frfrance          #+#    #+#             */
/*   Updated: 2020/05/04 20:51:00 by frfrance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_forward(t_all *all, t_curs *curs)
{
	if (all->prsg.t_m[(int)(curs->po_x + curs->di_x * curs->mv_speed)]
		[(int)curs->po_y] != '1')
		curs->po_x += curs->di_x * curs->mv_speed;
	if (all->prsg.t_m[(int)curs->po_x][(int)(curs->po_y + curs->di_y *
		curs->mv_speed)] != '1')
		curs->po_y += curs->di_y * curs->mv_speed;
	if (all->prsg.t_m[(int)curs->po_x][(int)curs->po_y] == '2')
		all->hud.pdv -= 7.7;
}

void	ft_back(t_all *all, t_curs *curs)
{
	if (all->prsg.t_m[(int)(curs->po_x - curs->di_x * curs->mv_speed)]
		[(int)curs->po_y] != '1')
		curs->po_x -= curs->di_x * curs->mv_speed;
	if (all->prsg.t_m[(int)curs->po_x][(int)(curs->po_y - curs->di_y *
		curs->mv_speed)] != '1')
		curs->po_y -= curs->di_y * curs->mv_speed;
	if (all->prsg.t_m[(int)curs->po_x][(int)curs->po_y] == '2')
		all->hud.pdv -= 7.7;
}

void	ft_left(t_all *all, t_curs *curs)
{
	if (all->prsg.t_m[(int)(curs->po_x - all->cam.plan_x * curs->mv_speed)]
		[(int)curs->po_y] != '1')
		curs->po_x -= all->cam.plan_x * curs->mv_speed;
	if (all->prsg.t_m[(int)curs->po_x][(int)(curs->po_y - all->cam.plan_y *
		curs->mv_speed)] != '1')
		curs->po_y -= all->cam.plan_y * curs->mv_speed;
	if (all->prsg.t_m[(int)curs->po_x][(int)curs->po_y] == '2')
		all->hud.pdv -= 7.7;
}

void	ft_right(t_all *all, t_curs *curs)
{
	if (all->prsg.t_m[(int)(curs->po_x + all->cam.plan_x * curs->mv_speed)]
		[(int)curs->po_y] != '1')
		curs->po_x += all->cam.plan_x * curs->mv_speed;
	if (all->prsg.t_m[(int)curs->po_x][(int)(curs->po_y + all->cam.plan_y *
		curs->mv_speed)] != '1')
		curs->po_y += all->cam.plan_y * curs->mv_speed;
	if (all->prsg.t_m[(int)curs->po_x][(int)curs->po_y] == '2')
		all->hud.pdv -= 7.7;
}
