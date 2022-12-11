/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 15:14:32 by mingkang          #+#    #+#             */
/*   Updated: 2022/12/11 17:30:42 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

	// if (deq->cnt == 2 && deq->head->data > deq->head->tail)
	// {
	// 	swap(deq, ra);
	// 	return ;
	// }

void	sort_3(t_deque *deq)
{
	int const	first = deq->head->data;
	int const	sec = deq->head->next->data;
	int const	last = deq->tail->data;

	if (first < sec && sec < last)
		return ;
	if (first < sec)
	{
		rotate(deq, rra);
		if (last > first)
			swap(deq, sa);
	}
	else
	{
		if (first > last)
			rotate(deq, ra);
		if (deq->head->data > deq->head->next->data)
			swap(deq, sa);
	}
}

int	get_min_idx(t_deque *deq)
{
	t_node	*tmp;
	int		idx;
	int		min_value;
	int		min_idx;

	tmp = deq->head;
	idx = 0;
	while (tmp != NULL)
	{
		if (idx == 0 || tmp->data < min_value)
		{
			min_idx = idx;
			min_value = tmp->data;
		}
		tmp = tmp->next;
		idx++;
	}
	return (min_idx);
}

void	sort_4(t_deque *deq_a, t_deque *deq_b)
{
	int		min_idx;

	min_idx = get_min_idx(deq_a);
	if (min_idx == 1)
		rotate(deq_a, ra);
	else if (min_idx == 2)
	{
		rotate(deq_a, ra);
		rotate(deq_a, ra);
	}
	else if (min_idx == 3)
		rotate(deq_a, rra);
	push(deq_a, deq_b, pb);
	sort_3(deq_a);
	push(deq_b, deq_a, pa);
}

void	sort_5(t_deque *deq_a, t_deque *deq_b)
{
	int		min_idx;

	min_idx = get_min_idx(deq_a);
	if (min_idx <= 2)
	{
		while (min_idx-- != 0)
			rotate(deq_a, ra);
	}
	else
	{
		while (min_idx++ != 5)
			rotate(deq_a, rra);
	}
	push(deq_a, deq_b, pb);
	sort_4(deq_a, deq_b);
	push(deq_b, deq_a, pa);
}

void	hard_coding(t_deque *deq_a, t_deque *deq_b)
{
	if (deq_a->cnt == 2)
		swap(deq_a, sa);
	else if (deq_a->cnt == 3)
		sort_3(deq_a);
	else if (deq_a->cnt == 4)
		sort_4(deq_a, deq_b);
	else
		sort_5(deq_a, deq_b);
}

