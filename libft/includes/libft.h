/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:36:11 by mingkang          #+#    #+#             */
/*   Updated: 2022/12/24 15:08:53 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1024
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 10240
# endif

typedef struct s_node
{
	char			*str;
	struct s_node	*next;
}t_lnode;

typedef struct s_lst
{
	ssize_t	sum;
	t_lnode	head_node;
	t_lnode	*tail_node;
}t_lst;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}t_list;

void	free_strs(void *var);
int		ft_atoi(const char *str);
int		ft_atoi_base(char *str, char *base, int base_n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalpha(int i);
int		ft_isalnum(int i);
int		ft_isascii(int i);
int		ft_isdigit(int i);
int		ft_isprint(int i);
void	ft_bzero(void *s, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strdup(const char *s1);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
size_t	word_cnt(char *str, char c);

/*
** get_next_line
*/
char	*get_next_line(int fd);
char	*ft_strldup(const char *s1, size_t len);
t_lst	*ft_init_lst(char **fd_arr);
ssize_t	ft_addlst(t_lst *lst, char *str, size_t str_len);
ssize_t	ft_check(t_lst *lst, int fd, char **str, char *buf);
ssize_t	read_buf(t_lst *lst, int fd, char *buf);
char	*ft_getstr(t_lst *lst, char **fd_str);

#endif
