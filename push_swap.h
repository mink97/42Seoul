/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:19:32 by mingkang          #+#    #+#             */
/*   Updated: 2022/12/02 17:14:27 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define TRUE 1
# define FALSE 0

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

typedef struct s_best_case
{
	int		idx;
	int		left_rotate;
	int		right_rotate;
	int		total_rotate;
}	t_best_case;

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

// libft_utils.c
long long	ft_atoi(const char *str);

// opration.c
void		swap(t_deque *deque, int act);
void		push(t_deque *src_deq, t_deque *dst_deq, int act);
void		rotate(t_deque *deq, int act);
void		swap_both(t_deque *deq_a, t_deque *deq_b, int act);
void		rotate_both(t_deque *deq_a, t_deque *deq_b, int act);

// init_deque.c
void		init_deque(int argc, char **argv, t_deque **deq_a, t_deque **deq_b);
int			parse_argv(int argc, char **argv, int **arr);
void		push_argv(t_deque *deq_a, int *arr, int arr_len);
int			check_align(int *arr, int arr_len);

// deque.c
t_deque		*create_deque(void);
t_node		*create_node(int element);
int			push_front(t_deque *deq, t_node *new_node);
int			push_rear(t_deque *deq, t_node *new_node);
t_node		*pop_front(t_deque *deq);
t_node		*pop_rear(t_deque *deq);

// ft_split.c
char		**ft_split(char const *s, char c);
size_t		word_cnt(char *str, char c);

void		gen_error(void);

// for check(tmp)
void		show_deque(t_deque *deq);

#endif
