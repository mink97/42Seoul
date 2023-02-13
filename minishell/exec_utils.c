/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:26:19 by mingkang          #+#    #+#             */
/*   Updated: 2023/02/04 21:27:03 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	wait_child(pid_t pid)
{
	int	status;

	waitpid(pid, &status, 0);
	if ((status & 0177) == 0)
		set_exitcode((status >> 8) & 0xff);
	else if ((status & 0177) != 0 && (status & 0177) != 0177)
		set_exitcode(128 + (status & 0177));
}

int	is_builtin(t_cmd *cmd)
{
	char	*cmd_name;

	cmd_name = cmd->cmd[0];
	if (ft_strncmp(cmd_name, "echo", 5) == 0 || \
		ft_strncmp(cmd_name, "cd", 3) == 0 || \
		ft_strncmp(cmd_name, "pwd", 4) == 0 || \
		ft_strncmp(cmd_name, "export", 7) == 0 || \
		ft_strncmp(cmd_name, "unset", 6) == 0 || \
		ft_strncmp(cmd_name, "env", 4) == 0 || \
		ft_strncmp(cmd_name, "exit", 5) == 0)
		return (1);
	return (0);
}

void	redi_cmd(t_cmd *cmd)
{
	if (cmd->infile != NULL)
	{
		dup2_check(cmd->infile->fd, STDIN_FILENO);
		close(cmd->infile->fd);
	}
	if (cmd->outfile != NULL)
	{
		dup2_check(cmd->outfile->fd, STDOUT_FILENO);
		close(cmd->outfile->fd);
	}
}

void	exec_builtin(t_cmd *cmd, t_bool is_pipe)
{
	char	*cmd_name;

	cmd_name = cmd->cmd[0];
	if (ft_strncmp(cmd_name, "echo", 5) == 0)
		builtin_echo(cmd->cmd);
	else if (ft_strncmp(cmd_name, "cd", 3) == 0)
		builtin_cd(cmd->cmd);
	else if (ft_strncmp(cmd_name, "pwd", 4) == 0)
		builtin_pwd(cmd->cmd);
	else if (ft_strncmp(cmd_name, "export", 7) == 0)
		builtin_export(cmd->cmd + 1);
	else if (ft_strncmp(cmd_name, "unset", 6) == 0)
		builtin_unset(cmd->cmd + 1);
	else if (ft_strncmp(cmd_name, "env", 4) == 0)
		builtin_env(cmd->cmd);
	else if (ft_strncmp(cmd_name, "exit", 5) == 0)
		builtin_exit(cmd->cmd, is_pipe);
}
