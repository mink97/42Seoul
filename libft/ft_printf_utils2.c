/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbok <jbok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:33:29 by jbok              #+#    #+#             */
/*   Updated: 2023/02/03 20:39:54 by jbok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_hexlen(size_t n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		len++;
		n /= 16;
	}
	return (len);
}

char	*ft_ptrtoa(void *ptr)
{
	size_t	len;
	size_t	n;
	char	*str;

	n = (size_t)ptr;
	len = ft_hexlen(n) + 2;
	str = malloc_check(sizeof(char) * len);
	str[0] = '0';
	str[1] = 'x';
	if (!n)
		str[2] = "0123456789abcdef"[0];
	while (n)
	{
		str[--len] = "0123456789abcdef"[n % 16];
		n /= 16;
	}
	return (str);
}

char	*ft_lhextoa(unsigned int n)
{
	size_t	len;
	char	*str;

	len = ft_hexlen(n);
	str = malloc_check(sizeof(char) * len);
	if (!n)
		str[0] = "0123456789abcdef"[0];
	while (n)
	{
		str[--len] = "0123456789abcdef"[n % 16];
		n /= 16;
	}
	return (str);
}

char	*ft_uhextoa(unsigned int n)
{
	size_t	len;
	char	*str;

	len = ft_hexlen(n);
	str = malloc(sizeof(char) * len);
	if (!str)
		return (0);
	if (!n)
		str[0] = "0123456789ABCDEF"[n];
	while (n)
	{
		str[--len] = "0123456789ABCDEF"[n % 16];
		n /= 16;
	}
	return (str);
}
