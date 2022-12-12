/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:39:45 by mingkang          #+#    #+#             */
/*   Updated: 2022/12/12 13:30:18 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_deque	*deq_a;
	t_deque	*deq_b;

	if (argc == 1)
		return (0);
	init_deque(argc - 1, argv + 1, &deq_a, &deq_b);
	handover_a_to_b(deq_a, deq_b);
	handover_b_to_a(deq_b, deq_a);
}
