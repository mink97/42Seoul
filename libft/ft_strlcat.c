/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbok <jbok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:06:10 by jbok              #+#    #+#             */
/*   Updated: 2022/11/11 13:17:54 by jbok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(const char *str, size_t max)
{
	size_t	i;

	i = 0;
	while (str[i] && i < max)
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strnlen(dst, size);
	srclen = ft_strlen(src);
	if (dstlen == size)
		return (srclen + size);
	if (srclen < size - dstlen)
		ft_memcpy(dst + dstlen, src, srclen + 1);
	else
	{
		ft_memcpy(dst + dstlen, src, size - dstlen - 1);
		dst[size - 1] = 0;
	}
	return (dstlen + srclen);
}
