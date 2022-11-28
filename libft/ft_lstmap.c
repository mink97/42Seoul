/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:29:22 by mingkang          #+#    #+#             */
/*   Updated: 2022/11/22 11:01:38 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*tmp;
	void	*cont;

	head = 0;
	if (lst == 0 || f == 0 || del == 0)
		return (0);
	while (lst != 0)
	{
		cont = f(lst->content);
		tmp = ft_lstnew(cont);
		if (!tmp || !cont)
		{
			if (!tmp)
				del(cont);
			else
				free(tmp);
			ft_lstclear(&head, del);
			return (0);
		}
		ft_lstadd_back(&head, tmp);
		lst = lst->next;
	}
	return (head);
}
