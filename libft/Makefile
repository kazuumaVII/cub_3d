# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frfrance <frfrance@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/16 14:42:52 by alesanto          #+#    #+#              #
#    Updated: 2020/03/07 13:23:47 by frfrance         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c ft_isalpha.c ft_bzero.c ft_isascii.c ft_isalnum.c ft_isdigit.c ft_calloc.c ft_isprint.c ft_itoa.c ft_memccpy.c \
	ft_memchr.c ft_memcpy.c  ft_memcmp.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c  ft_putstr_fd.c   ft_strchr.c \
	ft_putnbr_fd.c ft_strlcat.c ft_strdup.c ft_strdup_c.c ft_strjoin.c ft_strlen.c ft_strncmp.c  ft_split.c ft_strrchr.c ft_substr.c \
	ft_strlcpy.c ft_toupper.c ft_tolower.c ft_strtrim.c ft_strmapi.c ft_strnstr.c ft_memmove.c ft_lstadd_back.c ft_lstadd_front.c \
	ft_lstdelone.c ft_lstiter.c ft_lstclear.c ft_lstlast.c ft_lstnew.c ft_lstsize.c ft_lstmap.c ft_find_c.c ft_get_next_line.c \
	ft_putstr_t.c ft_itoa_base.c ft_itoa_b_l.c ft_space_i.c ft_space_d.c ft_skip_space.c ft_ptr_lsr_th.c ft_print_exit.c\
	./ft_printf/ft_args.c ./ft_printf/ft_printf.c ./ft_printf/ft_systeme.c ./ft_printf/ft_utile.c

OBJS = $(SRCS:.c=.o)
INCLUDES = ./libft.h
CFLAGS = -Wall -Wextra -Werror
LOGFILE=$(LOGPATH) `date +'%y.%m.%d %H:%M:%S'`

all: ${NAME}

.c.o : $(SRCS)
	@(gcc -c $(CFLAGS) -I $(INCLUDES) $^ -o $(^:.c=.o))

$(NAME): $(OBJS)

	@(ar rc $(NAME) $(OBJS) $^)
	@(ranlib $(NAME))
	make clean

clean:
	@(rm -rf $(OBJS))

fclean:	clean
	@(rm -rf $(NAME))

re:	fclean all

.PHONY:	all clean fclean re
