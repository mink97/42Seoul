/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:39:32 by jbok              #+#    #+#             */
/*   Updated: 2023/02/03 10:49:26 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || \
		c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

static unsigned long	ft_atoi2(const char *str, int sign)
{
	unsigned long	n;

	n = 0;
	while (ft_isdigit(*str))
	{
		if (n > ULONG_MAX / 10 || \
		(n == ULONG_MAX / 10 && (unsigned long)(*str - '0') > ULONG_MAX % 10))
		{
			if (sign)
				return (-1);
			else
				return (0);
		}
		n = n * 10 + *str++ - '0';
	}
	if (sign)
		return (n);
	else
		return (-n);
}

int	ft_atoi(const char *str)
{
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			return ((int)ft_atoi2(str + 1, 0));
		str++;
	}
	return ((int)ft_atoi2(str, 1));
}
