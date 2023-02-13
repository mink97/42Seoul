/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_strs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbok <jbok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 13:34:14 by mingkang          #+#    #+#             */
/*   Updated: 2023/02/03 20:30:31 by jbok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_strs(void *var)
{
	char	**strs;
	size_t	i;

	strs = (char **)var;
	i = 0;
	while (strs[i] != NULL)
	{
		free(strs[i]);
		strs[i] = NULL;
		i++;
	}
	free(strs);
}
