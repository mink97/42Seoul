/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbok <jbok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:17:53 by jbok              #+#    #+#             */
/*   Updated: 2022/11/11 09:29:38 by jbok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h_len;
	size_t	n_len;
	size_t	i;

	if (!(haystack && needle) && !len)
		return (0);
	h_len = ft_strlen(haystack);
	n_len = ft_strlen(needle);
	i = 0;
	while (i + n_len <= h_len && i + n_len <= len)
	{
		if (ft_memcmp(haystack + i, needle, n_len) == 0)
			return ((char *)(haystack + i));
		i++;
	}
	return (0);
}
