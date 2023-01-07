/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:56:08 by mingkang          #+#    #+#             */
/*   Updated: 2022/11/12 09:37:12 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len_1;
	size_t	len_2;

	if (s1 == 0 || s2 == 0)
		return (0);
	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len_1 + len_2 + 1));
	if (!str)
		return (0);
	ft_memcpy(str, s1, len_1);
	ft_memcpy(str + len_1, s2, len_2 + 1);
	return (str);
}
