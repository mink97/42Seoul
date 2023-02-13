/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbok <jbok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:02:26 by jbok              #+#    #+#             */
/*   Updated: 2023/02/03 20:39:09 by jbok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	src_len;

	if (!s)
		return (0);
	src_len = ft_strlen(s);
	if (start >= src_len)
		return (ft_calloc(1, sizeof(char)));
	if (len < src_len - start)
		ptr = malloc_check(sizeof(char) * (len + 1));
	else
		ptr = malloc_check(sizeof(char) * (src_len - start + 1));
	ft_strncpy(ptr, s + start, len);
	return (ptr);
}
