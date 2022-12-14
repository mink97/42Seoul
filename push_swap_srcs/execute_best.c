/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_best.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 12:51:11 by mingkang          #+#    #+#             */
/*   Updated: 2022/12/12 13:20:18 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	execute_rr(t_deque *deq_a, t_deque *deq_b, t_rotate best)
{
	while (best.left_rot != 0 && best.right_rot != 0)
	{
		rotate_both(deq_a, deq_b, rr);
		best.left_rot--;
		best.right_rot--;
	}
	while (best.left_rot != 0)
	{
		rotate(deq_a, ra);
		best.left_rot--;
	}
	while (best.right_rot != 0)
	{
		rotate(deq_b, rb);
		best.right_rot--;
	}
}

static void	execute_rrr(t_deque *deq_a, t_deque *deq_b, t_rotate best)
{
	while (best.left_rot != 0 && best.right_rot != 0)
	{
		rotate_both(deq_a, deq_b, rrr);
		best.left_rot++;
		best.right_rot++;
	}
	while (best.left_rot != 0)
	{
		rotate(deq_a, rra);
		best.left_rot++;
	}
	while (best.right_rot != 0)
	{
		rotate(deq_b, rrb);
		best.right_rot++;
	}
}

static void	execute_ra_rrb(t_deque *deq_a, t_deque *deq_b, t_rotate best)
{
	while (best.left_rot != 0)
	{
		rotate(deq_a, ra);
		best.left_rot--;
	}
	while (best.right_rot != 0)
	{
		rotate(deq_b, rrb);
		best.right_rot++;
	}
}

static void	execute_rra_rb(t_deque *deq_a, t_deque *deq_b, t_rotate best)
{
	while (best.left_rot != 0)
	{
		rotate(deq_a, rra);
		best.left_rot++;
	}
	while (best.right_rot != 0)
	{
		rotate(deq_b, rb);
		best.right_rot--;
	}
}

void	execute_best(t_deque *deq_a, t_deque *deq_b, t_rotate best)
{
	if (best.left_rot >= 0)
	{
		if (best.right_rot >= 0)
			execute_rr(deq_a, deq_b, best);
		else
			execute_ra_rrb(deq_a, deq_b, best);
	}
	else
	{
		if (best.right_rot >= 0)
			execute_rra_rb(deq_a, deq_b, best);
		else
			execute_rrr(deq_a, deq_b, best);
	}
	push(deq_b, deq_a, pa);
}
