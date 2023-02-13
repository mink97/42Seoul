/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbok <jbok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:31:41 by jbok              #+#    #+#             */
/*   Updated: 2023/02/03 20:37:12 by jbok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size && count > SIZE_MAX / size)
		return (0);
	ptr = malloc_check(count * size);
	ft_bzero(ptr, count * size);
	return (ptr);
}

void	*ft_realloc(void *src, size_t src_size, size_t dst_size)
{
	void	*ptr;

	if (src_size >= dst_size)
		return (src);
	ptr = malloc_check(dst_size);
	ptr = ft_memcpy(ptr, src, src_size);
	free(src);
	return (ptr);
}
