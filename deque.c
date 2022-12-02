/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:45:21 by mingkang          #+#    #+#             */
/*   Updated: 2022/12/02 17:04:43 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_deque	*create_deque(void)
{
	t_deque	*deq;

	deq = malloc(sizeof(t_deque));
	if (deq == NULL)
		gen_error();
	deq->cnt = 0;
	deq->head = NULL;
	deq->tail = NULL;
	return (deq);
}

t_node	*create_node(int element)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		gen_error();
	new_node->data = element;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

int	push_front(t_deque *deq, t_node *new_node)
{
	if (deq->head == NULL && deq->tail == NULL)
	{
		deq->head = new_node;
		deq->tail = new_node;
	}
	else
	{
		new_node->next = deq->head;
		deq->head->prev = new_node;
		deq->head = new_node;
	}
	deq->cnt++;
	return (TRUE);
}

int	push_rear(t_deque *deq, t_node *new_node)
{
	if (deq->head == NULL && deq->tail == NULL)
	{
		deq->head = new_node;
		deq->tail = new_node;
	}
	else
	{
		new_node->prev = deq->tail;
		deq->tail->next = new_node;
		deq->tail = new_node;
	}
	deq->cnt++;
	return (TRUE);
}

t_node	*pop_front(t_deque *deq)
{
	t_node	*ret_node;

	ret_node = deq->head;
	if (ret_node == NULL)
		gen_error();
	if (deq->cnt == 1)
	{
		deq->head = NULL;
		deq->tail = NULL;
	}
	else
	{
		deq->head = deq->head->next;
		ret_node->next = NULL;
		deq->head->prev = NULL;
	}
	deq->cnt--;
	return (ret_node);
}

t_node	*pop_rear(t_deque *deq)
{
	t_node	*ret_node;

	ret_node = deq->tail;
	if (ret_node == NULL)
		gen_error();
	if (deq->cnt == 1)
	{
		deq->head = NULL;
		deq->tail = NULL;
	}
	else
	{
		deq->tail = deq->tail->prev;
		ret_node->prev = NULL;
		deq->tail->next = NULL;
	}
	deq->cnt--;
	return (ret_node);
}

#include <stdio.h>
void	show_deque(t_deque *deq)
{
	t_node	*p_node;

	if (deq == NULL)
	{
		printf("show_deque() error\n");
		return ;
	}
	p_node = deq->head;
	while (p_node != NULL)
	{
		printf("[%d]\n", p_node->data);
		p_node = p_node->next;
	}
	printf("---------------------------------\n");
}
