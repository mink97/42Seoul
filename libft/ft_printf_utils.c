/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbok <jbok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:25:12 by jbok              #+#    #+#             */
/*   Updated: 2023/01/30 15:17:45 by jbok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_simple_atoi(const char **str)
{
	int	n;

	n = 0;
	while ('0' <= *(*str) && *(*str) <= '9')
	{
		n = n * 10 + (*(*str)++ - '0');
		if (n < 0)
			return (-1);
	}
	return (n);
}

t_flag	ft_chr_to_type(const char c)
{
	if (c == '-')
		return (FT_FLAG_HYPHEN);
	else if (c == '0')
		return (FT_FLAG_ZERO);
	else if (c == '.')
		return (FT_FLAG_PERIOD);
	else if (c == '#')
		return (FT_FLAG_HASH);
	else if (c == ' ')
		return (FT_FLAG_SPACE);
	else if (c == '+')
		return (FT_FLAG_PLUS);
	else
		return (FT_FLAG_ERROR);
}

ssize_t	ft_putstr(void *ptr)
{
	t_arg	*arg;

	if (!ptr)
		return (-1);
	arg = ptr;
	if (arg->type == PRINTF_STR && arg->content == 0)
		return (write(1, "(null)", 6));
	else
		return (write(1, arg->content, arg->prt_len));
}

void	ft_free_arg(void *ptr)
{
	t_arg	*arg;

	arg = ptr;
	if (!arg)
		return ;
	if (arg->type != PLAIN && arg->type != PRINTF_STR && arg->type != PERCENT \
	&& arg->content)
		free(arg->content);
	free(arg);
}
