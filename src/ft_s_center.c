/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_center.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrance <frfrance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:53:00 by frfrance          #+#    #+#             */
/*   Updated: 2020/05/04 20:51:28 by frfrance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		ft_sprite_complete(t_all *all)
{
	t_list		*lst;
	t_sprite	*sprite;

	lst = *all->sprite;
	while (lst)
	{
		sprite = lst->content;
		if (sprite->x == all->cam.map_x + 0.5 &&
			sprite->y == all->cam.map_y + 0.5)
			sprite->visible = 1;
		lst = lst->next;
	}
}

void		ft_sprite_save(t_all *all, int x, int y)
{
	t_sprite	*new_sprite;
	t_list		*new_elem;

	if (!(new_sprite = malloc(sizeof(t_sprite))))
		exit(0);
	new_sprite->x = (float)x + 0.5;
	new_sprite->y = (float)y + 0.5;
	new_sprite->visible = 0;
	new_elem = ft_lstnew(new_sprite);
	ft_lstadd_back(all->sprite, new_elem);
}

void		ft_check_sprite(char *str, t_all *all)
{
	int		j;
	int		i;

	i = 0;
	j = -1;
	while (str[++j])
		if (str[j] == '2')
		{
			ft_sprite_save(all, all->plan.current_line, j);
			i++;
		}
	if (j < 3)
	{
		printf("lalala\n");
		exit(0);
	}
	all->plan.current_line++;
}
