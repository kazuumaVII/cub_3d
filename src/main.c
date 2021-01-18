/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrance <frfrance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 16:19:30 by frfrance          #+#    #+#             */
/*   Updated: 2020/06/01 17:17:00 by frfrance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		ft_convert_tab(t_all *all, t_list *tab)
{
	int i;

	i = 0;
	if (!tab)
		ft_print_exit("\nError\nMap missing");
	if (!(all->prsg.t_m = ft_add_ptr(malloc(sizeof(char *) *
		(ft_lstsize(tab) + 1)), all->ptr_lst, &free)))
		exit(0);
	while (tab)
	{
		all->prsg.t_m[i] = ft_add_ptr(ft_strdup(tab->content),
		all->ptr_lst, &free);
		tab = tab->next;
		i++;
	}
	all->prsg.t_m[i] = NULL;
	ft_verif_map(all);
	if (all->curs.spwan != 1)
		ft_print_exit("\n\tError\nJoueur introuvable");
}

void		ft_file(int fd, t_all *all)
{
	char	*line;
	int		ret;
	t_list	**tab;

	if (!(tab = ft_calloc(sizeof(t_list *), 1)))
		exit(0);
	*tab = NULL;
	line = NULL;
	while ((ret = ft_get_next_line(fd, &line)) == 1)
	{
		if (ret == -1)
			exit(0);
		if (line)
		{
			ft_parsing(line, all, tab);
			free(line);
		}
	}
	if (line)
		free(line);
	ft_verif_resolution(all);
	ft_convert_tab(all, *tab);
	ft_print_cub_3d(all);
	ft_lstclear(tab, free);
	free(tab);
}

int			ft_op_all(char *file, t_all *all)
{
	int		fd;
	int		i;

	i = -1;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (0);
	if (!(all->ptr_lst = malloc(sizeof(t_list *) * 1)))
		return (0);
	*all->ptr_lst = NULL;
	if (!(all->sprite = ft_add_ptr(malloc(sizeof(t_list *) * 1),
		all->ptr_lst, &free)))
		exit(0);
	*all->sprite = NULL;
	ft_file(fd, all);
	while (all->prsg.t_m[++i])
		ft_check_sprite(all->prsg.t_m[i], all);
	close(fd);
	return (1);
}

int			main(int ac, char **av)
{
	t_all	all;

	ft_bzero(&all, sizeof(t_all));
	all.prsg.t_f = -1;
	all.prsg.t_c = -1;
	all.prsg.verif_r = 0;
	if (ac == 1)
	{
		ft_printf("\nError\nAucune map\n");
		return (0);
	}
	ft_flag_map(av[1]);
	if (av[2])
		ft_flag_bmp(av[2]);
	if (!(ft_op_all(av[1], &all)))
		return (0);
	if (ac == 2)
		ft_open_w(&all);
	else if (ac == 3)
	{
		ft_printf("\nCreation image bmp...\n");
		ft_bmp_center(&all);
	}

	return (0);
}
