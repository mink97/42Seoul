/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:30:09 by mingkang          #+#    #+#             */
/*   Updated: 2022/11/29 14:17:26 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_arg_type(va_list ap, const char *str)
{
	int	len;

	if (*str == 'c')
		len = print_char((char)va_arg(ap, int));
	else if (*str == 's')
		len = print_str(va_arg(ap, char *));
	else if (*str == 'p')
		len = print_addr(va_arg(ap, void *));
	else if (*str == 'd' || *str == 'i')
		len = print_int(va_arg(ap, int));
	else if (*str == 'u')
		len = print_uint(va_arg(ap, unsigned int));
	else if (*str == 'x')
		len = print_hex(va_arg(ap, unsigned int), T_LOWER);
	else if (*str == 'X')
		len = print_hex(va_arg(ap, unsigned int), T_UPPER);
	else if (*str == '%')
		len = print_per();
	else
		len = -1;
	return (len);
}

static int	parse_str(va_list ap, const char *format, int len)
{
	int	i;
	int	tmp;

	i = 0;
	while (format[i] != 0)
	{
		if (format[i] != '%')
		{
			tmp = 0;
			while (format[i + tmp] != 0 && format[i + tmp] != '%')
				tmp++;
			if (write(1, format + i, tmp) != tmp)
				return (-1);
			i += tmp;
		}
		else
		{
			tmp = check_arg_type(ap, &format[++i]);
			if (tmp == -1)
				return (-1);
			i++;
		}
		len += tmp;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, format);
	len = parse_str(ap, format, len);
	va_end(ap);
	return (len);
}
