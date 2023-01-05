/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:56:33 by mingkang          #+#    #+#             */
/*   Updated: 2022/12/26 10:34:15 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	absl(int num)
{
	if (num < 0)
		return (-num);
	else
		return (num);
}

int	get_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	get_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

void	ft_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}
