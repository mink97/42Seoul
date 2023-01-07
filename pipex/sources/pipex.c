/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 10:04:50 by mingkang          #+#    #+#             */
/*   Updated: 2023/01/05 16:16:48 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(t_cmd_lst *cmd_lst, int *fds, int i, int cmd_cnt)
{
	if (i != cmd_cnt - 1)
		dup2(fds[1], STDOUT_FILENO);
	close(fds[0]);
	close(fds[1]);
	if (i == 0 && cmd_lst->is_error == TRUE)
	{
		write(STDOUT_FILENO, NULL, 1);
		exit(EXIT_FAILURE);
	}
	if (cmd_lst->cmd_arr[i].path == NULL)
	{
		perror("sh: command not found");
		write(STDOUT_FILENO, NULL, 1);
		exit(EXIT_FAILURE);
	}
	execve(cmd_lst->cmd_arr[i].path, cmd_lst->cmd_arr[i].argv, cmd_lst->envp);
	ft_error("failed to execute cmd");
}

void	run_pipe(t_cmd_lst *cmd_lst, int cmd_cnt)
{
	int		i;
	int		fds[2];
	pid_t	pid;

	i = -1;
	while (++i < cmd_cnt)
	{
		pipe(fds);
		pid = fork();
		if (pid < 0)
			ft_error("fork error");
		else if (pid == 0)
			child_process(cmd_lst, fds, i, cmd_cnt);
		dup2(fds[0], STDIN_FILENO);
		close(fds[0]);
		close(fds[1]);
	}
}

void	exec_here_doc(int argc, char **argv, t_cmd_lst *cmd_lst)
{
	int		fd_io[2];

	cmd_lst->cmd_arr = init_cmd(argc - 1, argv + 1, cmd_lst->envp);
	make_here_doc(argv[2]);
	fd_io[0] = open("/tmp/here_doc", O_RDONLY, 0644);
	dup2(fd_io[0], STDIN_FILENO);
	close(fd_io[0]);
	fd_io[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	dup2(fd_io[1], STDOUT_FILENO);
	close(fd_io[1]);
	run_pipe(cmd_lst, argc - 4);
	free_cmd_lst(cmd_lst, argc - 4);
	unlink("/tmp/here_doc");
}

void	exec_cmd(int argc, char **argv, t_cmd_lst *cmd_lst)
{
	int		fd_io[2];

	cmd_lst->cmd_arr = init_cmd(argc, argv, cmd_lst->envp);
	fd_io[0] = open(argv[1], O_RDONLY, 0644);
	if (fd_io[0] < 0)
	{
		perror("sh: error");
		fd_io[0] = open("/tmp/open_err", O_RDONLY | O_CREAT | O_TRUNC, 0644);
		cmd_lst->is_error = TRUE;
	}
	dup2(fd_io[0], STDIN_FILENO);
	close(fd_io[0]);
	fd_io[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(fd_io[1], STDOUT_FILENO);
	close(fd_io[1]);
	run_pipe(cmd_lst, argc - 3);
	free_cmd_lst(cmd_lst, argc - 3);
}

int	main(int argc, char **argv, char **envp)
{
	t_cmd_lst	*cmd_lst;

	if (argc < 5)
		ft_error("there are few arguments");
	cmd_lst = malloc(sizeof(t_cmd_lst) * 1);
	cmd_lst->envp = envp;
	cmd_lst->is_error = FALSE;
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		exec_here_doc(argc, argv, cmd_lst);
	else
		exec_cmd(argc, argv, cmd_lst);
	while (waitpid(-1, NULL, 0) > 0)
		;
	return (0);
}
