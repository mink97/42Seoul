/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:29:09 by mingkang          #+#    #+#             */
/*   Updated: 2022/12/23 16:23:51 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	char	neg;
	int		num;

	i = 0;
	neg = 0;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (neg & 1)
		num *= -1;
	return (num);
}

int	find_idx(char *str, char to_find)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == to_find)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base, int base_n)
{
	int	mn;
	int	num;
	int	n;

	num = 0;
	if (!str)
		return (0);
	mn = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			mn *= -1;
		str++;
	}
	while (*str)
	{
		n = find_idx(base, ft_toupper(*str));
		if (n < 0)
			break ;
		num = num * base_n + n;
		str++;
	}
	return (num * mn);
}
