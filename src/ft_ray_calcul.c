/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_calcul.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrance <frfrance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:40:48 by frfrance          #+#    #+#             */
/*   Updated: 2020/05/04 20:51:23 by frfrance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_val(t_all *all, int x)
{
	all->cam.cam_x = (2.0 * (float)x / (float)all->prsg.x_r - 1.0);
	all->cam.ray_po_x = all->curs.po_x;
	all->cam.ray_po_y = all->curs.po_y;
	all->cam.ray_dir_x = all->curs.di_x + all->cam.plan_x * all->cam.cam_x;
	all->cam.ray_dir_y = all->curs.di_y + all->cam.plan_y * all->cam.cam_x;
	all->cam.map_x = (int)all->cam.ray_po_x;
	all->cam.map_y = (int)all->cam.ray_po_y;
	all->cam.dta_dist_x = sqrt(1.0 + (all->cam.ray_dir_y * all->cam.ray_dir_y)
		/ (all->cam.ray_dir_x * all->cam.ray_dir_x));
	all->cam.dta_dist_y = sqrt(1.0 + (all->cam.ray_dir_x * all->cam.ray_dir_x)
		/ (all->cam.ray_dir_y * all->cam.ray_dir_y));
	all->cam.hit = 0;
	all->cam.side = 0;
}

void	ft_vector_r(t_all *all)
{
	if (all->cam.ray_dir_x < 0)
	{
		all->cam.step_x = -1.0;
		all->cam.side_dist_x = (all->cam.ray_po_x - all->cam.map_x)
			* all->cam.dta_dist_x;
	}
	else
	{
		all->cam.step_x = 1.0;
		all->cam.side_dist_x = (all->cam.map_x + 1 - all->cam.ray_po_x)
			* all->cam.dta_dist_x;
	}
	if (all->cam.ray_dir_y < 0)
	{
		all->cam.step_y = -1.0;
		all->cam.side_dist_y = (all->cam.ray_po_y - all->cam.map_y)
			* all->cam.dta_dist_y;
	}
	else
	{
		all->cam.step_y = 1.0;
		all->cam.side_dist_y = (all->cam.map_y + 1 - all->cam.ray_po_y)
			* all->cam.dta_dist_y;
	}
}

void	ft_hit_ray(t_all *all)
{
	while (!all->cam.hit)
	{
		if (all->cam.side_dist_x < all->cam.side_dist_y)
		{
			all->cam.side_dist_x += all->cam.dta_dist_x;
			all->cam.map_x += all->cam.step_x;
			all->cam.side = 0;
		}
		else
		{
			all->cam.side_dist_y += all->cam.dta_dist_y;
			all->cam.map_y += all->cam.step_y;
			all->cam.side = 1;
		}
		if (all->prsg.t_m[all->cam.map_x][all->cam.map_y] == '1')
			all->cam.hit = 1;
		else if (all->prsg.t_m[all->cam.map_x][all->cam.map_y] == '2')
			ft_sprite_complete(all);
		else if (all->prsg.t_m[all->cam.map_x][all->cam.map_y] == 'X')
			all->cam.hit = 2;
	}
}

void	ft_draw_start(t_all *all)
{
	if (!all->cam.side)
		all->cam.perp_wall_dis = fabs(((float)all->cam.map_x -
		all->cam.ray_po_x + (1.0 - all->cam.step_x) / 2.0) /
		all->cam.ray_dir_x);
	else
		all->cam.perp_wall_dis = fabs(((float)all->cam.map_y -
			all->cam.ray_po_y + (1.0 - all->cam.step_y) / 2.0)
			/ all->cam.ray_dir_y);
	all->cam.haut_lign = (int)fabs(all->prsg.y_r / all->cam.perp_wall_dis);
	all->cam.draw_start = -all->cam.haut_lign / 2 + all->prsg.y_r / 2;
	all->cam.draw_end = all->cam.haut_lign / 2 + all->prsg.y_r / 2;
	if (all->cam.draw_start < 0)
		all->cam.draw_start = 0;
	if (all->cam.draw_end >= all->prsg.y_r)
		all->cam.draw_end = all->prsg.y_r - 1;
}

void	ft_text_wall(t_all *all)
{
	if (all->cam.side)
		all->cam.wall_x = all->cam.ray_po_x + (((float)all->cam.map_y -
		all->cam.ray_po_y + (1.0 - all->cam.step_y) / 2.0) /
		all->cam.ray_dir_y) * all->cam.ray_dir_x;
	else
		all->cam.wall_x = all->cam.ray_po_y + (((float)all->cam.map_x -
		all->cam.ray_po_x + (1.0 - all->cam.step_x) / 2.0) /
		all->cam.ray_dir_x) * all->cam.ray_dir_y;
	all->cam.wall_x -= floor(all->cam.wall_x);
}
