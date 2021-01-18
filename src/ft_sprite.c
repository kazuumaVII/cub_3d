/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrance <frfrance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 17:09:05 by frfrance          #+#    #+#             */
/*   Updated: 2020/05/04 20:51:34 by frfrance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_calcul_sprite_dist(t_all *all)
{
	float		x;
	float		y;
	t_sprite	*sprite;
	t_list		*lst;

	sprite = NULL;
	lst = *all->sprite;
	while (lst)
	{
		sprite = (t_sprite *)lst->content;
		x = powf(all->curs.po_x - (float)sprite->x, 2.0);
		y = powf(all->curs.po_y - (float)sprite->y, 2.0);
		sprite->dist = x + y;
		sprite->visible = 0;
		lst = lst->next;
	}
}

void	ft_sort_sprite(t_all *all)
{
	void		*temp;
	t_list		*current;
	t_list		*ori;
	t_sprite	*first;
	t_sprite	*second;

	ori = *all->sprite;
	current = *all->sprite;
	while (current && current->next)
	{
		first = current->content;
		second = (current->next)->content;
		if (first->dist >= second->dist)
			current = current->next;
		else
		{
			temp = current->content;
			current->content = (current->next)->content;
			(current->next)->content = temp;
			current = ori;
		}
	}
}

void	ft_init_sprite(t_all *all, t_sprite *sprite)
{
	sprite->s_x = sprite->x - all->curs.po_x;
	sprite->s_y = sprite->y - all->curs.po_y;
	sprite->inv_det = 1.0 / (all->cam.plan_x * all->curs.di_y -
		all->curs.di_x * all->cam.plan_y);
	sprite->trans_x = sprite->inv_det * (all->curs.di_y *
		sprite->s_x - all->curs.di_x * sprite->s_y);
	sprite->trans_y = sprite->inv_det * (-all->cam.plan_y *
		sprite->s_x + all->cam.plan_x * sprite->s_y);
	sprite->screen_x = (all->prsg.x_r / 2) * (1.0 +
		sprite->trans_x / sprite->trans_y);
	sprite->h = (int)fabs(all->prsg.x_r / sprite->trans_y) / 1.8;
	if ((sprite->draw_start_y = -sprite->h / 2 +
		all->prsg.y_r / 2) < 0)
		sprite->draw_start_y = 0;
	if ((sprite->draw_end_y = sprite->h / 2 +
		all->prsg.y_r / 2) >= all->prsg.y_r)
		sprite->draw_end_y = all->prsg.y_r - 1;
	sprite->w = (int)fabs(all->prsg.x_r / sprite->trans_y) / 6.6;
	sprite->draw_start_x = -sprite->w / 2 + sprite->screen_x;
	sprite->draw_end_x = sprite->w / 2 + sprite->screen_x;
}

void	ft_draws_sprite(t_all *all, t_sprite *sprite,
		float buff[all->prsg.x_r])
{
	sprite->stripe = sprite->draw_start_x - 1;
	while (++sprite->stripe < sprite->draw_end_x)
	{
		sprite->pix = sprite->draw_start_y - 1;
		if (sprite->stripe >= 0 && sprite->stripe < all->prsg.x_r
			&& sprite->trans_y < buff[sprite->stripe])
		{
			while (++sprite->pix < sprite->draw_end_y)
			{
				if (sprite->pix >= 0 && sprite->pix <= all->prsg.y_r)
				{
					ft_sprite_color(all, &all->text.t_s, sprite);
					if (sprite->color != 0xff000000)
						ft_put_pixel_j(all, sprite->pix, sprite->stripe,
							sprite->color);
				}
			}
		}
	}
}

void	ft_sprite_center(t_all *all, float buffer[all->prsg.x_r])
{
	t_list		*lst;
	t_sprite	*sprite;

	lst = *all->sprite;
	while (lst)
	{
		sprite = lst->content;
		if (sprite->visible)
		{
			ft_init_sprite(all, sprite);
			ft_draws_sprite(all, sprite, buffer);
		}
		lst = lst->next;
	}
}
