# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frfrance <frfrance@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/27 14:26:34 by frfrance          #+#    #+#              #
#    Updated: 2020/05/04 21:18:45 by frfrance         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D

SRCS = src/ft_bmp.c src/ft_check_flag.c src/ft_draws.c \
		src/ft_hud.c src/ft_key.c src/ft_map.c \
 		src/ft_move.c src/ft_mv_rot.c src/ft_print.c \
 		src/ft_prsg.c src/ft_r_center.c src/ft_ray_calcul.c \
		src/ft_s_center.c src/ft_sprite.c src/ft_texture.c \
		src/ft_window.c src/ft_prsg_u.c src/ft_utile.c \
		src/main.c

INCLUDES = ./includes/cub3d.h
LIB = libft/libft.a

CFLAGS =  -Wall -Wextra -Werror
MLX = -L ./includes/ -lmlx -framework OpenGL -framework Appkit

all : $(NAME)

$(NAME) : $(OBJS)
	@(make -C libft)
	@(gcc $(MLX) $(CFLAGS) $(SRCS) $(LIB) -o $(NAME))

clean :
	@(rm -f $(OBJS))
	@(make clean -C libft)

cleanlib :
	@(make fclean -C libft)

fclean : cleanlib clean
	@(rm -rf $(NAME))
	@(rm -f libft.a)
	@(rm -rf a.out.dSYM)
	@(rm -f a.out)

re : fclean all
