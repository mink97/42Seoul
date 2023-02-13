/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:33:27 by mingkang          #+#    #+#             */
/*   Updated: 2023/01/10 19:04:45 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
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

char		*get_next_line(int fd);
char		*ft_strldup(const char *s1, size_t len);
t_lst		*ft_init_lst(char **fd_arr);
ssize_t		ft_addlst(t_lst *lst, char *str, size_t str_len);
ssize_t		ft_check(t_lst *lst, int fd, char **str, char *buf);
ssize_t		read_buf(t_lst *lst, int fd, char *buf);
char		*ft_getstr(t_lst *lst, char **fd_str);
void		free_strs(void *var);

#endif
