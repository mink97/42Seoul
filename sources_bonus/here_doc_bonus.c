/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 09:49:25 by mingkang          #+#    #+#             */
/*   Updated: 2023/01/04 21:21:55 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	make_here_doc(char *limiter)
{
	int		here_fd;
	char	*line;

	here_fd = open("/tmp/here_doc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	write(1, "heredoc> ", 9);
	line = get_next_line(0);
	while (line != NULL && ft_strncmp(line, limiter, ft_strlen(limiter)) != 0)
	{
		ft_putstr_fd(line, here_fd);
		write(1, "heredoc> ", 9);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	close(here_fd);
}
