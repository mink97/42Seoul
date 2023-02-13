/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbok <jbok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:48:44 by mingkang          #+#    #+#             */
/*   Updated: 2023/02/05 13:18:43 by jbok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static unsigned char	check_is_numeric(char *str)
{
	int		num;
	char	*tmp;

	if (!ft_strncmp(str, "0", 2) || !ft_strncmp(str, "+0", 3) || \
		!ft_strncmp(str, "-0", 3))
		return (0);
	else if (!ft_strncmp(str, "-1", 3))
		return (255);
	tmp = str;
	if (*str == '+' || *str == '-')
		str++;
	if (*str == 0)
		ft_error_with_free("exit: ", tmp, ERR_NUM_ARG);
	while (*str != 0)
	{
		if (!ft_isdigit(*str))
			ft_error_with_free("exit: ", tmp, ERR_NUM_ARG);
		str++;
	}
	num = ft_atoi(tmp);
	if (num == -1 || num == 0)
		ft_error_with_free("exit: ", tmp, ERR_NUM_ARG);
	return ((unsigned char)num);
}

void	builtin_exit(char **cmd, t_bool is_pipe)
{
	unsigned char	ex_code;

	if (is_pipe == FALSE)
		ft_printf("exit\n");
	if (cmd[1] == 0)
		exit (EXIT_SUCCESS);
	ex_code = check_is_numeric(cmd[1]);
	if (cmd[2] != 0)
		ft_error("exit", ERR_TOO_MANY_ARG);
	else
		exit(ex_code);
}
