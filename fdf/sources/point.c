/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 10:57:39 by mingkang          #+#    #+#             */
/*   Updated: 2022/12/24 13:27:24 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_x(t_point *point, double gamma)
{
	int	prev_y;
	int	prev_z;

	prev_y = point->y;
	prev_z = point->z;
	point->y = prev_y * cos(gamma) + prev_z * sin(gamma);
	point->z = -prev_y * sin(gamma) + prev_z * cos(gamma);
}

static void	rotate_y(t_point *point, double beta)
{
	int	prev_x;
	int	prev_z;

	prev_x = point->x;
	prev_z = point->z;
	point->x = prev_x * cos(beta) + prev_z * sin(beta);
	point->z = -prev_x * sin(beta) + prev_z * cos(beta);
}

static void	rotate_z(t_point *point, double alpha)
{
	int	prev_x;
	int	prev_y;

	prev_x = point->x;
	prev_y = point->y;
	point->x = prev_x * cos(alpha) - prev_y * sin(alpha);
	point->y = prev_x * sin(alpha) + prev_y * cos(alpha);
}

static void	change_projection(t_point *point, t_prjc prjc)
{
	int	prev_x;
	int	prev_y;

	prev_x = point->x;
	prev_y = point->y;
	if (prjc == ISOMETRIC)
	{
		point->x = (prev_x - prev_y) * cos(0.4637);
		point->y = (prev_x + prev_y) * sin(0.4637) - point->z;
	}
	else if (prjc == OBLIQUE)
	{
		point->x = prev_x - prev_y * cos(0.785);
		point->y = prev_y * sin(0.785) - point->z;
	}
}

t_point	*get_vertex(t_point *point, t_data *data)
{
	t_point	*tmp;

	tmp = malloc(sizeof(t_point) * 1);
	tmp->x = point->x - data->map->width / 2;
	tmp->y = point->y - data->map->height / 2;
	tmp->z = point->z * data->cam->zoom / data->cam->z_factor;
	tmp->color = point->color;
	tmp->x *= data->cam->zoom;
	tmp->y *= data->cam->zoom;
	rotate_z(tmp, data->cam->alpha);
	rotate_x(tmp, data->cam->gamma);
	rotate_y(tmp, data->cam->beta);
	if (data->cam->prjc != PARALLEL)
	{
		change_projection(tmp, data->cam->prjc);
		tmp->y += SRCN_HGT / 8;
	}
	tmp->x += SRCN_WDT / 2 + data->cam->x_offset;
	tmp->y += SRCN_HGT / 2 + data->cam->y_offset;
	return (tmp);
}
