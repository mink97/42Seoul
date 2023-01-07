/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 07:47:17 by mingkang          #+#    #+#             */
/*   Updated: 2022/12/21 10:11:16 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_n_strchr(char const *s1, char const *set, size_t i, char rev)
{
	char	*str;

	str = (char *)s1;
	while (i + 1 != 0 && str[i])
	{
		if (ft_strchr(set, str[i]) == 0)
			return (str + i);
		if (rev == 0)
			i++;
		else
		{
			if (i == 0)
				break ;
			i--;
		}
	}
	return (str + i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*start;
	char	*end;
	char	*str;

	if (s1 == 0)
		return (0);
	start = ft_n_strchr(s1, set, 0, 0);
	end = ft_n_strchr(s1, set, ft_strlen(s1) - 1, 1);
	if (end < start)
		len = 0;
	else
		len = end - start + 1;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	ft_strlcpy(str, start, len + 1);
	return (str);
}
