/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:25:41 by mingkang          #+#    #+#             */
/*   Updated: 2022/12/10 11:00:22 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_deque *deq, int act)
{
	t_node	*tmp1;
	t_node	*tmp2;

	tmp1 = pop_front(deq);
	tmp2 = pop_front(deq);
	if (tmp1 == NULL || tmp2 == NULL)
		return ;
	push_front(deq, tmp1);
	push_front(deq, tmp2);
	if (act == sa)
		write(1, "sa\n", 3);
	else if (act == sb)
		write(1, "sb\n", 3);
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
	write(1, "ss\n", 3);
}

void	push(t_deque *src_deq, t_deque *dst_deq, int act)
{
	t_node	*tmp;

	tmp = pop_front(src_deq);
	if (tmp == NULL)
		return ;
	push_front(dst_deq, tmp);
	if (act == pa)
		write(1, "pa\n", 3);
	else if (act == pb)
		write(1, "pb\n", 3);
}

void	rotate(t_deque *deq, int act)
{
	t_node	*tmp;

	if (act == ra || act == rb)
	{
		tmp = pop_front(deq);
		push_rear(deq, tmp);
		if (act == ra)
			write(1, "ra\n", 3);
		else
			write(1, "rb\n", 3);
	}
	else if (act == rra || act == rrb)
	{
		tmp = pop_rear(deq);
		push_front(deq, tmp);
		if (act == rra)
			write(1, "rra\n", 4);
		else
			write(1, "rrb\n", 4);
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
		write(1, "rr\n", 3);
	}
	else if (act == rrr)
	{
		tmp = pop_rear(deq_a);
		push_front(deq_a, tmp);
		tmp = pop_rear(deq_b);
		push_front(deq_b, tmp);
		write(1, "rrr\n", 4);
	}
}
