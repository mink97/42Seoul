/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:04:53 by mingkang          #+#    #+#             */
/*   Updated: 2022/11/12 09:12:22 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_length(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long long	num;
	int			len;
	char		*str;

	num = (long long)n;
	len = get_length(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	str[len--] = '\0';
	if (num == 0)
		str[len] = '0';
	while (num)
	{
		str[len--] = num % 10 + '0';
		num /= 10;
	}
	return (str);
}
