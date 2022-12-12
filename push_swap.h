/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:19:32 by mingkang          #+#    #+#             */
/*   Updated: 2022/12/12 13:35:24 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

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

typedef struct s_rotate
{
	int		idx;
	int		left_rot;
	int		right_rot;
	int		total_rot;
}	t_rotate;

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

// common.c
int			get_max(int a, int b);
int			get_min(int a, int b);
int			absl(int a);
void		gen_error(void);

// execute_best.c
void		execute_best(t_deque *deq_a, t_deque *deq_b, t_rotate best);

// hand_over_utils.c
t_rotate	find_best_case(t_deque *deq_a, t_deque *deq_b);
void		swap_group(t_deque *deq_a);

// hand_over.c
void		handover_a_to_b(t_deque *deq_a, t_deque *deq_b);
void		handover_b_to_a(t_deque *deq_b, t_deque *deq_a);

// hard_code.c
void		hard_coding(t_deque *deq_a, t_deque *deq_b);

// libft_utils.c
size_t		word_cnt(char *str, char c);
char		**ft_split(char const *s, char c);
long long	ft_atoi(const char *str);

// init_deque.c
void		init_deque(int argc, char **argv, t_deque **deq_a, t_deque **deq_b);

// deque_utils.c
t_node		*create_node(int element);
void		push_front(t_deque *deq, t_node *new_node);
void		push_rear(t_deque *deq, t_node *new_node);
t_node		*pop_front(t_deque *deq);
t_node		*pop_rear(t_deque *deq);

// opration.c
void		swap(t_deque *deque, int act);
void		swap_both(t_deque *deq_a, t_deque *deq_b);
void		push(t_deque *src_deq, t_deque *dst_deq, int act);
void		rotate(t_deque *deq, int act);
void		rotate_both(t_deque *deq_a, t_deque *deq_b, int act);

#endif
