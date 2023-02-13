/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:02:35 by mingkang          #+#    #+#             */
/*   Updated: 2023/02/04 20:55:01 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	is_n_opt(char *str)
{
	size_t		i;

	i = 0;
	if (str[i++] != '-')
		return (FALSE);
	while (str[i])
	{
		if (str[i++] != 'n')
			return (FALSE);
	}
	return (TRUE);
}

void	builtin_echo(char **argv)
{
	size_t	i;
	t_bool	flag;

	flag = FALSE;
	if (argv[1] != NULL)
		flag = is_n_opt(argv[1]);
	i = 1;
	while (argv[i] != NULL && is_n_opt(argv[i]) == TRUE)
		i++;
	while (argv[i] != NULL)
	{
		ft_printf("%s", argv[i++]);
		if (argv[i] != NULL)
			ft_printf(" ");
	}
	if (flag == FALSE)
		ft_printf("\n");
	set_exitcode(0);
}
