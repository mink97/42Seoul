/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:41:29 by mingkang          #+#    #+#             */
/*   Updated: 2022/11/25 19:45:08 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1024
# endif
# ifndef OPEN_MAX
#  define OPEN_MAX 49152
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
char	*ft_strldup(const char *s1, ssize_t len);
size_t	ft_strlen(const char *str);
t_lst	*ft_init_lst(char **fd_arr);
ssize_t	ft_addlst(t_lst *lst, char *str, ssize_t str_len);
void	ft_lstclear(t_lst *lst);

#endif
