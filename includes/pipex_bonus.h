/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 10:04:43 by mingkang          #+#    #+#             */
/*   Updated: 2023/01/04 21:26:03 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include <unistd.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# define TRUE 1
# define FALSE 0

typedef struct s_cmd
{
	char	*path;
	char	**argv;
}	t_cmd;

typedef struct s_cmd_lst
{
	int		is_error;
	t_cmd	*cmd_arr;
	char	**envp;
}	t_cmd_lst;

/*
** utils.c
*/
void	ft_error(char *str);
void	free_cmd_lst(t_cmd_lst *cmd_lst, int cnt);

/*
** ft_split.c
*/
char	**quatation_split(char const *s, char c);

/*
** parse_cmd.c
*/
t_cmd	*init_cmd(int argc, char **argv, char **envp);

/*
** here_doc.c
*/
void	make_here_doc(char *limiter);

#endif
