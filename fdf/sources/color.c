/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 10:57:24 by mingkang          #+#    #+#             */
/*   Updated: 2022/12/24 12:55:56 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	get_ratio(int cur, int s, int f)
{
	double	ratio;

	if (s == f)
		return (1.0);
	ratio = (double)(cur - s) / (f - s);
	return (ratio);
}

static int	ft_lerp(int s, int f, double ratio)
{
	int	value;

	value = (1 - ratio) * s + ratio * f;
	return (value);
}

int	get_color(t_point cur, t_point s, t_point f, const int *wdt_hgt)
{
	int		color;
	int		red;
	int		green;
	int		blue;
	double	ratio;

	if (cur.color == f.color)
		return (f.color);
	if (wdt_hgt[0] > wdt_hgt[1])
		ratio = get_ratio(cur.x, s.x, f.x);
	else
		ratio = get_ratio(cur.y, s.y, f.y);
	red = ft_lerp(get_r(s.color), get_r(f.color), ratio);
	green = ft_lerp(get_g(s.color), get_g(f.color), ratio);
	blue = ft_lerp(get_b(s.color), get_b(f.color), ratio);
	color = create_trgb(0, red, green, blue);
	return (color);
}
