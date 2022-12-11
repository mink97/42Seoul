/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:39:45 by mingkang          #+#    #+#             */
/*   Updated: 2022/12/11 16:45:42 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	gen_error(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

#include <stdio.h>
int	main(int argc, char **argv)
{
	t_deque	*deq_a;
	t_deque	*deq_b;

	// printf("start\n");
	// printf("---------------------------------\n");
	init_deque(argc - 1, argv + 1, &deq_a, &deq_b);
	// show_deque(deq_a);
	handover_a_to_b(deq_a, deq_b);
	// show_deque(deq_b);
	handover_b_to_a(deq_b, deq_a);
	// show_deque(deq_a);
}
