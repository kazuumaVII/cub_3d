/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draws.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrance <frfrance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:09:58 by frfrance          #+#    #+#             */
/*   Updated: 2020/06/01 17:09:08 by frfrance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_put_pixel_j(t_all *all, int x, int y, unsigned int color)
{
	int		(*pixel_a)[all->prsg.x_r][1];

	pixel_a = (void *)all->mlx.mapp;
	*pixel_a[x][y] = color;
}

void	ft_img(t_all *all)
{
	int		bpp;
	int		size;
	int		endian;

	all->mlx.img = mlx_new_image(all->mlx.m_i, all->prsg.x_r, all->prsg.y_r);
	all->mlx.mapp = mlx_get_data_addr(all->mlx.img, &bpp, &size, &endian);
}

void	ft_ground_a_sky(t_all *all, int x)
{
	int	i;

	i = 0;
	while (i < all->cam.draw_start)
		ft_put_pixel_j(all, i++, x, all->prsg.t_f);
	i = all->cam.draw_end - 1;
	while (i < all->prsg.y_r - 1)
		ft_put_pixel_j(all, i++, x, all->prsg.t_c);
}

void	ft_raycasting(t_all *all)
{
	int		x;
	float	buff[all->prsg.x_r];

	x = 0;
	ft_pos_r(all);
	if (!all->mlx.img)
		ft_img(all);
	ft_calcul_sprite_dist(all);
	ft_sort_sprite(all);
	while (x < all->prsg.x_r)
	{
		ft_ray_center(all, buff, x);
		while (all->cam.draw_start < all->cam.draw_end)
		{
			ft_texture(all);
			ft_put_pixel_j(all, all->cam.draw_start++, x, all->cam.color);
		}
		x++;
	}
	ft_sprite_center(all, buff);
	ft_barre_life(all, &all->hud);
}
