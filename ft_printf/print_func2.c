/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:03:31 by mingkang          #+#    #+#             */
/*   Updated: 2022/12/13 12:01:22 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char ch)
{
	int	n;

	n = write(1, &ch, 1);
	if (n != 1)
		return (-1);
	return (1);
}

int	ft_strlen(char *str)
{
	long long	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
		if (i >= 2147483647)
			return (-1);
	}
	return (i);
}

int	print_str(char *str)
{
	int	len;

	if (str == 0)
	{
		if (write(1, "(null)", 6) != 6)
			return (-1);
		return (6);
	}
	len = ft_strlen(str);
	if (len == -1 || write(1, str, len) != len)
		return (-1);
	return (len);
}

void	ft_putnbr_base_u(unsigned long long num, int base, int *len)
{
	const char	*low_hex = "0123456789abcdef";
	int			test;

	test = 1;
	if (*len != -1)
	{
		if (num >= (unsigned)base)
		{
			ft_putnbr_base_u(num / base, base, len);
			ft_putnbr_base_u(num % base, base, len);
		}
		else
		{
			test = write(1, low_hex + num, 1);
			(*len)++;
		}
		if (test != 1)
			*len = -1;
	}
}

int	print_addr(void *ptr)
{
	int	len;

	len = 2;
	if (write(1, "0x", 2) != 2)
		return (-1);
	ft_putnbr_base_u((unsigned long long)ptr, 16, &len);
	return (len);
}
