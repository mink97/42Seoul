/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:33:34 by mingkang          #+#    #+#             */
/*   Updated: 2023/02/04 21:53:13 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_pwd(char **argv)
{
	char	buf[PATH_MAX + 1];

	(void)argv;
	if (getcwd(buf, PATH_MAX + 1) == NULL)
		ft_error("pwd", ERR_ETC_2);
	ft_putendl_fd(buf, STDOUT_FILENO);
}

void	builtin_env_traversal(void *key, void *val)
{
	if (!ft_strncmp("?", key, SIZE_T_MAX))
		return ;
	if (val)
		ft_printf("%s=%s\n", key, val);
}

void	builtin_env(char **argv)
{
	t_treemap	*env;

	(void)argv;
	env = get_env_map();
	treemap_inorder(env->root, builtin_env_traversal);
	ft_setenv(ft_strdup("?"), ft_itoa(0));
}
