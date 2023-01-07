/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:54:18 by mingkang          #+#    #+#             */
/*   Updated: 2022/11/09 16:17:19 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_p;
	unsigned char	*s2_p;

	s1_p = (unsigned char *)s1;
	s2_p = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i + 1 < n)
	{
		if (s1_p[i] != s2_p[i])
			break ;
		i++;
	}
	return (s1_p[i] - s2_p[i]);
}
