/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbok <jbok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:39:03 by jbok              #+#    #+#             */
/*   Updated: 2023/02/03 20:40:03 by jbok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_split(const char *s, char c)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if ((i == 0 || s[i - 1] == c) && s[i] != c)
			cnt++;
		i++;
	}
	return (cnt);
}

static char	**ft_free_all(char **ptr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		free(ptr[i++]);
	free(ptr);
	return ((void *)0);
}

static char	*ft_strcdup(const char *s, char c)
{
	size_t	size;
	char	*ptr;

	size = 0;
	while (s[size] && s[size] != c)
		size++;
	ptr = malloc_check(sizeof(char) * (size + 1));
	ft_memcpy(ptr, s, size);
	ptr[size] = 0;
	return (ptr);
}

char	**ft_split(const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	**ptr;

	if (!s)
		return (0);
	size = ft_count_split(s, c);
	ptr = malloc_check(sizeof(char *) * (size + 1));
	i = 0;
	j = 0;
	while (s[i])
	{
		if ((i == 0 || s[i - 1] == c) && s[i] != c)
		{
			ptr[j++] = ft_strcdup(s + i, c);
			if (!ptr[j - 1])
				return (ft_free_all(ptr, j - 1));
		}
		i++;
	}
	ptr[j] = 0;
	return (ptr);
}
