/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mv_rot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrance <frfrance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 17:23:40 by frfrance          #+#    #+#             */
/*   Updated: 2020/05/04 20:51:04 by frfrance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_rot_left(t_all *all, t_curs *curs)
{
	float	old_di_x;
	float	old_plan_x;

	old_di_x = curs->di_x;
	old_plan_x = all->cam.plan_x;
	curs->di_x = curs->di_x * cos(curs->mv_speed_r) -
		curs->di_y * sin(curs->mv_speed_r);
	curs->di_y = old_di_x * sin(curs->mv_speed_r) + curs->di_y *
		cos(curs->mv_speed_r);
	all->cam.plan_x = all->cam.plan_x * cos(curs->mv_speed_r) -
		all->cam.plan_y * sin(curs->mv_speed_r);
	all->cam.plan_y = old_plan_x * sin(curs->mv_speed_r) +
		all->cam.plan_y * cos(curs->mv_speed_r);
}

void	ft_rot_right(t_all *all, t_curs *curs)
{
	float	old_di_x;
	float	old_plan_x;

	old_di_x = curs->di_x;
	old_plan_x = all->cam.plan_x;
	curs->di_x = curs->di_x * cos(-curs->mv_speed_r) - curs->di_y *
		sin(-curs->mv_speed_r);
	curs->di_y = old_di_x * sin(-curs->mv_speed_r) + curs->di_y *
		cos(-curs->mv_speed_r);
	all->cam.plan_x = all->cam.plan_x * cos(-curs->mv_speed_r) -
		all->cam.plan_y * sin(-curs->mv_speed_r);
	all->cam.plan_y = old_plan_x * sin(-curs->mv_speed_r) + all->cam.plan_y *
		cos(-curs->mv_speed_r);
}
