/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbok <jbok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:56:32 by jbok              #+#    #+#             */
/*   Updated: 2022/11/14 09:27:56 by jbok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbrlong_fd_rec(long n, int fd)
{
	if (n < 10)
	{
		ft_putchar_fd(n + '0', fd);
	}
	else
	{
		ft_putnbrlong_fd_rec(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	return ;
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbrlong_fd_rec((long)n * -1, fd);
	}
	else
		ft_putnbrlong_fd_rec((long)n, fd);
	return ;
}
