/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrance <frfrance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:51:23 by alesanto          #+#    #+#             */
/*   Updated: 2020/05/04 15:15:11 by frfrance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>

typedef struct			s_list
{
	void				*content;
	struct s_list		*next;
}						t_list;

char					*ft_strtrim(char const *str, char const *set);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
char					*ft_strmapi(char const *s,
							char (*f)(unsigned int, char));
int						ft_strlen(const char *str);
char					*ft_strjoin(char const *s1, char const *s2, int f);
char					*ft_strdup(char *src);
char					**ft_split(const char *str, char c);
int						ft_atoi(char *str);
char					*ft_itoa(int n);
char					*ft_itoa_base(long long int n, char *base);
void					ft_bzero(void *s, size_t n);
void					*ft_memset (void *b, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					*ft_memchr(const void *s, int c, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memccpy(void *dst,
							const void *src, int c, size_t n);
void					*ft_memmove(void *dst, const void *src, size_t n);
int						ft_isdigit(int c);
int						ft_isalpha(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_tolower(int c);
int						ft_toupper(int c);
char					*ft_strnstr(const char *s1, const char *s2, size_t n);
char					*ft_substr(char const *s,
							unsigned int start, size_t len);
void					*ft_memccpy(void *dest, const void *src,
							int c, size_t n);
void					ft_putchar_fd(char c, int fd);
int						ft_putstr_fd(char *str, int fd);
int						ft_putstr_t(char *s, int fd);
void					ft_putendl_fd(char *str, int fd);
void					ft_putnbr_fd(int n, int fd);
char					*ft_strrchr(const char *s, int c);
char					*ft_strchr(const char *s, int c);
t_list					*ft_lstnew(void *content);
void					ft_lstadd_front(t_list **alst, t_list *new);
int						ft_lstsize(t_list *lst);
t_list					*ft_lstlast(t_list *lst);
void					ft_lstadd_back(t_list **alst, t_list *new);
void					ft_lstdelone(t_list *lst, void (*del)(void *));
void					ft_lstclear(t_list **lst, void (*del)(void *));
void					ft_lstiter(t_list *lst,
							void (*f)(void *));
t_list					*ft_lstmap(t_list *lst,
							void *(*f)(void *), void (*del)(void *));
unsigned int			ft_strlcat(char *dest, const char *src, size_t size);
size_t					ft_strlcpy(char *dest, const char *src, size_t n);
void					*ft_calloc(size_t count, size_t size);
int						ft_find_c(char *str, char c);
int						ft_find_f(char c, char *str);
void					ft_space_i(char *str, int *i);
char					*ft_space_d(char *str);
char					*ft_skip_space(char *str);
int						ft_get_next_line(int fd, char **line);

typedef struct			s_struct
{
	int					t;
	int					o;
	int					prec;
	char				*tab;
	int					n;
	int					c;
	int					w;
	int					z;
}						t_struct;

# define VALID_FLAGS "cdi%xXups"
# define VALID_FLAGS_V2 "diuxXp"

# define BUFFER_SIZE 5000

int						ft_printf(const char *argff, ...);
int						ft_flag(char *str, t_struct *prsg);
int						ft_width(char *str, va_list *arg_ptr, t_struct *prsg);
int						ft_precision(char *str, va_list *arg_ptr,
							t_struct *prsg);
void					ft_string(char str, t_struct *prsg);
void					ft_prec_nb(t_struct *prsg);
void					ft_space_f(char str, t_struct *prsg);
void					ft_ex(char str, t_struct *prsg);
void					ft_systm(char str, t_struct *prsg);
char					*ft_strdup_f(char *str);
char					*ft_itoa_base_l(long long int n, char *base);
char					*ft_strdup_c(int c);
void					ft_zero_s(t_struct *p, char str);

typedef struct			s_ptrlst
{
	void				*ptr;
	void				(*fptr)(void *);
}						t_ptrlst;

void					*ft_add_ptr(void *ptr, t_list **lst,
							void (*fptr)(void *));
void					ft_print_add_lst(t_list **lst);
void					ft_del_ptr(t_list **lst, void *to_del);
void					join_elem(t_list **lst, t_list *last, t_list *current);
void					ft_free_ptrlst(t_list **lst);
void					ft_print_exit(char *msg);

#endif
