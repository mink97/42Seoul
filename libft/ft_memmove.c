/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:39:47 by mingkang          #+#    #+#             */
/*   Updated: 2022/11/12 09:21:07 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*to;
	unsigned char	*from;

	to = (unsigned char *)dst;
	from = (unsigned char *)src;
	if (dst == 0 && src == 0)
		return (0);
	if (to <= from)
	{
		i = 0;
		while (i < len)
		{
			to[i] = from[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (i-- > 0)
			to[i] = from[i];
	}
	return (dst);
}
