/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:41:29 by mingkang          #+#    #+#             */
/*   Updated: 2022/11/23 18:03:14 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1024
# endif

typedef struct s_fd_lst
{
	int				fd;
	char			*str;
	struct s_fd_lst	*next;
}t_fd_lst;

typedef struct s_node
{
	char			*str;
	struct s_node	*next;
}t_lnode;

typedef struct s_lnk_lst
{
	ssize_t	sum;
	t_lnode	head_node;
}t_lnk_lst;

void		ft_bzero(void *s, size_t n);
void		ft_lstclear(t_lnk_lst *lst);
int			ft_addlst(t_lnk_lst *lst, char *str, ssize_t str_len);
t_fd_lst	*find_fd(t_fd_lst **lst, int fd);
char		*ft_strdup(const char *s1, ssize_t len);
size_t		ft_strlen(const char *str);
ssize_t		ft_check(t_fd_lst *fl_dsc, t_lnk_lst *lst, char *str, ssize_t str_len);
ssize_t		read_buf(t_fd_lst *fl_dsc, t_lnk_lst *lst);
char		*ft_getstr(t_lnk_lst *lst);
char		*get_next_line(int fd);

#endif
