/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 09:50:07 by mingkang          #+#    #+#             */
/*   Updated: 2023/01/05 16:12:10 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**parse_env(char **envp)
{
	int		i;
	char	**path;
	char	*str;

	while (*envp != 0)
	{
		if (ft_strncmp(*envp, "PATH", 4) == 0)
			break ;
		envp++;
	}
	path = ft_split(*envp + 5, ':');
	if (path == 0)
		ft_error("failed to split path");
	i = 0;
	while (path[i] != NULL)
	{
		str = path[i];
		path[i] = ft_strjoin(str, "/");
		free(str);
		i++;
	}
	return (path);
}

static void	check_cmd(t_cmd *cmd, char **path)
{
	char	*tmp;
	int		mode;
	int		i;

	i = 0;
	mode = F_OK | X_OK;
	if (access(cmd->argv[0], mode) == 0)
	{
		cmd->path = ft_strdup(cmd->argv[0]);
		return ;
	}
	while (path[i] != NULL)
	{
		tmp = ft_strjoin(path[i], cmd->argv[0]);
		if (access(tmp, mode) == 0)
			break ;
		free(tmp);
		tmp = NULL;
		i++;
	}
	cmd->path = tmp;
}

static t_cmd	*parse_cmd(int argc, char **argv, char **path)
{
	t_cmd	*cmd_arr;
	int		i;

	cmd_arr = malloc(sizeof(t_cmd) * (argc - 3));
	i = 0;
	while (i < argc - 3)
	{
		cmd_arr[i].argv = quatation_split(argv[i + 2], ' ');
		check_cmd(cmd_arr + i, path);
		i++;
	}
	free_strs(path);
	return (cmd_arr);
}

t_cmd	*init_cmd(int argc, char **argv, char **envp)
{
	t_cmd	*cmd_arr;
	char	**path;

	path = parse_env(envp);
	cmd_arr = parse_cmd(argc, argv, path);
	return (cmd_arr);
}
