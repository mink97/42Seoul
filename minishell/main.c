/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbok <jbok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:07:38 by jbok              #+#    #+#             */
/*   Updated: 2023/02/05 13:14:58 by jbok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char		*input;
	t_deque		*arg_lst;
	const int	std_io[2] = {dup_check(STDIN_FILENO), dup_check(STDOUT_FILENO)};

	init_signal();
	init_env();
	while (1)
	{
		input = readline("minishell$ ");
		if (!input)
			exit(get_exitcode());
		if (input[0] && !is_input_space(input))
		{
			add_history(input);
			arg_lst = parse(input);
			if (arg_lst)
				exec(arg_lst);
			dup2_check(std_io[0], STDIN_FILENO);
			dup2_check(std_io[1], STDOUT_FILENO);
		}
		free(input);
	}
	return (0);
}
