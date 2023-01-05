/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 10:57:28 by mingkang          #+#    #+#             */
/*   Updated: 2022/12/24 17:55:11 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	exit_hook(void *vars)
{
	t_data	*data;

	data = (t_data *)vars;
	mlx_destroy_image(data->mlx_ptr, data->img);
	write(1, "\033[0;94m|quit fdf|\n\033[0;0m", 24);
	exit(0);
}

static void	rotate_axis(int keycode, t_data *data)
{
	if (keycode == K_CODE_Q)
		data->cam->gamma += 0.1;
	else if (keycode == K_CODE_W)
		data->cam->gamma -= 0.1;
	else if (keycode == K_CODE_A)
		data->cam->beta += 0.1;
	else if (keycode == K_CODE_S)
		data->cam->beta -= 0.1;
	else if (keycode == K_CODE_Z)
		data->cam->alpha += 0.1;
	else if (keycode == K_CODE_X)
		data->cam->alpha -= 0.1;
}

int	key_press(int keycode, void *vars)
{
	t_data			*data;
	const t_color	colors[6] = {GRAY, SKY_BLUE, NVJ_WHITE, CORAL, 0, BLACK};

	data = (t_data *)vars;
	if (keycode == K_SHIFT)
		data->handle->shift_hold = TRUE;
	else if (keycode == K_CODE_P || keycode == K_CODE_I || keycode == K_CODE_O)
		set_camera(keycode, data);
	else if (keycode == K_CODE_Q || keycode == K_CODE_W || keycode == K_CODE_A \
		|| keycode == K_CODE_S || keycode == K_CODE_Z || keycode == K_CODE_X)
		rotate_axis(keycode, data);
	else if (keycode == K_CODE_ZU && data->cam->z_factor > 1)
		data->cam->z_factor--;
	else if (keycode == K_CODE_ZD)
		data->cam->z_factor++;
	else if (keycode == K_CODE_1 || keycode == K_CODE_2 || keycode == K_CODE_3 \
		|| keycode == K_CODE_4 || keycode == K_CODE_5 || keycode == K_CODE_6)
		data->map->bg_color = colors[keycode - 18];
	else if (keycode == K_ESC)
		exit_hook(vars);
	draw_map(data);
	return (0);
}

int	key_release(int keycode, void *vars)
{
	t_data	*data;

	(void)keycode;
	data = (t_data *)vars;
	data->handle->shift_hold = 0;
	draw_map(data);
	return (0);
}

void	cntl_map(t_data *data)
{
	mlx_hook(data->win_ptr, ON_KEYDOWN, 0, key_press, data);
	mlx_hook(data->win_ptr, ON_KEYUP, 0, key_release, data);
	mlx_hook(data->win_ptr, ON_MOUSEDOWN, 0, mouse_press, data);
	mlx_hook(data->win_ptr, ON_MOUSEUP, 0, mouse_release, data);
	mlx_hook(data->win_ptr, ON_MOUSEMOVE, 0, mouse_move, data);
	mlx_hook(data->win_ptr, ON_DESTROY, 0, exit_hook, data);
}
