/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 07:53:42 by mingkang          #+#    #+#             */
/*   Updated: 2022/12/27 13:49:03 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	char	*str;
	t_data	*data;

	if (argc != 2)
		ft_error("error - only 1 argument please");
	str = ft_strrchr(argv[1], '.');
	if (str == NULL || ft_strncmp(str, ".fdf", 5) != 0)
		ft_error("only .fdf file can open");
	data = init_mlx(argv);
	draw_map(data);
	cntl_map(data);
	mlx_loop(data->mlx_ptr);
}
