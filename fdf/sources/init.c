/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 10:57:36 by mingkang          #+#    #+#             */
/*   Updated: 2022/12/24 13:42:58 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_camera(int keycode, t_data *data)
{
	if (keycode == K_CODE_P)
		data->cam->prjc = PARALLEL;
	else if (keycode == K_CODE_O)
		data->cam->prjc = OBLIQUE;
	else if (keycode == K_CODE_I)
		data->cam->prjc = ISOMETRIC;
	data->cam->alpha = 0;
	data->cam->beta = 0;
	data->cam->gamma = 0;
	data->cam->x_offset = 0;
	data->cam->y_offset = 0;
	data->cam->zoom = \
	get_min((SRCN_WDT) / data->map->width, (SRCN_HGT) / data->map->height) / 2;
	data->cam->z_factor = get_max(data->map->z_max / data->map->height * 2, 1);
}

t_data	*init_mlx(char **argv)
{
	t_data		*data;

	data = malloc(sizeof(t_data) * 1);
	if (data == NULL)
		ft_error("error - failed to malloc data");
	data->mlx_ptr = mlx_init();
	data->win_ptr = \
		mlx_new_window(data->mlx_ptr, SRCN_WDT, SRCN_HGT, "42seoul-fdf");
	data->img = mlx_new_image(data->mlx_ptr, SRCN_WDT, SRCN_HGT);
	if (data->mlx_ptr == NULL || data->win_ptr == NULL || data->img == NULL)
		ft_error("error - failed to initialize mlx");
	data->addr = mlx_get_data_addr(data->img, \
		&(data->bpp), &(data->size_line), &(data->endn));
	data->map = init_map(argv);
	data->cam = malloc(sizeof(t_camera) * 1);
	if (data->cam == NULL)
		ft_error("error - failed to malloc camera");
	set_camera(K_CODE_I, data);
	data->handle = malloc(sizeof(t_handle) * 1);
	if (data->handle == NULL)
		ft_error("error - failed to malloc handle");
	return (data);
}
