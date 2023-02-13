/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbok <jbok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:00:43 by jbok              #+#    #+#             */
/*   Updated: 2023/02/05 13:21:43 by jbok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <signal.h>
# include <limits.h>
# include <sys/stat.h>
# include "libft.h"
# include "ft_printf.h"
# include "ft_deque.h"
# include "ft_vector.h"
# include "ft_treemap.h"

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

enum
{
	ENV_INIT,
	ENV_SET,
	ENV_GET,
	ENV_DEL,
	ENV_GET_MAP,
	ENV_GET_ENVP,
};

typedef enum e_status
{
	INFILE = 1U << 0,
	OUTFILE = 1U << 1,
	HEREDOC = 1U << 2,
	APPEND = 1U << 3,
	PIPE = 1U << 4,
	CMD = 1U << 5,
	STR = 1U << 6,
	FD = 1U << 7,
	FILE_ERROR = 1U << 8,
	SYNTAX_ERROR = 1U << 9,
	QUOTE = 1U << 10,
}	t_status;

typedef enum e_error
{
	ERR_CMD_FOUND,
	ERR_NO_FILE,
	ERR_NO_FILE_2,
	ERR_PERMIT,
	ERR_TOO_MANY_ARG,
	ERR_NUM_ARG,
	ERR_VALID_ID,
	ERR_HOME_NOT_SET,
	ERR_OLDPWD_NOT_SET,
	ERR_IS_DIRECTORY,
	ERR_IS_NOT_DIRECTORY,
	ERR_ETC,
	ERR_ETC_2
}	t_error;

typedef struct s_token
{
	t_status	status;
	char		*str;
	int			fd;
}	t_token;

typedef struct s_cmd
{
	t_status	status;
	t_token		*infile;
	t_token		*outfile;
	char		*path;
	union
	{
		char	**cmd;
		t_deque	*cmd_dq;
	};
}	t_cmd;

//	parse
t_deque		*parse(char *str);
t_cmd		*make_cmd(t_deque *tokens);
t_token		*make_token(char **str);
void		make_heredoc(t_token *token);
void		tokenize_dollar(t_vector *char_vec, char **str);

//	utils
int			is_punctuation(int c);
t_token		*vec_to_token(t_status status, t_vector *vec, char **str);
void		dq_to_cmd(t_cmd *cmd);
t_cmd		*del_cmd(t_cmd *cmd);
t_token		*del_token(t_token *token);
int			ft_strcmp_treemap(void *a, void *b);
int			is_input_space(char *input);

//	signal.c
void		init_signal(void);
void		dfl_signal(void);

//	error.c
void		set_exitcode(int ex_code);
int			get_exitcode(void);
void		ft_error(char *err_msg, t_error err_code);
void		ft_error_with_free(char *str1, char *str2, t_error err_code);

//	built*.c
void		builtin_echo(char **argv);
void		builtin_cd(char **argv);
void		builtin_pwd(char **argv);
void		builtin_export(char **argv);
void		builtin_unset(char **argv);
void		builtin_env(char **argv);
void		builtin_exit(char **cmd, t_bool is_pipe);

//	check_cmd.c
void		check_cmd(t_cmd *cmd);

//	exec.c
void		exec(t_deque *cmd_list);

//	exec_utils.c
void		wait_child(pid_t pid);
int			is_builtin(t_cmd *cmd);
void		redi_cmd(t_cmd *cmd);
void		exec_builtin(t_cmd *cmd, t_bool is_pipe);

//	env
void		*__handle_env(char *key, char *val, int mode);
void		init_env(void);
char		*ft_getenv(char *name);
char		*ft_setenv(char *name, char *val);
char		*ft_unsetenv(char *name);
t_treemap	*get_env_map(void);
char		**get_envp(void);

#endif
