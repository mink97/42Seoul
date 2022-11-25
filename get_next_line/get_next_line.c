/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 09:02:48 by mingkang          #+#    #+#             */
/*   Updated: 2022/11/25 16:48:09 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <limits.h>

char	*ft_strdup(const char *s1, ssize_t len)
{
	ssize_t	i;
	char	*newstr;

	newstr = (char *)malloc(sizeof(char) * (len + 1));
	if (newstr == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		newstr[i] = s1[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

size_t	ft_strlen(const char *str)
{
	size_t	cnt;

	if (str == 0)
		return (0);
	cnt = 0;
	while (str[cnt])
		cnt++;
	return (cnt);
}

void	ft_lstclear(t_lnk_lst *lst)
{
	t_lnode	*dummy;
	t_lnode	*tmp;

	if (lst == 0)
		return ;
	tmp = lst->head_node.next;
	while (tmp != 0)
	{
		dummy = tmp;
		tmp = tmp->next;
		free(dummy->str);
		free(dummy);
	}
	lst->head_node.next = 0;
}

ssize_t	ft_addlst(t_lnk_lst *lst, char *str, ssize_t str_len)
{
	t_lnode	*node;
	t_lnode	*new_node;
	char	*new_str;

	new_str = ft_strdup(str, str_len);
	if (new_str == 0)
		return (-1);
	new_node = malloc(sizeof(t_lnode));
	if (new_node == NULL)
	{
		free(new_str);
		return (-1);
	}
	new_node->str = new_str;
	new_node->next = 0;
	node = &(lst->head_node);
	while (node->next != 0)
		node = node->next;
	node->next = new_node;
	return (str_len);
}

ssize_t	ft_check(t_lnk_lst *lst, char *str, ssize_t str_len, int fd)
{
	ssize_t	i;
	ssize_t	check;

	i = 0;
	while (i < str_len && str[i++] != '\n')
		;
	lst->sum += i;
	check = ft_addlst(lst, str, str_len);
	if (check == -1)
		return (-1);
	if (str[i - 1] != '\n') // 개행을 만나지 못했을 때
	{
		check = read_buf(lst, fd);
		if (check == -1)
			return (-1);
	}
	return (i);
}

ssize_t	read_buf(t_lnk_lst *lst, int fd)
{
	char	*buf;
	// ssize_t	len;
	ssize_t	read_len;
	size_t	i;

	buf = malloc(sizeof(char) * (BUFFER_SIZE));
	if (buf == NULL)
		return (-1);
	i = 0;
	while (i < BUFFER_SIZE)
		buf[i++] = 0;
	read_len = read(fd, buf, BUFFER_SIZE);
	if (read_len > 0)
		read_len = ft_check(lst, buf, read_len, fd);
	// else if (read_len == 0)
	// 	len = (0);
	// else
	// 	len = (-1);
	free(buf);
	return (read_len);
}

char	*get_next_line(int fd)
{
	static char		*fd_arr[OPEN_MAX + 3];
	t_lnk_lst		*lst;
	char			*ret;
	ssize_t			len;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	lst = malloc(sizeof(t_lnk_lst));
	if (lst == 0)
	{
		if (fd_arr[fd] != 0)
		{
			free(fd_arr[fd]);
			fd_arr[fd] = NULL;
		}
		return (0);
	}
	lst->sum = 0;
	lst->head_node.next = 0;
	if (fd_arr[fd] != 0)
	{
		len = ft_check(lst, fd_arr[fd], ft_strlen(fd_arr[fd]), fd);
		free(fd_arr[fd]);
		fd_arr[fd] = NULL;
	}
	else
		len = read_buf(lst, fd);
	ret = 0;
	if (len > 0)
		ret = ft_getstr(lst, &fd_arr[fd]);
	ft_lstclear(lst);
	free(lst);
	return (ret);
}

char	*ft_getstr(t_lnk_lst *lst, char **fd_str)
{
	t_lnode	*node;
	char	*str;
	ssize_t	i;
	ssize_t	j;

	str = malloc(sizeof(char) * (lst->sum + 1));
	if (str == 0)
		return (0);
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
	// j = 0;
	// while ((node->str)[j] != 0 && i < lst->sum)
	// 	str[i++] = (node->str)[j++];
	if (i == lst->sum && node->str[j] != 0)
		*fd_str = ft_strdup(&(node->str)[j], ft_strlen(&(node->str)[j]));
	str[i] = 0;
	return (str);
}
