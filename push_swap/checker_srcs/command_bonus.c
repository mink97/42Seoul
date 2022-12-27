/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:27:00 by mingkang          #+#    #+#             */
/*   Updated: 2022/12/13 20:47:16 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && i + 1 < n)
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	command(t_deque *deq_a, t_deque *deq_b, char *act)
{
	if (ft_strncmp(act, "sa\n", 4) == 0)
		swap(deq_a);
	else if (ft_strncmp(act, "sb\n", 4) == 0)
		swap(deq_b);
	else if (ft_strncmp(act, "ss\n", 4) == 0)
		swap_both(deq_a, deq_b);
	else if (ft_strncmp(act, "pa\n", 4) == 0)
		push(deq_b, deq_a);
	else if (ft_strncmp(act, "pb\n", 4) == 0)
		push(deq_a, deq_b);
	else if (ft_strncmp(act, "ra\n", 4) == 0)
		rotate(deq_a, ra);
	else if (ft_strncmp(act, "rb\n", 4) == 0)
		rotate(deq_b, rb);
	else if (ft_strncmp(act, "rr\n", 4) == 0)
		rotate_both(deq_a, deq_b, rr);
	else if (ft_strncmp(act, "rra\n", 5) == 0)
		rotate(deq_a, rra);
	else if (ft_strncmp(act, "rrb\n", 5) == 0)
		rotate(deq_b, rrb);
	else if (ft_strncmp(act, "rrr\n", 5) == 0)
		rotate_both(deq_a, deq_b, rrr);
	else
		gen_error();
}

int	check_align(t_deque *deq_a, t_deque *deq_b)
{
	t_node	*tmp;

	if (deq_b->cnt != 0)
		return (0);
	tmp = deq_a->head;
	while (tmp->next != NULL)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
