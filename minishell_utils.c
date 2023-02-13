/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbok <jbok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:14:30 by jbok              #+#    #+#             */
/*   Updated: 2023/02/04 20:55:35 by jbok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp_treemap(void *a, void *b)
{
	return (ft_strncmp(a, b, -1));
}

int	is_input_space(char *input)
{
	size_t	i;

	i = 0;
	while (input[i] && input[i] == ' ')
		i++;
	if (input[i])
		return (0);
	ft_setenv(ft_strdup("?"), ft_itoa(0));
	return (1);
}
