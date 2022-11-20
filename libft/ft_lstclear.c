/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:51:43 by mingkang          #+#    #+#             */
/*   Updated: 2022/11/11 14:11:17 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*dummy;
	t_list	*tmp;

	if (lst == 0 || del == 0)
		return ;
	tmp = *lst;
	while (tmp != 0)
	{
		dummy = tmp;
		tmp = tmp->next;
		ft_lstdelone(dummy, del);
	}
	*lst = 0;
}
