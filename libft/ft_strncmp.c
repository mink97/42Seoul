/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:35:28 by mingkang          #+#    #+#             */
/*   Updated: 2022/11/12 09:44:21 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && i + 1 < n)
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
