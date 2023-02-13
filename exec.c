/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 21:16:15 by mingkang          #+#    #+#             */
/*   Updated: 2023/02/04 21:56:36 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	child_process(t_cmd *cmd, int *fds, char **envp)
{
	close(fds[0]);
	close(fds[1]);
	redi_cmd(cmd);
	if (cmd->cmd == NULL)
		;
	else if ((*cmd->cmd) != NULL && is_builtin(cmd))
		exec_builtin(cmd, TRUE);
	else if ((*cmd->cmd) != NULL)
	{
		check_cmd(cmd);
		if (cmd->path == NULL)
			ft_error(cmd->cmd[0], ERR_CMD_FOUND);
		execve(cmd->path, cmd->cmd, envp);
		exit(EXIT_FAILURE);
	}
	else
		set_exitcode(0);
	exit(get_exitcode());
}

static void	parent_process(t_cmd *cmd, int *fds)
{
	dup2_check(fds[0], STDIN_FILENO);
	close(fds[0]);
	close(fds[1]);
	del_cmd(cmd);
}

static void	exec_cmds(t_deque *cmd_list, char **envp)
{
	int		fds[2];
	t_cmd	*cmd;
	pid_t	pid;

	while (cmd_list->size)
	{
		cmd = ft_popfront(cmd_list);
		pipe(fds);
		pid = fork();
		if (pid < 0)
			ft_error("fork", ERR_ETC);
		else if (pid == 0)
		{
			if (cmd_list->size != 0)
				dup2_check(fds[1], STDOUT_FILENO);
			child_process(cmd, fds, envp);
		}
		parent_process(cmd, fds);
		if (cmd_list->size == 0)
			wait_child(pid);
	}
	while (waitpid(-1, NULL, 0) > 0)
		;
}

static void	exec_one_cmd(t_cmd *cmd, char **envp)
{
	pid_t	pid;

	redi_cmd(cmd);
	if (cmd->cmd == NULL)
		;
	else if (*(cmd->cmd) != NULL && is_builtin(cmd))
		exec_builtin(cmd, FALSE);
	else if (*(cmd->cmd) != NULL)
	{
		pid = fork();
		if (pid < 0)
			ft_error("fork", ERR_ETC);
		else if (pid == 0)
		{
			check_cmd(cmd);
			if (cmd->path == NULL)
				ft_error(cmd->cmd[0], ERR_CMD_FOUND);
			execve(cmd->path, cmd->cmd, envp);
			exit(EXIT_FAILURE);
		}
		wait_child(0);
	}
	else
		set_exitcode(0);
	del_cmd(cmd);
}

void	exec(t_deque *cmd_list)
{
	char	**envp;

	envp = get_envp();
	if (cmd_list->size > 1)
		exec_cmds(cmd_list, envp);
	else if (cmd_list->size == 1)
		exec_one_cmd(ft_popfront(cmd_list), envp);
	free_strs(envp);
	free(cmd_list);
}
