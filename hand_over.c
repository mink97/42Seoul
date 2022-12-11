/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hand_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 10:35:58 by mingkang          #+#    #+#             */
/*   Updated: 2022/12/11 16:51:59 by mingkang         ###   ########.fr       */
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
		// show_deque(deq_a);
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
	sort_3(deq_a);
}

int	get_left_rot(t_deque *deq_a, int value)
{
	int		left_rot;
	t_node	*tmp;

	left_rot = 1;
	tmp = deq_a->head;
	if (tmp == NULL)
		return (0);
	while (tmp->next != NULL)
	{
		if ((tmp->data > tmp->next->data && \
			(tmp->data < value || value < tmp->next->data)) || \
			(tmp->data < value && value < tmp->next->data))
			return (left_rot);
		tmp = tmp->next;
		left_rot++;
	}
	return (left_rot);
}

void	get_total(t_rotate *tmp, int a_cnt, int b_cnt)
{
	int const	a_r = tmp->left_rot;
	int const	a_rr = a_cnt - tmp->left_rot;
	int const	b_r = tmp->right_rot;
	int const	b_rr = b_cnt - tmp->right_rot;

	if (a_r > a_rr)
		tmp->left_rot = -a_rr;
	if (b_r > b_rr)
		tmp->right_rot = -b_rr;
	if (tmp->left_rot * tmp->right_rot >= 0)
		tmp->total_rot = get_max(absl(tmp->left_rot), absl(tmp->right_rot));
	else
		tmp->total_rot = absl(tmp->left_rot) + absl(tmp->right_rot);
}

t_rotate	find_best_case(t_deque *deq_a, t_deque *deq_b)
{
	t_rotate	tmp;
	t_rotate	best;
	t_node		*right_tmp;

	tmp.idx = 0;
	best.total_rot = -1;
	right_tmp = deq_b->head;
	while (right_tmp != NULL)
	{
		tmp.right_rot = tmp.idx;
		tmp.left_rot = get_left_rot(deq_a, right_tmp->data);
		get_total(&tmp, deq_a->cnt, deq_b->cnt);
		if (best.total_rot > tmp.total_rot || best.total_rot == -1)
		{
			best.idx = tmp.idx;
			best.left_rot = tmp.left_rot;
			best.right_rot = tmp.right_rot;
			best.total_rot = tmp.total_rot;
		}
		tmp.idx++;
		right_tmp = right_tmp->next;
	}
	return (best);
}

void	swap_group(t_deque *deq_a)
{
	t_node	*tmp;
	int		point;

	point = 0;
	tmp = deq_a->head;
	while (tmp->data != 0)
	{
		tmp = tmp->next;
		point++;
	}
	if (point < deq_a->cnt - point)
	{
		while (point-- > 0)
			rotate(deq_a, ra);
	}
	else
	{
		while (deq_a->cnt - point++ > 0)
			rotate(deq_a, rra);
	}
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
