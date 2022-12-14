/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:38:23 by mingkang          #+#    #+#             */
/*   Updated: 2022/12/13 19:51:51 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	swap(t_deque *deq)
{
	t_node	*tmp1;
	t_node	*tmp2;

	tmp1 = pop_front(deq);
	tmp2 = pop_front(deq);
	if (tmp1 == NULL || tmp2 == NULL)
		return ;
	push_front(deq, tmp1);
	push_front(deq, tmp2);
}

void	swap_both(t_deque *deq_a, t_deque *deq_b)
{
	t_node	*tmp1;
	t_node	*tmp2;

	tmp1 = pop_front(deq_a);
	tmp2 = pop_front(deq_a);
	if (tmp1 == NULL || tmp2 == NULL)
		return ;
	push_front(deq_a, tmp1);
	push_front(deq_a, tmp2);
	tmp1 = pop_front(deq_b);
	tmp2 = pop_front(deq_b);
	if (tmp1 == NULL || tmp2 == NULL)
		return ;
	push_front(deq_b, tmp1);
	push_front(deq_b, tmp2);
}

void	push(t_deque *src_deq, t_deque *dst_deq)
{
	t_node	*tmp;

	tmp = pop_front(src_deq);
	if (tmp == NULL)
		return ;
	push_front(dst_deq, tmp);
}

void	rotate(t_deque *deq, int act)
{
	t_node	*tmp;

	if (act == ra || act == rb)
	{
		tmp = pop_front(deq);
		push_rear(deq, tmp);
	}
	else if (act == rra || act == rrb)
	{
		tmp = pop_rear(deq);
		push_front(deq, tmp);
	}
}

void	rotate_both(t_deque *deq_a, t_deque *deq_b, int act)
{
	t_node	*tmp;

	if (act == rr)
	{
		tmp = pop_front(deq_a);
		push_rear(deq_a, tmp);
		tmp = pop_front(deq_b);
		push_rear(deq_b, tmp);
	}
	else if (act == rrr)
	{
		tmp = pop_rear(deq_a);
		push_front(deq_a, tmp);
		tmp = pop_rear(deq_b);
		push_front(deq_b, tmp);
	}
}
