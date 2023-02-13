/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbok <jbok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:21:45 by jbok              #+#    #+#             */
/*   Updated: 2023/02/03 20:38:04 by jbok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_nothing(va_list *ap, t_arg *arg)
{
	(void)ap;
	(void)arg;
}

void	ft_make_str(va_list *ap, t_arg *arg)
{
	const static t_f	f[10] = {ft_nothing, ft_nothing, ft_nothing, \
	ft_format_char, ft_format_str, ft_format_ptr, ft_format_sint, \
	ft_format_uint, ft_format_lhex, ft_format_uhex};

	(f[arg->type])(ap, arg);
}

void	ft_format_char(va_list *ap, t_arg *arg)
{
	if (!(arg->width))
		arg->width += 1;
	arg->prt_len = arg->width;
	arg->content = malloc_check(sizeof(char) * arg->width);
	while (--(arg->width))
		((char *)(arg->content))[arg->width] = ' ';
	if (arg->flag & FT_FLAG_HASH)
		((char *)(arg->content))[0] = va_arg(*ap, int);
	else
		((char *)(arg->content))[arg->prt_len - 1] = va_arg(*ap, int);
}

void	ft_format_str(va_list *ap, t_arg *arg)
{
	arg->content = va_arg(*ap, char *);
	if (arg->content)
		arg->prt_len = ft_strlen(arg->content);
	else
		arg->prt_len = 6;
}

void	ft_format_ptr(va_list *ap, t_arg *arg)
{
	void	*ptr;

	ptr = va_arg(*ap, void *);
	arg->prt_len = ft_hexlen((size_t)ptr) + 2;
	arg->content = ft_ptrtoa(ptr);
}
