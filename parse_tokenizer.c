/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokenizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbok <jbok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 10:13:36 by bok               #+#    #+#             */
/*   Updated: 2023/02/04 16:03:12 by jbok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_status	check_status(char **str);
static void		tokenize_quote(t_vector **char_vec, \
char **str, t_status *status);
static void		tokenize_dquote(t_vector **char_vec, \
char **str, t_status *status);

t_token	*make_token(char **str)
{
	t_vector	*char_vec;
	t_status	status;

	status = check_status(str);
	if ((!**str || is_punctuation(**str)) && !(status & (CMD | PIPE)))
		return (vec_to_token(SYNTAX_ERROR, 0, str));
	else if (!**str && status & PIPE)
		return (vec_to_token(SYNTAX_ERROR, 0, str));
	else if (status & PIPE)
		return (vec_to_token(status, 0, str));
	char_vec = ft_vec_new();
	while (**str && !is_punctuation(**str))
	{
		if (**str == '\'')
			tokenize_quote(&char_vec, str, &status);
		else if (**str == '\"')
			tokenize_dquote(&char_vec, str, &status);
		else if (**str == '$' && !(status & HEREDOC))
			tokenize_dollar(char_vec, str);
		else
			ft_vec_push(char_vec, *(*str)++);
		if (!(char_vec))
			break ;
	}
	return (vec_to_token(status, char_vec, str));
}

static t_status	check_status(char **str)
{
	t_status	status;

	while (**str && **str == ' ')
		(*str)++;
	if (!ft_strncmp("<<", *str, 2))
		status = HEREDOC | STR;
	else if (!ft_strncmp(">>", *str, 2))
		status = APPEND | STR;
	else if (**str == '<')
		status = INFILE | STR;
	else if (**str == '>')
		status = OUTFILE | STR;
	else if (**str == '|')
		status = PIPE;
	else
		status = CMD | STR;
	if (status & HEREDOC || status & APPEND)
		(*str) += 2;
	else if (status & INFILE || status & OUTFILE || status & PIPE)
		(*str) += 1;
	while (**str && **str == ' ')
		(*str)++;
	return (status);
}

static void	tokenize_quote(t_vector **char_vec, char **str, t_status *status)
{
	*status |= QUOTE;
	(*str)++;
	while (**str && **str != '\'')
		ft_vec_push(*char_vec, *(*str)++);
	if (*(*str)++ == 0)
	{
		*char_vec = ft_vec_del(*char_vec);
		(*str)--;
	}
}

static void	tokenize_dquote(t_vector **char_vec, char **str, t_status *status)
{
	*status |= QUOTE;
	(*str)++;
	while (**str && **str != '\"')
	{
		if (**str == '$' && !(*status & HEREDOC))
			tokenize_dollar(*char_vec, str);
		else
			ft_vec_push(*char_vec, *(*str)++);
	}
	if (*(*str)++ == 0)
	{
		*char_vec = ft_vec_del(*char_vec);
		(*str)--;
	}
}

void	tokenize_dollar(t_vector *char_vec, char **str)
{
	size_t	i;
	char	*key;
	char	*env;

	i = 0;
	(*str)++;
	while ((*str)[i] && !is_punctuation((*str)[i]) && \
	(*str)[i] != '\'' && (*str)[i] != '\"' && (*str)[i] != '$')
		i++;
	if (!i)
		return ;
	key = ft_substr(*str, 0, i);
	env = ft_getenv(key);
	free(key);
	*str += i;
	if (!env)
		return ;
	i = -1;
	while (env[++i])
		ft_vec_push(char_vec, env[i]);
}
