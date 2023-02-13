/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbok <jbok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:10:17 by jbok              #+#    #+#             */
/*   Updated: 2023/02/05 13:21:06 by jbok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include "get_next_line.h"
# include <stdint.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

//part1
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
size_t		ft_strlen(const char *s);
void		ft_bzero(void *s, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t n);
void		*ft_memset(void *dst, int c, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
size_t		ft_strlcpy(char *dst, char *src, size_t size);
size_t		ft_strlcat(char *dst, char *src, size_t size);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(char *src);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_atoi(const char *c);
void		*ft_calloc(size_t count, size_t size);
void		*ft_realloc(void *src, size_t src_size, size_t dst_size);
//part2
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(const char *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char s, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

char		*ft_uitoa(unsigned int n);
size_t		ft_intlen(int n);
size_t		ft_uintlen(unsigned int n);
int			ft_abs(int n);
//bonus
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		*ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//ft_printf
int			ft_printf(const char *str, ...);

void		*malloc_check(size_t size);
void		dup2_check(int int1, int int2);
int			dup_check(int fd);

#endif
