/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 07:49:11 by mingkang          #+#    #+#             */
/*   Updated: 2022/12/24 16:24:42 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

# define SRCN_WDT 1000
# define SRCN_HGT 1000

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef enum e_color
{
	GRAY = 0xCDC9C9,
	SKY_BLUE = 0x6495ED,
	NVJ_WHITE = 0xFFDEAD,
	CORAL = 0xF08080,
	BLACK = 0x1C1C1C
}	t_color;

typedef enum e_handle_key
{
	K_ESC = 53,
	K_SHIFT = 257,
	K_CODE_1 = 18,
	K_CODE_2 = 19,
	K_CODE_3 = 20,
	K_CODE_4 = 21,
	K_CODE_5 = 23,
	K_CODE_6 = 22,
	K_CODE_P = 35,
	K_CODE_O = 31,
	K_CODE_I = 34,
	K_CODE_Q = 12,
	K_CODE_W = 13,
	K_CODE_A = 0,
	K_CODE_S = 1,
	K_CODE_Z = 6,
	K_CODE_X = 7,
	K_CODE_ZU = 30,
	K_CODE_ZD = 33
}	t_handle_key;

typedef enum e_handle_mouse
{
	M_LEFT = 1,
	M_RIGHT = 2,
	M_WHEEL = 3,
	M_WHEEL_UP = 5,
	M_WHEEL_DOWN = 4
}	t_handle_mouse;

typedef enum e_prjc
{
	ISOMETRIC,
	OBLIQUE,
	PARALLEL
}	t_prjc;

enum e_hook
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_DESTROY = 17
};

typedef struct s_handle
{
	int	prev_x;
	int	prev_y;
	int	cur_x;
	int	cur_y;
	int	shift_hold;
	int	wheel_hold;
}	t_handle;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_map
{
	t_point	*nodes;
	t_color	bg_color;
	int		width;
	int		height;
	int		z_max;
}	t_map;

typedef struct s_camera
{
	t_prjc	prjc;
	double	alpha;
	double	beta;
	double	gamma;
	int		x_offset;
	int		y_offset;
	int		zoom;
	int		z_factor;
}	t_camera;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	char		*addr;
	int			bpp;
	int			size_line;
	int			endn;
	t_map		*map;
	t_camera	*cam;
	t_handle	*handle;
}	t_data;

/*
** utils.c
*/
int		create_trgb(int t, int r, int g, int b);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
void	ft_error(char *str);

/*
** color.c
*/
int		get_color(t_point cur, t_point s, t_point f, const int *wdt_hgt);

/*
** common.c
*/
int		absl(int num);
int		get_max(int a, int b);
int		get_min(int a, int b);

/*
** control_mouse.c
*/
int		mouse_move(int x, int y, void *vars);
int		mouse_press(int button, int x, int y, void *vars);
int		mouse_release(int button, int x, int y, void *vars);

/*
** control_key.c
*/
int		key_press(int keycode, void *vars);
int		key_release(int keycode, void *vars);
void	cntl_map(t_data *data);

/*
** draw.c
*/
void	draw_map(t_data *data);

/*
** init_map.c
*/
t_map	*init_map(char **argv);

/*
** point.c
*/
t_point	*get_vertex(t_point *point, t_data *data);

/*
** init.c
*/
void	set_camera(int keycode, t_data *data);
t_data	*init_mlx(char **argv);

#endif
