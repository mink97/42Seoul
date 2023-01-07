/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:34:47 by mingkang          #+#    #+#             */
/*   Updated: 2023/01/04 20:39:09 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	free_cmd_lst(t_cmd_lst *cmd_lst, int cnt)
{
	int		i;
	t_cmd	*cmd_arr;

	cmd_arr = cmd_lst->cmd_arr;
	i = 0;
	while (i < cnt)
	{
		free_strs(cmd_arr[i].argv);
		cmd_arr[i].argv = NULL;
		free(cmd_arr[i].path);
		i++;
	}
	free(cmd_arr);
	free(cmd_lst);
}
