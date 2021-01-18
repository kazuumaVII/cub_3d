/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrance <frfrance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 17:32:56 by frfrance          #+#    #+#             */
/*   Updated: 2020/06/01 11:22:49 by frfrance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define SPEED 0.05

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include "mlx.h"

typedef struct		s_parsing
{
	int				x_r;
	int				y_r;
	char			**t_m;
	unsigned int	t_f;
	unsigned int	t_c;
	int				sky;
	int				ground;
	int				j;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	int				none_color;
	int				verif_f;
	int				verif_c;
	int				verif_r;
}					t_prsg;

typedef struct		s_mlx
{
	void			*m_i;
	void			*m_w;
	int				*img;
	int				*sword;
	char			*mapp;

}					t_mlx;

typedef struct		s_image
{
	char			*name;
	void			*image;
	int				*mapping;
	int				h;
	int				w;
}					t_img;

typedef struct		s_texture
{
	t_img			t_no;
	t_img			t_so;
	t_img			t_we;
	t_img			t_ea;
	t_img			t_s;
}					t_text;

typedef struct		s_camera
{
	float			po_x;
	float			po_y;
	float			cam_x;
	float			plan_x;
	float			plan_y;
	float			ray_po_x;
	float			ray_po_y;
	float			ray_dir_x;
	float			ray_dir_y;
	float			dta_dist_x;
	float			dta_dist_y;
	float			step_x;
	float			step_y;
	float			side_dist_x;
	float			side_dist_y;
	int				map_x;
	int				map_y;
	int				hit;
	int				side;
	float			haut_lign;
	int				draw_start;
	int				draw_end;
	float			wall_x;
	float			perp_wall_dis;
	unsigned int	color;
	float			text_x;
	float			text_y;
}					t_cam;

typedef struct		s_curseur
{
	int				spwan;
	float			di_x;
	float			di_y;
	char			pop;
	float			po_x;
	float			po_y;
	int				ori_x;
	int				ori_y;
	float			mv_speed;
	float			mv_speed_r;
}					t_curs;

typedef struct		s_move
{
	int				go;
	int				back;
	int				left;
	int				right;
	int				left_q;
	int				right_e;
}					t_mv;

typedef struct		s_hud
{
	float			lb_start_x;
	float			lb_start_y;
	float			lb_end_x;
	float			lb_end_y;
	float			lb_w;
	float			lb_h;
	float			lb_x;
	float			lb_y;
	float			now;
	int				pdv;
	int				pdv_r;
}					t_hud;

typedef struct		s_sprite
{
	float			x;
	float			y;
	float			dist;
	int				visible;
	float			s_x;
	float			s_y;
	float			inv_det;
	float			trans_x;
	float			trans_y;
	int				screen_x;
	int				h;
	int				w;
	int				draw_start_x;
	int				draw_start_y;
	int				draw_end_x;
	int				draw_end_y;
	float			tex_x;
	float			tex_y;
	float			wall_x;
	int				stripe;
	int				pix;
	unsigned int	color;
}					t_sprite;

typedef struct		s_plan
{
	char			**plan;
	int				current_line;
}					t_plan;

typedef struct		s_all_structure
{
	t_prsg			prsg;
	t_mlx			mlx;
	t_cam			cam;
	t_curs			curs;
	t_mv			mv;
	t_text			text;
	t_img			img;
	t_hud			hud;
	t_list			**sprite;
	t_list			**ptr_lst;
	t_plan			plan;
}					t_all;

void				ft_repop(char *str, t_all *all, int i);

int					ft_center_prsg(char *str, t_all *all);
void				ft_recup_text_prsg(t_all *all, t_img *text, char *str);
unsigned int		ft_conver_color(char *str);
int					ft_check_res(t_all *all, char *str, t_prsg *prsg);
void				ft_parsing(char *str, t_all *all, t_list **tab);
int					ft_str_to_tab(char *str, t_list **tab);
char				*ft_not_skip_space(char *str);

void				ft_verif_map(t_all *all);
void				ft_convert_tab(t_all *all, t_list *tab);
void				ft_pos_r(t_all *all);

int					ft_open_w(t_all *all);
int					ft_close_win(t_all *all);
void				ft_destroy_win(t_all *all, int option);

void				ft_raycasting(t_all *all);
void				ft_ray_center(t_all *all, float buff[all->prsg.x_r], int x);

void				ft_init_val(t_all *all, int x);
void				ft_vector_r(t_all *all);
void				ft_hit_ray(t_all *all);
void				ft_draw_start(t_all *all);
void				ft_text_wall(t_all *all);
void				ft_ground_a_sky(t_all *all, int x);
void				ft_put_pixel_j(t_all *all, int x, int y,
					unsigned int color);

int					ft_push_key(int k, t_all *all);
int					ft_k_release(int k, t_all *all);
int					ft_key_center(t_all *all);

void				ft_forward(t_all *all, t_curs *curs);
void				ft_back(t_all *all, t_curs *curs);
void				ft_left(t_all *all, t_curs *curs);
void				ft_right(t_all *all, t_curs *curs);
void				ft_rot_left(t_all *all, t_curs *curs);
void				ft_rot_right(t_all *all, t_curs *curs);

void				ft_texture(t_all *all);
void				ft_color_center(t_all *all);
void				ft_sprite_color(t_all *all, t_img *text, t_sprite *sprite);

void				ft_print_cub_3d(t_all *all);

void				ft_sprite_center(t_all *all, float buffer[all->prsg.x_r]);
void				ft_calcul_sprite_dist(t_all *all);
void				ft_sort_sprite(t_all *all);

void				ft_init_sprite(t_all *all, t_sprite *sprite);
void				ft_draws_sprite(t_all *all, t_sprite *sprite,
					float buff[all->prsg.x_r]);
void				ft_sprite_save(t_all *all, int x, int y);
void				ft_sprite_complete(t_all *all);
void				ft_check_sprite(char *str, t_all *all);

void				ft_life_or_dead(t_all *all);
void				ft_barre_life(t_all *all, t_hud *hud);

void				ft_verif_resolution(t_all *all);
int					ft_check_prsg(t_all *all, char *str);
void				parsing(char *str, t_all *all, t_list **tab);
int					ft_check_color(char *tmp);
void				ft_verif_color(char *str);

void				ft_bmp_center(t_all *all);
void				ft_flag_bmp(char *str);
void				ft_flag_map(char *str);
void				ft_flag_xpm(char *str);
void				ft_res_bmp(int *res);

#endif
