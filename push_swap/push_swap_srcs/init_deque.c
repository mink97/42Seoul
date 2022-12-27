/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_deque.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:45:21 by mingkang          #+#    #+#             */
/*   Updated: 2022/12/14 11:31:23 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_deque	*create_deque(void)
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

static void	convert_to_int(int *arr, int argc, char **argv)
{
	int			i;
	int			j;
	int			k;
	long long	num;
	char		**strs;

	i = 0;
	j = 0;
	while (i < argc)
	{
		strs = ft_split(argv[i++], ' ');
		if (strs == NULL)
			gen_error();
		k = 0;
		while (strs[k] != NULL)
		{
			num = ft_atoi(strs[k]);
			arr[j++] = (int)num;
			free(strs[k++]);
		}
		free(strs);
	}
}

static int	parse_argv(int argc, char **argv, int **arr)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (i < argc)
		cnt += word_cnt(argv[i++], ' ');
	if (cnt == 0)
		gen_error();
	*arr = malloc(sizeof(int) * cnt);
	if (*arr == NULL)
		gen_error();
	convert_to_int(*arr, argc, argv);
	i = 0;
	while (i < cnt - 1)
	{
		if ((*arr)[i] - (*arr)[i + 1] > 0)
			return (cnt);
		i++;
	}
	exit(EXIT_SUCCESS);
}

static void	push_argv(t_deque *deq_a, int *arr, int arr_len)
{
	int		i;
	int		j;
	int		idx;
	t_node	*tmp;

	i = -1;
	while (++i < arr_len)
	{
		j = -1;
		idx = 0;
		while (++j < arr_len)
		{
			if (i != j && arr[i] == arr[j])
				gen_error();
			if (arr[i] > arr[j])
				idx++;
		}
		tmp = create_node(idx);
		push_rear(deq_a, tmp);
	}
}

void	init_deque(int argc, char **argv, t_deque **deq_a, t_deque **deq_b)
{
	int	cnt;
	int	*arr;

	cnt = parse_argv(argc, argv, &arr);
	*deq_a = create_deque();
	*deq_b = create_deque();
	push_argv(*deq_a, arr, cnt);
	free(arr);
}
