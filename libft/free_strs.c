/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_strs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 13:34:14 by mingkang          #+#    #+#             */
/*   Updated: 2022/12/24 15:08:21 by mingkang         ###   ########.fr       */
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
