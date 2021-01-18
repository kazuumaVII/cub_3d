/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrance <frfrance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:01:18 by frfrance          #+#    #+#             */
/*   Updated: 2020/05/04 20:50:52 by frfrance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_push_key(int k, t_all *all)
{
	if (k == 13)
		all->mv.go = 1;
	else if (k == 1)
		all->mv.back = 1;
	else if (k == 123)
		all->mv.left_q = 1;
	else if (k == 124)
		all->mv.right_e = 1;
	else if (k == 0)
		all->mv.left = 1;
	else if (k == 2)
		all->mv.right = 1;
	else if (k == 49)
		all->curs.mv_speed = 0.08;
	if (k == 53)
		ft_close_win(all);
	return (0);
}

int		ft_k_release(int k, t_all *all)
{
	if (k == 13)
		all->mv.go = 0;
	else if (k == 1)
		all->mv.back = 0;
	else if (k == 123)
		all->mv.left_q = 0;
	else if (k == 124)
		all->mv.right_e = 0;
	else if (k == 0)
		all->mv.left = 0;
	else if (k == 2)
		all->mv.right = 0;
	else if (k == 49)
		all->curs.mv_speed = SPEED;
	if (k == 53)
		ft_close_win(all);
	return (0);
}

int		ft_key_center(t_all *all)
{
	mlx_clear_window(all->mlx.m_i, all->mlx.m_w);
	if (all->mv.go)
		ft_forward(all, &all->curs);
	else if (all->mv.back)
		ft_back(all, &all->curs);
	if (all->mv.left)
		ft_left(all, &all->curs);
	else if (all->mv.right)
		ft_right(all, &all->curs);
	if (all->mv.left_q)
		ft_rot_left(all, &all->curs);
	else if (all->mv.right_e)
		ft_rot_right(all, &all->curs);
	ft_raycasting(all);
	ft_life_or_dead(all);
	mlx_put_image_to_window(all->mlx.m_i, all->mlx.m_w, all->mlx.img, 0, 0);
	return (0);
}
