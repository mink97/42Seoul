/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 09:02:48 by mingkang          #+#    #+#             */
/*   Updated: 2022/11/23 20:03:30 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <limits.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
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

int	ft_addlst(t_lnk_lst *lst, char *str, ssize_t str_len)
{
	t_lnode	*node;
	t_lnode	*new_node;
	char	*new_str;

	if (lst == 0)
		return (-1);
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
	lst->sum += str_len;
	return (1);
}

t_fd_lst	*find_fd(t_fd_lst **lst, int fd)
{
	t_fd_lst	*tmp;
	t_fd_lst	*cur;

	cur = *lst;
	if (cur != 0)
	{
		while (cur->next != 0 && cur->fd != fd)
			cur = cur->next;
		if (cur->fd == fd)
			return (cur);
	}
	tmp = (t_fd_lst *)malloc(sizeof(t_fd_lst));
	if (tmp == 0)
		return (0);
	tmp->fd = fd;
	tmp->str = 0;
	tmp->next = NULL;
	if (*lst == NULL)
		*lst = tmp;
	else
		cur->next = tmp;
	return (tmp);
}

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

ssize_t	ft_check(t_fd_lst *fl_dsc, t_lnk_lst *lst, char *str, ssize_t str_len)
{
	ssize_t	i;
	char	*post;
	int		check;

	// printf("check_str : %s\n", str);
	i = 0;
	while (i < str_len && str[i] != '\n') // str == NULL일 경우는?
		i++;
	if (i < str_len)
		i++;
	check = ft_addlst(lst, str, i);
	if (check == -1)
	{
		free(fl_dsc->str);
		return (-1);
	}
	if (i < str_len - 1) // 중간에 '\n'이 있는 경우. 뒷 부분
	{
		post = ft_strdup(str + i, str_len - i);
		if (post == NULL) // free(fl_dsc->str) 안해줘도 될려나>?
		{
			free(fl_dsc->str);
			return (-1);
		}
	}
	else
		post = NULL;
	free(fl_dsc->str);
	fl_dsc->str = post;
	return (i);
}

ssize_t	read_buf(t_fd_lst *fl_dsc, t_lnk_lst *lst, ssize_t *read_len)
{
	char	*buf;
	ssize_t	len;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (-1);
	ft_bzero(buf, BUFFER_SIZE + 1);
	*read_len = read(fl_dsc->fd, buf, BUFFER_SIZE);
	len = 0;
	while (*read_len > 0)
	{
		len = ft_check(fl_dsc, lst, buf, *read_len);
		if (len == -1)
		{
			free(buf);
			return (-1);
		}
		if (len != *read_len || *read_len < BUFFER_SIZE)
			break ;
		*read_len = read(fl_dsc->fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (len);
}

char	*ft_getstr(t_lnk_lst *lst)
{
	t_lnode	*node;
	char	*str;
	ssize_t	i;
	ssize_t	j;

	str = malloc(sizeof(char) * (lst->sum + 1));
	if (str == 0)
		return (0);
	i = 0;
	node = lst->head_node.next;
	while (node != 0)
	{
		j = 0;
		while (node->str[j] != 0)
			str[i++] = node->str[j++];
		node = node->next;
	}
	str[i] = 0;
	ft_lstclear(lst);
	return (str);
}

char	*get_next_line(int fd)
{
	static char		*fd_arr[OPEN_MAX + 3];
	static t_fd_lst	*fd_lst;
	t_fd_lst		*fl_dsc;
	t_lnk_lst		*lst;
	char			*ret;
	ssize_t			tmp_len;
	ssize_t			len;
	ssize_t			read_len;

	// fl_dsc = find_fd(&fd_lst, fd);
	// if (fl_dsc == 0)
	// 	return (0);
	//함수 하나로 만들어야 할 듯(init)
	lst = malloc(sizeof(t_lnk_lst));
	if (lst == 0)
		return (0);
	lst->sum = 0;
	lst->head_node.next = 0;
	if (fd_arr[fd] != 0)
	{
		tmp_len = ft_strlen(fd_arr[fd]);
		len = ft_check(fd_arr[fd], lst, fd_arr[fd], tmp_len);
		if (len == tmp_len) // 개행 없을 때*
			read_buf(fl_dsc, lst, &read_len); // 개행 올 때 까지 버퍼 읽기
	}
	else
		len = read_buf(fl_dsc, lst, &read_len);
	ret = 0;
	if (len > 0)
		ret = ft_getstr(lst); // str 합치는 함수
	ft_lstclear(lst);
	free(lst);
	return (ret);
}
