/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bok <bok@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:29:12 by jbok              #+#    #+#             */
/*   Updated: 2023/02/04 23:08:04 by bok              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*malloc_check(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		perror("malloc");
		exit(1);
	}
	return (ptr);
}

void	dup2_check(int int1, int int2)
{
	if (dup2(int1, int2) < 0)
	{
		perror("dup2");
		exit(1);
	}
}

int	dup_check(int fd)
{
	int	ret;

	ret = dup(fd);
	if (ret < 0)
	{
		perror("dup");
		exit(1);
	}
	return (ret);
}
