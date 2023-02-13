/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:44:05 by mingkang          #+#    #+#             */
/*   Updated: 2023/02/04 21:51:25 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_err(char *str1, char *str2, int exit_num, t_bool bool)
{
	ft_putstr_fd("minishell: ", 2);
	if (str2 != NULL)
	{
		ft_putstr_fd(str1, 2);
		ft_putendl_fd(str2, 2);
		if (bool == TRUE)
			exit(exit_num);
		else
			set_exitcode(exit_num);
	}
	else
	{
		perror(str1);
		if (bool == TRUE)
			exit(exit_num);
		else
			set_exitcode(exit_num);
	}
}

void	set_exitcode(int ex_code)
{
	char	*str;

	str = ft_itoa(ex_code);
	ft_setenv(ft_strdup("?"), str);
}

int	get_exitcode(void)
{
	int		ex_code;
	char	*str;

	str = ft_getenv("?");
	ex_code = ft_atoi(str);
	return (ex_code);
}

void	ft_error(char *err_msg, t_error err_code)
{
	if (err_code == ERR_CMD_FOUND)
		print_err(err_msg, ": command not found", 127, TRUE);
	else if (err_code == ERR_NO_FILE)
		print_err(err_msg, ": No such file or directory", 1, FALSE);
	else if (err_code == ERR_NO_FILE_2)
		print_err(err_msg, ": No such file or directory", 127, TRUE);
	else if (err_code == ERR_PERMIT)
		print_err(err_msg, ": Permission denied", 126, TRUE);
	else if (err_code == ERR_TOO_MANY_ARG)
		print_err(err_msg, ": too many arguments", 1, FALSE);
	else if (err_code == ERR_NUM_ARG)
		print_err(err_msg, ": numeric argument required", 255, TRUE);
	else if (err_code == ERR_HOME_NOT_SET)
		print_err(err_msg, ": HOME not set", 1, FALSE);
	else if (err_code == ERR_OLDPWD_NOT_SET)
		print_err(err_msg, ": OLDPWD not set", 1, FALSE);
	else if (err_code == ERR_IS_DIRECTORY)
		print_err(err_msg, ": is a directory", 126, TRUE);
	else if (err_code == ERR_IS_NOT_DIRECTORY)
		print_err(err_msg, ": Not a directory", 1, FALSE);
	else if (err_code == ERR_ETC_2)
		print_err(err_msg, NULL, 1, FALSE);
	else
		print_err(err_msg, NULL, 1, TRUE);
}

void	ft_error_with_free(char *str1, char *str2, t_error err_code)
{
	char	*tmp;

	tmp = ft_strjoin(str1, str2);
	ft_error(tmp, err_code);
	free(tmp);
}
