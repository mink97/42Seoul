/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:26:08 by mingkang          #+#    #+#             */
/*   Updated: 2023/01/04 21:26:03 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static size_t	word_cnt_a(char *str, char c)
{
	size_t	cnt;

	cnt = 1;
	if (*str == c || *str == 0)
		cnt--;
	while (*str)
	{
		if (*str == '\'')
		{
			str++;
			while (*str != '\'' && *str != 0)
				str++;
			if (*str == 0)
				ft_error("missing '''");
		}
		if (*str == c && *(str + 1) != c && *(str + 1))
			cnt++;
		str++;
	}
	return (cnt);
}

static	size_t	get_len(char **pstr, char c)
{
	size_t	len;

	len = 0;
	if ((*pstr)[len] == '\'')
	{
		while ((*pstr)[++len] != '\'')
			;
		len--;
		(*pstr)++;
	}
	else
	{
		while ((*pstr)[len] && (*pstr)[len] != c)
			len++;
	}
	return (len);
}

static char	*get_part(char **pstr, char c)
{
	char	*part;
	size_t	len;
	size_t	i;

	len = get_len(pstr, c);
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
	if (**pstr == '\'')
		(*pstr)++;
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

char	**quatation_split(char const *s, char c)
{
	size_t			i;
	char			*str;
	char			**sep_strs;

	if (s == 0)
		return (0);
	i = 0;
	str = (char *)s;
	sep_strs = (char **)malloc(sizeof(char *) * (word_cnt_a((char *)s, c) + 1));
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
