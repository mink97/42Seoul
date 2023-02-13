/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbok <jbok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:12:11 by mingkang          #+#    #+#             */
/*   Updated: 2023/02/05 13:11:01 by jbok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	set_unique_path(char **path, int opt)
{
	if (opt == 0)
	{
		*path = ft_getenv("HOME");
		if (*path == NULL)
			ft_error("cd", ERR_HOME_NOT_SET);
		else
			return (TRUE);
	}
	else if (opt == 1)
	{
		*path = ft_getenv("OLDPWD");
		if (*path == NULL)
			ft_error("cd", ERR_OLDPWD_NOT_SET);
		else
			return (TRUE);
	}
	return (FALSE);
}

static void	change_dir(char **cmd, char *path)
{
	char		buf[PATH_MAX + 1];
	struct stat	buf_st;

	if (*path == '\0')
		set_exitcode(0);
	else if (stat(path, &buf_st) == 0 && (buf_st.st_mode & 0170000) != 0040000)
		ft_error_with_free("cd: ", path, ERR_IS_NOT_DIRECTORY);
	else if (chdir(path) != 0)
		ft_error_with_free("cd: ", path, ERR_NO_FILE);
	else
	{
		ft_setenv(ft_strdup("OLDPWD"), ft_strdup(ft_getenv("PWD")));
		if (getcwd(buf, PATH_MAX + 1) == NULL)
			ft_error("cd", ERR_ETC);
		ft_setenv(ft_strdup("PWD"), ft_strdup(buf));
		if (cmd[1] != NULL && ft_strncmp(cmd[1], "-", 2) == 0)
			ft_printf("%s\n", buf);
		set_exitcode(0);
	}
}

void	builtin_cd(char **cmd)
{
	char	*path;
	t_bool	flag;

	flag = TRUE;
	if (cmd[1] == 0 || ft_strncmp(cmd[1], "~", 2) == 0)
		flag = set_unique_path(&path, 0);
	else if (ft_strncmp(cmd[1], "-", 2) == 0)
		flag = set_unique_path(&path, 1);
	else if (ft_strncmp(cmd[1], "~/", 2) == 0)
	{
		path = ft_getenv("HOME");
		if (path == NULL)
			path = cmd[1] + 1;
		else
			path = ft_strjoin(path, cmd[1] + 1);
	}
	else
		path = cmd[1];
	if (flag == FALSE)
		return ;
	change_dir(cmd, path);
	if (cmd[1] != NULL && ft_strncmp(cmd[1], "~/", 2) == 0 \
		&& ft_getenv("HOME") != NULL)
		free(path);
}
