/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrance <frfrance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:41:46 by frfrance          #+#    #+#             */
/*   Updated: 2020/06/01 17:17:03 by frfrance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_destroy_win(t_all *all, int option)
{
	if (all->text.t_no.image)
		mlx_destroy_image(all->mlx.m_i, all->text.t_no.image);
	if (all->text.t_so.image)
		mlx_destroy_image(all->mlx.m_i, all->text.t_so.image);
	if (all->text.t_we.image)
		mlx_destroy_image(all->mlx.m_i, all->text.t_we.image);
	if (all->text.t_ea.image)
		mlx_destroy_image(all->mlx.m_i, all->text.t_ea.image);
	if (all->text.t_s.image)
		mlx_destroy_image(all->mlx.m_i, all->text.t_s.image);
	if (all->mlx.m_w && option == 1)
	{
		mlx_clear_window(all->mlx.m_i, all->mlx.m_w);
		mlx_destroy_window(all->mlx.m_i, all->mlx.m_w);
	}
	if (all->mlx.img && option == 1)
		mlx_destroy_image(all->mlx.m_i, all->mlx.img);
}

int		ft_close_win(t_all *all)
{
	ft_destroy_win(all, 1);
	ft_lstclear(all->sprite, free);
	ft_free_ptrlst(all->ptr_lst);
	exit(0);
}

int		ft_open_w(t_all *all)
{
	all->curs.mv_speed = SPEED;
	all->curs.mv_speed_r = SPEED - 0.02;
	all->hud.pdv = 1000;
	all->hud.pdv_r = all->hud.pdv;
	if (!(all->mlx.m_i = mlx_init()))
		exit(0);
	ft_color_center(all);
	if (!(all->mlx.m_w = mlx_new_window(all->mlx.m_i, all->prsg.x_r,
		all->prsg.y_r, "Cube3D")))
		exit(0);
	ft_raycasting(all);
	mlx_put_image_to_window(all->mlx.m_i, all->mlx.m_w, all->mlx.img, 0, 0);
	mlx_do_key_autorepeatoff(all->mlx.m_i);
	mlx_hook(all->mlx.m_w, 2, (1L << 0), &ft_push_key, all);
	mlx_hook(all->mlx.m_w, 3, (1L << 1), &ft_k_release, all);
	mlx_hook(all->mlx.m_w, 17, (1l << 1), &ft_close_win, all);
	mlx_loop_hook(all->mlx.m_i, &ft_key_center, all);
	mlx_loop(all->mlx.m_i);
	return (0);
}
