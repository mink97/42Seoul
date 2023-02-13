/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbok <jbok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:26:02 by jbok              #+#    #+#             */
/*   Updated: 2023/02/03 20:40:18 by jbok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in_set(const unsigned char charset[32], const char c)
{
	if (charset[(unsigned char)c / 8] & 1 << (unsigned char)c % 8)
		return (1);
	else
		return (0);
}

static char	*ft_strndup(const char *src, size_t len)
{
	char	*dst;

	dst = (char *)malloc_check(sizeof(char) * (len + 1));
	ft_memcpy(dst, src, len);
	dst[len] = 0;
	return (dst);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned char	charset[32];
	size_t			i;
	size_t			j;

	if (!s1 || !set)
		return (0);
	i = 0;
	j = ft_strlen(s1);
	if (!j)
		return (ft_calloc(1, sizeof(char)));
	ft_bzero(charset, 32);
	while (set[i])
	{
		charset[(unsigned char)set[i] / 8] |= 1 << (unsigned char)set[i] % 8;
		i++;
	}
	i = 0;
	while (ft_is_in_set(charset, s1[i]))
		i++;
	while (ft_is_in_set(charset, s1[j - 1]))
		j--;
	if (i >= j)
		return (ft_calloc(1, sizeof(char)));
	return (ft_strndup(s1 + i, j - i));
}
