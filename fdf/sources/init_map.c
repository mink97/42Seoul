/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 12:37:17 by mingkang          #+#    #+#             */
/*   Updated: 2022/12/26 10:40:10 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	parse_map(char **argv, t_map *map, t_list **lst)
{
	int		i;
	int		fd;
	char	*line;
	char	**strs;
	t_list	*new;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error("error - failed to open file");
	line = get_next_line(fd);
	map->width = word_cnt(line, ' ');
	while (line > 0)
	{
		strs = ft_split(line, ' ');
		new = ft_lstnew(strs);
		ft_lstadd_back(lst, new);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	map->height = i;
	close(fd);
}

static void	fill_node(t_point *node, char **strs, int x, int y)
{
	char	**buf;

	buf = ft_split(*strs, ',');
	node->x = x;
	node->y = y;
	node->z = ft_atoi(buf[0]);
	if (buf[1])
		node->color = ft_atoi_base(&buf[1][2], "0123456789ABCDEF", 16);
	else
		node->color = 0xffffff;
	free_strs(buf);
}

static void	read_map(t_map *map, t_list **lst)
{
	int		i;
	int		j;
	int		k;
	char	**strs;
	t_list	*tmp;

	map->z_max = 0;
	tmp = *lst;
	k = 0;
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		strs = tmp->content;
		while (++j < map->width)
		{
			fill_node(map->nodes + (k++), strs + j, j, i);
			if ((map->nodes)[k - 1].z > map->z_max)
				map->z_max = (map->nodes)[k - 1].z;
		}
		tmp = tmp->next;
	}
	ft_lstclear(lst, free_strs);
}

t_map	*init_map(char **argv)
{
	t_map	*map;
	t_list	*lst;

	map = malloc(sizeof(t_map) * 1);
	if (map == NULL)
		ft_error("error - failed to malloc map");
	lst = NULL;
	parse_map(argv, map, &lst);
	map->nodes = malloc(sizeof(t_point) * map->width * map->height);
	if (map->nodes == NULL)
		ft_error("error - failed to malloc map->nodes");
	read_map(map, &lst);
	map->bg_color = GRAY;
	return (map);
}
