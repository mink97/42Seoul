/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:01:34 by mingkang          #+#    #+#             */
/*   Updated: 2022/12/13 20:49:50 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	free_deq(t_deque *deq)
{
	t_node	*tmp;
	t_node	*dummy;

	tmp = deq->head;
	while (tmp != NULL)
	{
		dummy = tmp;
		tmp = tmp->next;
		free(dummy);
	}
	free(deq);
}

void	gen_error(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_deque	*deq_a;
	t_deque	*deq_b;
	char	*str;

	if (argc == 1)
		return (0);
	init_deque(argc - 1, argv + 1, &deq_a, &deq_b);
	str = get_next_line(0);
	while (str != NULL)
	{
		command(deq_a, deq_b, str);
		free(str);
		str = get_next_line(0);
	}
	if (check_align(deq_a, deq_b) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_deq(deq_a);
	free_deq(deq_b);
}
