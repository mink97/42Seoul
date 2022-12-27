/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:01:30 by mingkang          #+#    #+#             */
/*   Updated: 2022/12/13 20:47:37 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include "get_next_line/get_next_line_bonus.h"

typedef struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_deque
{
	int		cnt;
	t_node	*head;
	t_node	*tail;
}	t_deque;

enum e_operation
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
};

// init_deque.c
void		init_deque(int argc, char **argv, t_deque **deq_a, t_deque **deq_b);

// deque_utils.c
t_node		*create_node(int element);
void		push_front(t_deque *deq, t_node *new_node);
void		push_rear(t_deque *deq, t_node *new_node);
t_node		*pop_front(t_deque *deq);
t_node		*pop_rear(t_deque *deq);

// libft_utils.c
size_t		word_cnt(char *str, char c);
char		**ft_split(char const *s, char c);
long long	ft_atoi(const char *str);

// opration.c
void		swap(t_deque *deque);
void		swap_both(t_deque *deq_a, t_deque *deq_b);
void		push(t_deque *src_deq, t_deque *dst_deq);
void		rotate(t_deque *deq, int act);
void		rotate_both(t_deque *deq_a, t_deque *deq_b, int act);

// command_bonus.c
void		gen_error(void);
void		command(t_deque *deq_a, t_deque *deq_b, char *act);
int			check_align(t_deque *deq_a, t_deque *deq_b);

#endif
