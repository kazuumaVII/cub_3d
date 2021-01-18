/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prsg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrance <frfrance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 17:41:00 by frfrance          #+#    #+#             */
/*   Updated: 2020/05/04 21:11:19 by frfrance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			ft_resolution(char *str, t_all *all)
{
	int i;

	all->prsg.verif_c = 0;
	all->prsg.verif_f = 0;
	if (all->prsg.verif_r != 0)
		ft_print_exit("\nError\nResolution deja existante");
	i = 0;
	ft_space_i(str, &i);
	i++;
	all->prsg.x_r = ft_atoi(&str[i]);
	ft_space_i(str, &i);
	while (ft_isdigit(str[i]))
		i++;
	all->prsg.y_r = ft_atoi(&str[i]);
	ft_space_i(str, &i);
	while (ft_isdigit(str[i]))
		i++;
	if (ft_atoi(&str[i]))
		ft_print_exit("\n\tError\nResolution");
	all->prsg.verif_r++;
}

unsigned int	ft_conver_color(char *str)
{
	int				i;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	ft_verif_color(str);
	i = 0;
	r = ft_atoi(&str[i]);
	while (ft_isdigit(str[i]) || str[i] == ' ')
		i++;
	g = ft_atoi(str + i + 1);
	i++;
	while (ft_isdigit(str[i]) || str[i] == ' ')
		i++;
	b = ft_atoi(str + i + 1);
	if (r > 255 || g > 255 || b > 255 || r < 0 || g < 0 || b < 0)
		ft_print_exit("\nError\nCouleur non valide");
	r = (int)pow(256, 2) * r;
	g = 256 * g;
	return (r + g + b);
}

void			ft_recup_text_prsg(t_all *all, t_img *text, char *str)
{
	char *tmp;

	tmp = ft_skip_space(str);
	if (text->name)
		ft_print_exit("\n\tError\nTexture deja utilise");
	text->name = ft_add_ptr(tmp, all->ptr_lst, &free);
	all = NULL;
}

int				ft_center_prsg(char *str, t_all *all)
{
	int error;

	error = 0;
	if (ft_strnstr(str, "R", ft_strlen(str)))
		ft_resolution(str, all);
	else if (str[0] == 'N' && str[1] == 'O')
		ft_recup_text_prsg(all, &all->text.t_no, str + 2);
	else if (str[0] == 'S' && str[1] == 'O')
		ft_recup_text_prsg(all, &all->text.t_so, str + 2);
	else if (str[0] == 'W' && str[1] == 'E')
		ft_recup_text_prsg(all, &all->text.t_we, str + 2);
	else if (str[0] == 'E' && str[1] == 'A')
		ft_recup_text_prsg(all, &all->text.t_ea, str + 2);
	else if (str[0] == 'S' && str[1] != 'O')
		ft_recup_text_prsg(all, &all->text.t_s, str + 1);
	else
	{
		if ((error = ft_check_res(all, str, &all->prsg)) == -1)
			ft_print_exit("\nError\nParsing");
		return (error);
	}
	return (1);
}
