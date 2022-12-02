/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:26:08 by mingkang          #+#    #+#             */
/*   Updated: 2022/12/01 15:58:18 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	word_cnt(char *str, char c)
{
	size_t	cnt;

	cnt = 1;
	if (*str == c || *str == 0)
		cnt--;
	while (*str)
	{
		if (*str == c && *(str + 1) != c && *(str + 1))
			cnt++;
		str++;
	}
	return (cnt);
}

static char	*get_part(char **pstr, char c)
{
	char	*part;
	size_t	len;
	size_t	i;

	len = 0;
	while ((*pstr)[len] && (*pstr)[len] != c)
		len++;
	part = (char *)malloc(sizeof(char) * (len + 1));
	if (!part)
		return (0);
	i = 0;
	while (i < len)
	{
		part[i++] = **pstr;
		(*pstr)++;
	}
	part[i] = 0;
	return (part);
}

static int	check_free(char **strs, size_t n)
{
	if (strs[n] == 0)
	{
		while (n-- > 0)
			free(strs[n]);
		free(strs);
		return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t			i;
	char			*str;
	char			**sep_strs;

	if (s == 0)
		return (0);
	i = 0;
	str = (char *)s;
	sep_strs = (char **)malloc(sizeof(char *) * (word_cnt((char *)s, c) + 1));
	if (sep_strs == 0)
		return (0);
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str && *str != c)
		{
			sep_strs[i] = get_part(&str, c);
			if (check_free(sep_strs, i++) == 0)
				return (0);
		}
	}
	sep_strs[i] = 0;
	return (sep_strs);
}
