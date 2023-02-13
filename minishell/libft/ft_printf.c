/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbok <jbok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 08:15:19 by jbok              #+#    #+#             */
/*   Updated: 2023/01/30 15:15:38 by jbok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arg	*ft_get_arg(const char **str, va_list *ap, ssize_t *count)
{
	t_arg	*arg;

	arg = ft_calloc(1, sizeof(t_arg));
	if (!arg)
	{
		*count = -1;
		return (0);
	}
	ft_parse_str(str, arg);
	if (arg->type == FT_ERROR)
		*count = -1;
	else
		ft_make_str(ap, arg);
	if (arg->content == 0 && arg->type != PRINTF_STR)
	{
		*count = -1;
		free(arg);
		arg = 0;
	}
	return (arg);
}

int	ft_printf2(const char **str, va_list *ap, ssize_t *count)
{
	t_arg	*tmp;

	while (*(*str))
	{
		tmp = ft_get_arg(str, ap, count);
		if (!tmp || *count + tmp->prt_len > 2147483647)
		{
			ft_free_arg(tmp);
			*count = -1;
			return (-1);
		}
		if (tmp->prt_len != ft_putstr(tmp))
			*count = -1;
		else
			*count += tmp->prt_len;
		ft_free_arg(tmp);
		if (*count == -1)
			break ;
	}
	return (*count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	ssize_t	count;

	va_start(ap, str);
	if (!str)
		return (-1);
	if (!(*str))
		return (0);
	count = 0;
	ft_printf2(&str, &ap, &count);
	va_end(ap);
	return (count);
}
