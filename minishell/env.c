/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbok <jbok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:28:05 by jbok              #+#    #+#             */
/*   Updated: 2023/02/04 17:22:34 by jbok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_env(void)
{
	__handle_env(0, 0, ENV_INIT);
}

char	*ft_getenv(char *name)
{
	return (__handle_env(name, 0, ENV_GET));
}

char	*ft_setenv(char *name, char *val)
{
	return (__handle_env(name, val, ENV_SET));
}

char	*ft_unsetenv(char *name)
{
	return (__handle_env(name, 0, ENV_DEL));
}

t_treemap	*get_env_map(void)
{
	return (__handle_env(0, 0, ENV_GET_MAP));
}
