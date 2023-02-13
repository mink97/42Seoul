/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_make_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:14:47 by bok               #+#    #+#             */
/*   Updated: 2023/02/03 19:30:03 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_token(t_cmd *cmd, t_token *token);
static void	open_token(t_token *token);
static void	clear_cmd(t_cmd *cmd);

t_cmd	*make_cmd(t_deque *tokens)
{
	t_cmd	*cmd;
	t_token	*token;

	cmd = ft_calloc(1, sizeof(t_cmd));
	cmd->cmd_dq = ft_calloc(1, sizeof(t_deque));
	while (tokens->size)
	{
		token = ft_popfront(tokens);
		if (cmd->status & FILE_ERROR && !(token->status & PIPE))
			del_token(token);
		else if (token->status & PIPE)
		{
			del_token(token);
			break ;
		}
		else
			set_token(cmd, token);
	}
	dq_to_cmd(cmd);
	return (cmd);
}

static void	set_token(t_cmd *cmd, t_token *token)
{
	if (token->status & CMD)
		ft_pushback(cmd->cmd_dq, token->str);
	else if (token->status & HEREDOC)
		make_heredoc(token);
	else
		open_token(token);
	if (token->status & FILE_ERROR)
	{
		del_token(token);
		clear_cmd(cmd);
		cmd->status |= FILE_ERROR;
	}
	else if (token->status & (INFILE | HEREDOC))
	{
		del_token(cmd->infile);
		cmd->infile = token;
	}
	else if (token->status & (OUTFILE | APPEND))
	{
		del_token(cmd->outfile);
		cmd->outfile = token;
	}
	else
		free(token);
}

static void	open_token(t_token *token)
{
	if (token->status & INFILE)
		token->fd = open(token->str, O_RDONLY);
	else if (token->status & OUTFILE)
		token->fd = open(token->str, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (token->status & APPEND)
		token->fd = open(token->str, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (token->fd < 0)
	{
		ft_putstr_fd("minishell: ", 2);
		perror(token->str);
		set_exitcode(1);
		token->status |= FILE_ERROR;
	}
	else
		token->status |= FD;
}

static void	clear_cmd(t_cmd *cmd)
{
	cmd->status = 0;
	cmd->infile = del_token(cmd->infile);
	cmd->outfile = del_token(cmd->outfile);
	while (cmd->cmd_dq->size)
		free(ft_popfront(cmd->cmd_dq));
	free(cmd->cmd_dq);
	cmd->cmd_dq = 0;
}
