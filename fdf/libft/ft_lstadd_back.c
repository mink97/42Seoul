/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:23:46 by mingkang          #+#    #+#             */
/*   Updated: 2022/11/11 10:34:13 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp_node;

	if (new == 0 || lst == 0)
		return ;
	if (*lst == 0)
		*lst = new;
	else
	{
		tmp_node = ft_lstlast(*lst);
		tmp_node->next = new;
	}
}
