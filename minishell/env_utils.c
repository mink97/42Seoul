/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bok <bok@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:42:38 by jbok              #+#    #+#             */
/*   Updated: 2023/02/04 23:09:44 by bok              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	__init_env(t_treemap *env);
static char	**treemap_to_envp(t_treemap *map);
static int	__tree_to_envp(t_treemap_node *node, char **envp);

void	*__handle_env(char *key, char *val, int mode)
{
	static t_treemap	env = {0, ft_strcmp_treemap};

	if (mode == ENV_INIT)
		__init_env(&env);
	else if (mode == ENV_SET)
		treemap_insert(&env, key, val);
	else if (mode == ENV_GET)
		return (treemap_get(env.root, key, env.key_cmp));
	else if (mode == ENV_DEL)
		treemap_del(&env, key);
	else if (mode == ENV_GET_MAP)
		return (&env);
	else if (mode == ENV_GET_ENVP)
		return (treemap_to_envp(&env));
	return (0);
}

static void	__init_env(t_treemap *env)
{
	extern char	**environ;
	char		**tmp;
	size_t		key_len;

	tmp = environ;
	while (*tmp)
	{
		key_len = 0;
		while ((*tmp)[key_len] && (*tmp)[key_len] != '=')
			key_len++;
		if ((*tmp)[key_len] == '=')
			treemap_insert(env, ft_substr(*tmp, 0, key_len), \
			ft_substr(*tmp, key_len + 1, SIZE_T_MAX));
		else
			treemap_insert(env, ft_substr(*tmp, 0, key_len), 0);
		tmp++;
	}
	ft_setenv(ft_strdup("?"), ft_strdup("0"));
	ft_unsetenv("OLDPWD");
}

char	**get_envp(void)
{
	return (__handle_env(0, 0, ENV_GET_ENVP));
}

static char	**treemap_to_envp(t_treemap *map)
{
	char	**envp;

	envp = malloc_check(sizeof(char *) * (treemap_get_size(map->root) + 1));
	__tree_to_envp(map->root, envp);
	envp[treemap_get_size(map->root)] = 0;
	return (envp);
}

static int	__tree_to_envp(t_treemap_node *node, char **envp)
{
	char	*env;
	size_t	len;
	size_t	key_len;

	if (!node)
		return (0);
	envp += __tree_to_envp(node->left, envp);
	len = ft_strlen(node->key);
	key_len = len;
	if (node->val)
		len += ft_strlen(node->val) + 1;
	env = malloc_check(sizeof(char) * (len + 1));
	env[len] = 0;
	ft_memcpy(env, node->key, key_len);
	if (node->val)
	{
		env[key_len] = '=';
		ft_memcpy(env + key_len + 1, node->val, len - (key_len + 1));
	}
	*envp++ = env;
	envp += __tree_to_envp(node->right, envp);
	return (treemap_get_size(node));
}
