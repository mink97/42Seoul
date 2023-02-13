# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbok <jbok@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/07 11:20:10 by jbok              #+#    #+#              #
#    Updated: 2023/02/05 13:11:03 by jbok             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
LIBFT_NAME = libft.a
LIBFT_DIR = ./libft/
LIBFT = ${LIBFT_DIR}libft.a
CFLAGS = -Wall -Werror -Wextra
LINK_FLAGS = -lreadline
ifeq (${shell uname -m}, arm64)
	CFLAGS := ${CFLAGS} -I/opt/homebrew/opt/readline/include
	LINK_FLAGS := ${LINK_FLAGS} -L/opt/homebrew/opt/readline/lib
else
	CFLAGS := ${CFLAGS} -I${HOME}/.brew/opt/readline/include
	LINK_FLAGS := ${LINK_FLAGS} -L${HOME}/.brew/opt/readline/lib
endif
SRC = main.c parse.c signal.c ft_deque.c ft_vector.c parse_tokenizer.c parse_make_cmd.c parse_make_heredoc.c parse_utils.c \
		builtin.c env.c env_utils.c error.c builtin_cd.c builtin_exit.c builtin_echo.c builtin_export.c \
		exec.c exec_utils.c check_cmd.c minishell_utils.c \
		ft_treemap_balance.c ft_treemap_del.c ft_treemap_insert.c \
		ft_treemap_utils.c ft_treemap_traversal.c
OBJ = ${SRC:.c=.o}
INCLUDES = -I./includes/ -I${LIBFT_DIR}includes/

all:	${NAME}
	@echo $(OSFLAG)

${NAME}:	${OBJ}	${LIBFT}
	${CC} ${LIBFT} ${CFLAGS} ${LINK_FLAGS} ${OBJ} -o $@

%.o:	%.c
	${CC} -c ${CFLAGS} ${INCLUDES} $< -o $@

${LIBFT}:
	${MAKE} -sC ${LIBFT_DIR}

clean:
	${RM} ${OBJ}
	${MAKE} clean -C ${LIBFT_DIR}

fclean:
	${MAKE} clean
	${RM} ${NAME} ${LIBFT}

re:
	${MAKE} fclean
	${MAKE} all

.PHONY:	all clean fclean re
