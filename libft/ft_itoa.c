/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbok <jbok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:23:56 by jbok              #+#    #+#             */
/*   Updated: 2023/02/03 20:37:28 by jbok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intlen(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

size_t	ft_uintlen(unsigned int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*ptr;

	size = ft_intlen(n);
	ptr = malloc_check(sizeof(char) * size + 1);
	ptr[size] = 0;
	if (n == 0)
		ptr[0] = '0';
	if (n < 0)
		ptr[0] = '-';
	while (n)
	{
		ptr[--size] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	return (ptr);
}

char	*ft_uitoa(unsigned int n)
{
	int		size;
	char	*ptr;

	size = ft_uintlen(n);
	ptr = malloc_check(sizeof(char) * size + 1);
	ptr[size] = 0;
	if (n == 0)
		ptr[0] = '0';
	while (n)
	{
		ptr[--size] = n % 10 + '0';
		n /= 10;
	}
	return (ptr);
}
