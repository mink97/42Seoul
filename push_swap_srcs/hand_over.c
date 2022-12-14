/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hand_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 10:35:58 by mingkang          #+#    #+#             */
/*   Updated: 2022/12/12 13:07:10 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handover_a_to_b(t_deque *deq_a, t_deque *deq_b)
{
	int const	pivot_a = (deq_a->cnt) / 3;
	int const	pivot_b = (deq_a->cnt) * 2 / 3;
	int			cnt;

	cnt = deq_a->cnt;
	if (cnt <= 5)
	{
		hard_coding(deq_a, deq_b);
		exit(EXIT_SUCCESS);
	}
	while (cnt-- > 0)
	{
		if (deq_a->head->data > pivot_b)
			rotate(deq_a, ra);
		else if (deq_a->head->data > pivot_a)
			push(deq_a, deq_b, pb);
		else
		{
			push(deq_a, deq_b, pb);
			rotate(deq_b, rb);
		}
	}
	while (deq_a->cnt > 3)
		push(deq_a, deq_b, pb);
	hard_coding(deq_a, deq_b);
}

void	handover_b_to_a(t_deque *deq_b, t_deque *deq_a)
{
	t_rotate	best;

	while (deq_b->cnt != 0)
	{
		best = find_best_case(deq_a, deq_b);
		execute_best(deq_a, deq_b, best);
	}
	swap_group(deq_a);
}
