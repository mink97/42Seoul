/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbok <jbok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 10:15:28 by bok               #+#    #+#             */
/*   Updated: 2023/02/04 15:56:07 by jbok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_punctuation(int c)
{
	if (c == ' ' || c == '<' || c == '>' || c == '|')
		return (1);
	return (0);
}

t_token	*vec_to_token(t_status status, t_vector *vec, char **str)
{
	t_token	*token;

	token = ft_calloc(1, sizeof(t_token));
	token->status = status;
	if (status & PIPE)
		;
	else if (!vec)
	{
		token->status = SYNTAX_ERROR;
		token->str = *str;
	}
	else
	{
		token->str = ft_realloc(vec->content, vec->size, vec->size + 1);
		token->str[vec->size] = 0;
		free(vec);
	}
	return (token);
}

t_token	*del_token(t_token *token)
{
	if (!token)
		return (0);
	if (token->status & FD)
		close(token->fd);
	if (token->status & HEREDOC && token->status & FD)
		unlink(token->str);
	if (token->status & STR)
		free(token->str);
	free(token);
	return (0);
}

t_cmd	*del_cmd(t_cmd *cmd)
{
	size_t	i;

	if (!cmd)
		return (0);
	del_token(cmd->infile);
	del_token(cmd->outfile);
	free(cmd->path);
	i = -1;
	if (cmd->cmd)
		while (cmd->cmd[++i])
			free(cmd->cmd[i]);
	free(cmd->cmd);
	free(cmd);
	return (0);
}

void	dq_to_cmd(t_cmd *cmd)
{
	char	**ret;

	if (!(cmd->cmd_dq))
		return ;
	if (cmd->status & SYNTAX_ERROR || cmd->status & FILE_ERROR)
	{
		while (cmd->cmd_dq->size)
			free(ft_popfront(cmd->cmd_dq));
		free(cmd->cmd_dq);
		ret = 0;
	}
	else
	{
		ret = malloc_check(sizeof(char *) * (cmd->cmd_dq->size + 1));
		ret[cmd->cmd_dq->size] = 0;
		while (cmd->cmd_dq->size)
			ret[cmd->cmd_dq->size] = (ft_popback(cmd->cmd_dq));
		free(cmd->cmd_dq);
	}
	cmd->cmd = ret;
}
