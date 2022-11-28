/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:54:37 by mingkang          #+#    #+#             */
/*   Updated: 2022/11/26 16:54:56 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

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
}t_lst;

char	*get_next_line(int fd);
char	*ft_strldup(const char *s1, size_t len);
size_t	ft_strlen(const char *str);
t_lst	*ft_init_lst(char **fd_arr);
ssize_t	ft_addlst(t_lst *lst, char *str, size_t str_len);
void	ft_lstclear(t_lst *lst);
ssize_t	ft_check(t_lst *lst, char *str, ssize_t str_len, int fd);
ssize_t	read_buf(t_lst *lst, int fd);
char	*ft_getstr(t_lst *lst, char **fd_str);

#endif
