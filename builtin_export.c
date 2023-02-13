/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbok <jbok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:01:30 by jbok              #+#    #+#             */
/*   Updated: 2023/02/04 15:54:50 by jbok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	env_syntax_error(char *str, int flag);

int	check_env_syntax(char *str)
{
	size_t	name_len;

	name_len = 0;
	if (ft_isalpha(str[name_len]) || str[name_len] == '_')
		name_len++;
	else
		return (name_len);
	while (ft_isalnum(str[name_len]) || str[name_len] == '_')
		name_len++;
	if (str[name_len] == '=' || !(str[name_len]))
		return (name_len);
	return (0);
}

void	builtin_export_traversal(void *key, void *val)
{
	if (!ft_strncmp("?", key, SIZE_T_MAX))
		return ;
	if (val)
		ft_printf("declare -x %s=\"%s\"\n", key, val);
	else
		ft_printf("declare -x %s\n", key);
}

void	builtin_export(char **argv)
{
	size_t		key_len;
	int			flag;

	flag = 0;
	if (*argv)
	{
		while (*argv)
		{
			key_len = check_env_syntax(*argv);
			if (!key_len)
			{
				env_syntax_error(*argv, 0);
				flag = 1;
			}
			else if ((*argv)[key_len] == '=')
				ft_setenv(ft_substr(*argv, 0, key_len), \
				ft_substr(*argv, key_len + 1, SIZE_T_MAX));
			else
				ft_setenv(ft_substr(*argv, 0, key_len), 0);
			argv++;
		}
	}
	else
		treemap_inorder(get_env_map()->root, builtin_export_traversal);
	ft_setenv(ft_strdup("?"), ft_itoa(flag));
}

void	builtin_unset(char **argv)
{
	int	flag;

	flag = 0;
	while (*argv)
	{
		if (!check_env_syntax(*argv))
		{
			env_syntax_error(*argv++, 1);
			flag = 1;
		}
		else
			ft_unsetenv(*argv++);
	}
	ft_setenv(ft_strdup("?"), ft_itoa(flag));
}

static void	env_syntax_error(char *str, int flag)
{
	ft_putstr_fd("minishell: ", 2);
	if (flag)
		ft_putstr_fd("unset: `", 2);
	else
		ft_putstr_fd("export: `", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd("\': not a valid identifier", 2);
}
