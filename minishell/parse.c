/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbok <jbok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:54:32 by jbok              #+#    #+#             */
/*   Updated: 2023/02/04 20:56:17 by jbok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_deque	*make_tokens(char *str);
static t_deque	*make_cmds(t_deque *tokens);
static void		prt_syntax_err(t_token *token);

t_deque	*parse(char *str)
{
	t_deque	*dq;

	while (*str && *str == ' ')
		str++;
	dq = make_tokens(str);
	if (!dq)
		return (0);
	dq = make_cmds(dq);
	return (dq);
}

static t_deque	*make_cmds(t_deque *tokens)
{
	t_deque	*cmds;
	t_cmd	*cmd;

	cmds = ft_calloc(1, sizeof(t_deque));
	while (tokens->size)
	{
		cmd = make_cmd(tokens);
		ft_pushback(cmds, cmd);
		if (cmd->status & SYNTAX_ERROR)
			break ;
	}
	free(tokens);
	return (cmds);
}

static t_deque	*make_tokens(char *str)
{
	t_deque	*tokens;
	t_token	*token;

	tokens = ft_calloc(1, sizeof(t_deque));
	while (*str)
	{
		token = make_token(&str);
		if ((token->status & SYNTAX_ERROR) || \
		((token->status & PIPE) && tokens->size == 0) || \
		(tokens->size && (((t_token *)((tokens->rear)->content))->status & \
		PIPE) && token->status & PIPE))
		{
			while (tokens->size)
				del_token(ft_popfront(tokens));
			prt_syntax_err(token);
			del_token(token);
			free(tokens);
			return (0);
		}
		else
			ft_pushback(tokens, token);
		while (*str == ' ')
			str++;
	}
	return (tokens);
}

static void	prt_syntax_err(t_token *token)
{
	ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
	if (token->status & PIPE)
		ft_putchar_fd('|', 2);
	else if (token->str && token->str[0])
		ft_putchar_fd(token->str[0], 2);
	else
		ft_putstr_fd("newline", 2);
	ft_putendl_fd("\'", 2);
	set_exitcode(258);
}
