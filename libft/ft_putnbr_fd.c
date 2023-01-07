/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:33:17 by mingkang          #+#    #+#             */
/*   Updated: 2022/11/12 09:29:44 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	int		q;
	int		r;
	char	ch;

	q = n / 10;
	r = n % 10;
	if (n < 0)
	{
		write(fd, "-", 1);
		q *= -1;
		r *= -1;
	}
	if (q > 0)
		ft_putnbr_fd(q, fd);
	ch = r + '0';
	write(fd, &ch, 1);
}
