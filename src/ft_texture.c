/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrance <frfrance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 17:00:18 by frfrance          #+#    #+#             */
/*   Updated: 2020/06/01 17:02:29 by frfrance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_sprite_color(t_all *all, t_img *text, t_sprite *sprite)
{
	int x;

	sprite->wall_x = (float)(sprite->stripe - sprite->draw_start_x) /
		(float)(sprite->draw_end_x - sprite->draw_start_x);
	sprite->tex_y = (sprite->pix * 2 - all->prsg.y_r +
		sprite->h) * (text->h / 2) / sprite->h;
	sprite->tex_x = (int)(sprite->wall_x * text->w);
	sprite->tex_x = text->w - sprite->tex_x - 1.0;
	x = (text->w * sprite->tex_y) + sprite->tex_x;
	sprite->color = text->mapping[x];
}

void	ft_color_calcul(t_all *all, t_cam *cam, t_img *text)
{
	int x;

	cam->text_y = (cam->draw_start * 2 - all->prsg.y_r + cam->haut_lign) *
		(text->h / 2) / cam->haut_lign;
	cam->text_x = (int)(cam->wall_x * text->w);
	cam->text_x = text->w - cam->text_x - 1.0;
	x = (text->w * cam->text_x) + cam->text_y;
	cam->color = text->mapping[x];
}

void	ft_texture(t_all *all)
{
	if (all->cam.hit == 2)
		all->cam.color = 0x000000;
	else if (all->cam.side && all->cam.ray_dir_y < 0)
		ft_color_calcul(all, &all->cam, &all->text.t_we);
	else if (all->cam.side && all->cam.ray_dir_y > 0)
		ft_color_calcul(all, &all->cam, &all->text.t_ea);
	else if (!all->cam.side && all->cam.ray_dir_x < 0)
		ft_color_calcul(all, &all->cam, &all->text.t_no);
	else if (!all->cam.side && all->cam.ray_dir_x > 0)
		ft_color_calcul(all, &all->cam, &all->text.t_so);
}

void	ft_file_img(t_all *all, t_img *text)
{
	int	x;
	int	y;
	int bpp;

	if (!(text->image = mlx_xpm_file_to_image(all->mlx.m_i, text->name,
		&text->w, &text->h)))
	{
		ft_printf("\nError\nTexture non valide\n");
		ft_close_win(all);
		exit(0);
	}
	ft_flag_xpm(text->name);
	text->mapping = (int *)mlx_get_data_addr(text->image, &y, &x, &bpp);
}

void	ft_color_center(t_all *all)
{
	ft_file_img(all, &all->text.t_no);
	ft_file_img(all, &all->text.t_so);
	ft_file_img(all, &all->text.t_we);
	ft_file_img(all, &all->text.t_ea);
	ft_file_img(all, &all->text.t_s);
}
