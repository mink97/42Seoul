/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_make_heredoc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbok <jbok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:33:24 by bok               #+#    #+#             */
/*   Updated: 2023/02/04 16:35:39 by jbok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	get_heredoc_input(t_token *token);
static void	get_heredoc_input_quote(t_token *token);
char		*replace_env(char *input);

void	make_heredoc(t_token *token)
{
	static size_t	index;
	char			*index_str;
	char			*heredoc_name;

	index_str = ft_itoa(index++);
	if (index > (unsigned int)INT_MAX)
		index = 0;
	heredoc_name = ft_strjoin("heredoc", index_str);
	free(index_str);
	token->fd = open(heredoc_name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (token->fd < 0)
	{
		perror("minishell: heredoc");
		set_exitcode(1);
		token->status |= FILE_ERROR;
		return ;
	}
	else
		token->status |= FD;
	get_heredoc_input(token);
	free(token->str);
	close(token->fd);
	token->fd = open(token->str = heredoc_name, O_RDONLY);
}

static void	get_heredoc_input(t_token *token)
{
	char	*input;

	if (token->status & QUOTE)
		return (get_heredoc_input_quote(token));
	while (1)
	{
		input = readline("> ");
		if (!input)
			break ;
		if (ft_strncmp(token->str, input, -1))
		{
			input = replace_env(input);
			ft_putendl_fd(input, token->fd);
			free(input);
		}
		else
		{
			free(input);
			break ;
		}
	}
}

char	*replace_env(char *input)
{
	char		*str;
	char		*ret;
	t_vector	*char_vec;

	char_vec = ft_vec_new();
	str = input;
	while (*input)
	{
		if (*input == '$')
			tokenize_dollar(char_vec, &input);
		else
			ft_vec_push(char_vec, *input++);
	}
	ret = ft_realloc(char_vec->content, char_vec->size, char_vec->size + 1);
	ret[char_vec->size] = 0;
	free(char_vec);
	free(str);
	return (ret);
}

static void	get_heredoc_input_quote(t_token *token)
{
	char	*input;

	while (1)
	{
		input = readline("> ");
		if (!input)
			break ;
		if (ft_strncmp(token->str, input, -1))
			ft_putendl_fd(input, token->fd);
		else
		{
			free(input);
			break ;
		}
		free(input);
	}
}
