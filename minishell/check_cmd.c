/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:13:22 by mingkang          #+#    #+#             */
/*   Updated: 2023/02/04 21:09:23 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**get_env_path(char *path_value)
{
	size_t	i;
	char	**path;
	char	*str;

	path = ft_split(path_value, ':');
	if (path == 0)
		ft_error("ft_split", ERR_ETC);
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

static void	check_cmd_cwd(t_cmd *cmd)
{
	char	*tmp;

	tmp = ft_strjoin("./", cmd->cmd[0]);
	if (access(tmp, F_OK) == 0)
	{
		ft_printf("check\n");
		if (access(tmp, X_OK) == 0)
			cmd->path = tmp;
		else
			ft_error(cmd->cmd[0], ERR_PERMIT);
	}
	else
		ft_error(cmd->cmd[0], ERR_NO_FILE_2);
}

static void	check_cmd_path(t_cmd *cmd, char **path)
{
	size_t		i;
	char		*tmp;

	i = 0;
	while (path[i] != NULL && *(cmd->cmd[0]) != '\0')
	{
		tmp = ft_strjoin(path[i], cmd->cmd[0]);
		if (access(tmp, F_OK) == 0)
		{
			if (access(tmp, X_OK) == 0)
			{
				cmd->path = tmp;
				break ;
			}
			ft_error(cmd->cmd[0], ERR_PERMIT);
		}
		free(tmp);
		tmp = NULL;
		i++;
	}
	free_strs(path);
}

void	check_cmd(t_cmd *cmd)
{
	struct stat	buf;
	char		*path;

	cmd->path = NULL;
	if (ft_strchr(cmd->cmd[0], '/') != NULL)
	{
		if (stat(cmd->cmd[0], &buf) == 0 && (buf.st_mode & 0170000) == 0040000)
			ft_error(cmd->cmd[0], ERR_IS_DIRECTORY);
		else if (access(cmd->cmd[0], F_OK) == 0)
		{
			if (access(cmd->cmd[0], X_OK) == 0)
				cmd->path = ft_strdup(cmd->cmd[0]);
			else
				ft_error(cmd->cmd[0], ERR_PERMIT);
		}
		else
			ft_error(cmd->cmd[0], ERR_NO_FILE_2);
		return ;
	}
	path = ft_getenv("PATH");
	if (path == NULL)
		check_cmd_cwd(cmd);
	else
		check_cmd_path(cmd, get_env_path(path));
}
