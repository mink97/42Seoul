/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbok <jbok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:24:18 by jbok              #+#    #+#             */
/*   Updated: 2022/11/21 19:33:59 by jbok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format_sint(va_list *ap, t_arg *arg)
{
	int	n;

	n = va_arg(*ap, int);
	arg->prt_len = ft_intlen(n);
	arg->content = ft_itoa(n);
}

void	ft_format_uint(va_list *ap, t_arg *arg)
{
	int	n;

	n = va_arg(*ap, int);
	arg->prt_len = ft_uintlen(n);
	arg->content = ft_uitoa(n);
}

void	ft_format_lhex(va_list *ap, t_arg *arg)
{
	unsigned int	n;

	n = va_arg(*ap, unsigned int);
	arg->prt_len = ft_hexlen(n);
	arg->content = ft_lhextoa(n);
}

void	ft_format_uhex(va_list *ap, t_arg *arg)
{
	unsigned int	n;

	n = va_arg(*ap, unsigned int);
	arg->prt_len = ft_hexlen(n);
	arg->content = ft_uhextoa(n);
}
