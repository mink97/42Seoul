/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbok <jbok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:34:33 by jbok              #+#    #+#             */
/*   Updated: 2023/01/30 15:15:05 by jbok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_str3(const char c, t_arg *arg)
{
	if (c == 'c')
		arg->type = CHAR;
	else if (c == 's')
		arg->type = PRINTF_STR;
	else if (c == 'p')
		arg->type = PTR;
	else if (c == 'd' || c == 'i')
		arg->type = SINT;
	else if (c == 'u')
		arg->type = UINT;
	else if (c == 'x')
		arg->type = LHEX;
	else if (c == 'X')
		arg->type = UHEX;
}

void	ft_parse_str2(const char **str, t_arg *arg)
{
	(*str) += 1;
	while (*(*str) == '-' || *(*str) == '0' || *(*str) == '#' \
	|| *(*str) == ' ' || *(*str) == '+')
		arg->flag |= ft_chr_to_type(*(*str)++);
	arg->width = ft_simple_atoi(str);
	if (*(*str) == '.')
	{
		arg->flag |= ft_chr_to_type(*(*str)++);
		arg->precision = ft_simple_atoi(str);
	}
	if (*(*str) == 'c' || *(*str) == 's' || *(*str) == 'p' || *(*str) == 'd' \
	|| *(*str) == 'i' || *(*str) == 'u' || *(*str) == 'x' || *(*str) == 'X')
	{
		ft_parse_str3(*(*str), arg);
		*str += 1;
	}
	else
		arg->type = FT_ERROR;
}

void	ft_parse_str(const char **str, t_arg *arg)
{
	size_t	len;

	len = 0;
	if (*(*str) != '%')
	{
		arg->content = (char *)*str;
		while (*(*str) && *(*str) != '%')
		{
			(*str)++;
			len++;
		}
		arg->flag = 0;
		arg->type = PLAIN;
		arg->prt_len = len;
	}
	else if (*(*str + 1) == '%')
	{
		arg->content = (char *)*str;
		arg->flag = 0;
		arg->type = PERCENT;
		arg->prt_len = 1;
		(*str) += 2;
	}
	else
		ft_parse_str2(str, arg);
}
