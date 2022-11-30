/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:54:05 by mingkang          #+#    #+#             */
/*   Updated: 2022/11/30 10:41:13 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/syslimits.h>
#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*fd_arr[OPEN_MAX];
	char		*ret;
	t_lst		*lst;
	ssize_t		len;
	char		*buf;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= OPEN_MAX)
		return (0);
	lst = ft_init_lst(fd_arr + fd);
	if (lst == NULL)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE));
	if (fd_arr[fd] != NULL)
		len = ft_check(lst, fd, &fd_arr[fd], buf);
	else
		len = read_buf(lst, fd, buf);
	free(buf);
	ret = 0;
	if (len > 0)
		ret = ft_getstr(lst, &fd_arr[fd]);
	ft_lstclear(lst);
	free(lst);
	return (ret);
}

ssize_t	ft_check(t_lst *lst, int fd, char **str, char *buf)
{
	ssize_t	i;
	ssize_t	check;
	ssize_t	str_len;

	i = 0;
	str_len = ft_strlen(*str);
	while (i < str_len && (*str)[i++] != '\n')
		;
	lst->sum += i;
	check = ft_addlst(lst, *str, str_len);
	if (check != -1 && (*str)[i - 1] != '\n')
		check = read_buf(lst, fd, buf);
	free(*str);
	*str = NULL;
	if (check == -1)
		return (-1);
	return (lst->sum);
}

ssize_t	read_buf(t_lst *lst, int fd, char *buf)
{
	ssize_t	read_len;
	ssize_t	check;
	ssize_t	i;

	if (buf == NULL)
		return (-1);
	read_len = read(fd, buf, BUFFER_SIZE);
	while (read_len > 0)
	{
		i = 0;
		while (i < read_len && buf[i++] != '\n')
			;
		lst->sum += i;
		check = ft_addlst(lst, buf, read_len);
		if (check == -1)
			return (-1);
		if (buf[i - 1] == '\n')
			break ;
		read_len = read(fd, buf, BUFFER_SIZE);
	}
	if (read_len < 0)
		return (-1);
	return (lst->sum);
}

char	*ft_getstr(t_lst *lst, char **fd_str)
{
	t_lnode	*node;
	char	*str;
	ssize_t	i;
	ssize_t	j;

	str = malloc(sizeof(char) * (lst->sum + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	node = (lst->head_node.next);
	while (1)
	{
		j = 0;
		while ((node->str)[j] != 0 && i < lst->sum)
			str[i++] = (node->str)[j++];
		if (node->next == 0)
			break ;
		node = (node->next);
	}
	if (i == lst->sum && node->str[j] != 0)
		*fd_str = ft_strldup(&(node->str)[j], ft_strlen(&(node->str)[j]));
	str[i] = 0;
	return (str);
}
