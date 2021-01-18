/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r_center.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrance <frfrance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 18:28:25 by frfrance          #+#    #+#             */
/*   Updated: 2020/05/04 20:51:19 by frfrance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_pos_r(t_all *all)
{
	if (all->curs.di_x == -1.0)
		all->cam.plan_y = 1.0;
	else if (all->curs.di_y == 1.0)
		all->cam.plan_x = 1.0;
	else if (all->curs.di_x == 1.0)
		all->cam.plan_y = -1.0;
	else if (all->curs.di_y == -1.0)
		all->cam.plan_x = -1.0;
}

void	ft_ray_center(t_all *all, float buff[all->prsg.x_r], int x)
{
	ft_init_val(all, x);
	ft_vector_r(all);
	ft_hit_ray(all);
	ft_draw_start(all);
	ft_text_wall(all);
	ft_ground_a_sky(all, x);
	buff[x] = all->cam.perp_wall_dis;
}
