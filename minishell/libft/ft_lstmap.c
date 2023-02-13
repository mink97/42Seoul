/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbok <jbok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:50:01 by jbok              #+#    #+#             */
/*   Updated: 2022/11/10 16:21:50 by jbok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lst_error(t_list **head, void (*del)(void *))
{
	ft_lstclear(head, del);
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*new_list;
	void	*content;

	if (!f || !del)
		return (0);
	new_list = 0;
	while (lst)
	{
		content = f(lst->content);
		if (!content)
			return (ft_lst_error(&new_list, del));
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			del(content);
			return (ft_lst_error(&new_list, del));
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
