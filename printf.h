/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:02:44 by bjasper           #+#    #+#             */
/*   Updated: 2019/12/19 15:42:31 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <inttypes.h>
# include <limits.h>

typedef struct  s_struct
{
    int plus; //f
    int minus; //f
    int space; //f
    int sharp; //f
    int zero; //f
    int width; // ширина
    int widthisneg; // ширина отрицательная
    int precision; // точность
    int h;
    int hh;
    int l;
    int ll;
    int value_is_neg;
    int dack_prec; //если стоит точка без числа т.е. если не указана точность
}   t_struct;

typedef struct		s_list
{
	char			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_putstr(char *str);
void				ft_putnbr(intmax_t nb);
void				ft_putchar(char c);
size_t				ft_strlen(const char *s);
char				*ft_strncpy(char *dst, const char *src, size_t len);
void				ft_striter(char *s, void (*f)(char *));
char				*ft_strmap(char const *s, char (*f)(char));
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memset(void *b, int c, size_t len);
int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_isalpha(int c);
void				*ft_memchr(const void *s, int c, size_t n);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				*ft_memalloc(size_t size);
int					ft_isalnum(int c);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_isprint(int c);
int					ft_isascii(int c);
char				*ft_itoa(intmax_t n);
char				*ft_strnew(size_t size);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_strdel(char **as);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_strclr(char *s);
size_t				ft_nbrlen(intmax_t n);

#endif
