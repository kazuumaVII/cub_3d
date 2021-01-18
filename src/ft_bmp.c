/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrance <frfrance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:17:47 by frfrance          #+#    #+#             */
/*   Updated: 2020/05/04 20:50:31 by frfrance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_bits_mv(unsigned char *str, int i)
{
	str[0] = (unsigned char)(i);
	str[1] = (unsigned char)(i >> 8);
	str[2] = (unsigned char)(i >> 16);
	str[3] = (unsigned char)(i >> 24);
}

void	ft_header(t_all *all, int fd)
{
	unsigned char	f_header[14];
	int				size;

	size = 3 * (all->prsg.x_r * all->prsg.y_r);
	ft_memset(&f_header, 0, 14);
	f_header[0] = 'B';
	f_header[1] = 'M';
	ft_bits_mv(&f_header[2], size + 54);
	f_header[10] = 54;
	write(fd, f_header, 14);
}

void	ft_header_img(t_all *all, int fd)
{
	unsigned char	img_header[40];

	ft_memset(&img_header, 0, 40);
	img_header[0] = 40;
	ft_bits_mv(&img_header[4], all->prsg.x_r);
	ft_bits_mv(&img_header[8], all->prsg.y_r);
	img_header[12] = 1;
	img_header[14] = 24;
	img_header[20] = 3 * (all->prsg.x_r * all->prsg.y_r);
	write(fd, img_header, 40);
}

void	ft_file_to_bmp(t_all *all, int fd)
{
	int					j;
	int					i;
	int					color;
	int					(*array)[all->prsg.x_r][1];
	unsigned char		pad[3];

	array = (void *)all->mlx.mapp;
	ft_memset(&pad, 0, 3);
	j = all->prsg.y_r;
	while (--j >= 0)
	{
		i = -1;
		while (++i < all->prsg.x_r)
		{
			color = *array[j][i];
			write(fd, &color, 3);
		}
		i = -1;
		while (++i < (4 - (all->prsg.x_r * 3) % 4) % 4)
			write(fd, &pad, 3);
	}
}

void	ft_bmp_center(t_all *all)
{
	int fd;

	all->mlx.m_i = mlx_init();
	ft_color_center(all);
	ft_raycasting(all);
	if ((fd = open("img.bmp", O_RDWR | O_CREAT, S_IRWXU)) == -1)
		ft_print_exit("\n\tError\nMauvais argument");
	ft_header(all, fd);
	ft_header_img(all, fd);
	ft_file_to_bmp(all, fd);
	ft_close_win(all);
	close(fd);
}
