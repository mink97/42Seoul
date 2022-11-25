/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:12:51 by mingkang          #+#    #+#             */
/*   Updated: 2022/11/25 19:45:04 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	cnt;

	cnt = 0;
	while (str[cnt])
		cnt++;
	return (cnt);
}

char	*ft_strldup(const char *s1, ssize_t len)
{
	ssize_t	i;
	char	*newstr;

	newstr = (char *)malloc(sizeof(char) * (len + 1));
	if (newstr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		newstr[i] = s1[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

t_lst	*ft_init_lst(char **fd_arr)
{
	t_lst	*lst;

	lst = malloc(sizeof(t_lst));
	if (lst == NULL)
	{
		if (*fd_arr != 0)
		{
			free(*fd_arr);
			*fd_arr = NULL;
		}
		return (NULL);
	}
	lst->sum = 0;
	lst->head_node.next = NULL;
	return (lst);
}

ssize_t	ft_addlst(t_lst *lst, char *str, ssize_t str_len)
{
	t_lnode	*node;
	t_lnode	*new_node;
	char	*new_str;

	new_str = ft_strldup(str, str_len);
	if (new_str == NULL)
		return (-1);
	new_node = malloc(sizeof(t_lnode));
	if (new_node == NULL)
	{
		free(new_str);
		return (-1);
	}
	new_node->str = new_str;
	new_node->next = NULL;
	node = &(lst->head_node);
	while (node->next != NULL)
		node = node->next;
	node->next = new_node;
	return (str_len);
}

void	ft_lstclear(t_lst *lst)
{
	t_lnode	*dummy;
	t_lnode	*tmp;

	if (lst == NULL)
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
