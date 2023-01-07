/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:18:26 by mingkang          #+#    #+#             */
/*   Updated: 2022/11/12 09:55:08 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	needle_len = ft_strlen(needle);
	while (haystack[i] != '\0' && i + needle_len <= len)
	{
		if (haystack[i] == needle[0])
		{
			if (!ft_strncmp(haystack + i, needle, needle_len))
				return ((char *)haystack + i);
		}
		i++;
	}
	return (0);
}
