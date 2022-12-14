/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:39:50 by mingkang          #+#    #+#             */
/*   Updated: 2022/12/12 13:35:00 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	push_front(t_deque *deq, t_node *new_node)
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
}

void	push_rear(t_deque *deq, t_node *new_node)
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
