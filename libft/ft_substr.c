/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:04:29 by mingkang          #+#    #+#             */
/*   Updated: 2022/11/12 10:03:24 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	n;
	size_t	size;

	if (s == 0)
		return (0);
	n = ft_strlen(s);
	if (n <= start)
		size = 0;
	else if (start + len < n)
		size = len;
	else
		size = n - start;
	sub_s = (char *)malloc(sizeof(char) * (size + 1));
	if (!sub_s)
		return (0);
	ft_memcpy(sub_s, s + start, size);
	sub_s[size] = 0;
	return (sub_s);
}
