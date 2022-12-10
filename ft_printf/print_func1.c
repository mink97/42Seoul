/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:02:20 by mingkang          #+#    #+#             */
/*   Updated: 2022/11/29 14:03:15 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(long long num, int base, int flag, int *len)
{
	const char	*hex = "0123456789abcdef";
	const char	*upper_hex = "0123456789ABCDEF";
	int			test;

	test = 1;
	if (*len != -1)
	{
		if (num >= base && test == 1)
		{
			ft_putnbr_base(num / base, base, flag, len);
			ft_putnbr_base(num % base, base, flag, len);
		}
		else if (test == 1)
		{
			if (base == 10 || flag == T_LOWER)
				test = write(1, hex + num, 1);
			else
				test = write(1, upper_hex + num, 1);
			(*len)++;
		}
		if (test != 1)
			*len = -1;
	}
}

int	print_int(int num)
{
	long long	n;
	int			len;

	len = 0;
	n = (long long)num;
	if (n < 0)
	{
		n *= -1;
		if (write(1, "-", 1) != 1)
			return (-1);
		len++;
	}
	ft_putnbr_base(n, 10, 0, &len);
	return (len);
}

int	print_uint(unsigned int num)
{
	int	len;

	len = 0;
	ft_putnbr_base((long long)num, 10, 0, &len);
	return (len);
}

int	print_hex(unsigned int num, int flag)
{
	int	len;

	len = 0;
	ft_putnbr_base((long long)num, 16, flag, &len);
	return (len);
}

int	print_per(void)
{
	if (write(1, "%%", 1) != 1)
		return (-1);
	return (1);
}
