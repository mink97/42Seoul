/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 10:57:31 by mingkang          #+#    #+#             */
/*   Updated: 2022/12/24 13:02:55 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < SRCN_WDT && y >= 0 && y < SRCN_HGT)
	{
		dst = data->addr + (y * data->size_line + x * (data->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

static void	get_variation(t_point *s, t_point *f, int *variation)
{
	if (s->x > f->x)
		variation[0] = -1;
	else
		variation[0] = 1;
	if (s->y > f->y)
		variation[1] = -1;
	else
		variation[1] = 1;
}

static void	draw_line(t_point *s, t_point *f, t_data *data)
{
	const int	wdt_hgt[2] = {absl(f->x - s->x), absl(f->y - s->y)};
	int			variation[2];
	int			dsc[2];
	t_point		cur;

	cur = *s;
	get_variation(s, f, variation);
	dsc[1] = 2 * wdt_hgt[0] - 2 * wdt_hgt[1];
	while (cur.x != f->x || cur.y != f->y)
	{
		put_pixel(data, cur.x, cur.y, get_color(cur, *s, *f, wdt_hgt));
		dsc[0] = dsc[1];
		if (dsc[0] < wdt_hgt[0])
		{
			dsc[1] += 2 * wdt_hgt[0];
			cur.y += variation[1];
		}
		if (dsc[0] > -wdt_hgt[1])
		{
			dsc[1] -= 2 * wdt_hgt[1];
			cur.x += variation[0];
		}
	}
	free(s);
	free(f);
}

static void	draw_background(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < SRCN_HGT)
	{
		x = -1;
		while (++x < SRCN_WDT)
		{
			if (data->map->bg_color != 0)
				put_pixel(data, x, y, data->map->bg_color);
			else
				put_pixel(data, x, y, create_trgb(0, y * 255 / SRCN_WDT, \
							y * 255 / SRCN_WDT, y * 255 / SRCN_WDT));
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
}

void	draw_map(t_data *data)
{
	int		x;
	int		y;
	int		i;
	t_point	*addr;

	draw_background(data);
	addr = data->map->nodes;
	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
			i = y * data->map->width + x;
			if (x < data->map->width - 1)
				draw_line(get_vertex(&addr[i], data), \
				get_vertex(&addr[i + 1], data), data);
			if (y < data->map->height - 1)
				draw_line(get_vertex(&addr[i], data), \
				get_vertex(&addr[i + data->map->width], data), data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
}
