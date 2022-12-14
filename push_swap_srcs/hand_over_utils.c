/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hand_over_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:06:39 by mingkang          #+#    #+#             */
/*   Updated: 2022/12/12 13:25:03 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_left_rot(t_deque *deq_a, int value)
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

static int	get_total_rot(t_rotate *tmp, int a_cnt, int b_cnt)
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
		return (get_max(absl(tmp->left_rot), absl(tmp->right_rot)));
	else
		return (absl(tmp->left_rot) + absl(tmp->right_rot));
}

t_rotate	find_best_case(t_deque *deq_a, t_deque *deq_b)
{
	t_rotate	tmp;
	t_rotate	best;
	t_node		*right_tmp;

	tmp.idx = 0;
	right_tmp = deq_b->head;
	while (right_tmp != NULL)
	{
		tmp.right_rot = tmp.idx;
		tmp.left_rot = get_left_rot(deq_a, right_tmp->data);
		tmp.total_rot = get_total_rot(&tmp, deq_a->cnt, deq_b->cnt);
		if (tmp.idx == 0 || best.total_rot > tmp.total_rot)
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
