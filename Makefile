# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/30 10:10:44 by mingkang          #+#    #+#              #
#    Updated: 2023/01/05 16:26:57 by mingkang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm

RMFLAGS		= -rf

AR			= ar

ARFLAGS		= -crs
# **************************************************************************** #

# libft
LIBFT_DIR	= ./libft/

LIBFT_NAME	= libft.a

LIBFT		= ${LIBFT_DIR}libft.a

INCLUDES	= -I./includes/ -I${LIBFT_DIR}includes/

# pipex
SRCS_DIR	= ./sources/

SRCS_NAME	= quotation_split.c here_doc.c parse_cmd.c utils.c pipex.c

SRCS		= ${addprefix ${SRCS_DIR}, ${SRCS_NAME}}

OBJS_DIR 	= objects/

OBJS_NAME	= ${SRCS_NAME:.c=.o}

OBJS		= ${addprefix ${OBJS_DIR}, ${OBJS_NAME}}

# pipex_bonus
B_SRCS_DIR	= ./sources_bonus/

B_SRCS_NAME	= quotation_split_bonus.c here_doc_bonus.c parse_cmd_bonus.c \
				utils_bonus.c pipex_bonus.c

B_SRCS		= ${addprefix ${B_SRCS_DIR}, ${B_SRCS_NAME}}

B_OBJS_DIR 	= objects_bonus/

B_OBJS_NAME	= ${B_SRCS_NAME:.c=.o}

B_OBJS		= ${addprefix ${B_OBJS_DIR}, ${B_OBJS_NAME}}
# **************************************************************************** #

COLOR_RED		= \033[0;31m
COLOR_GREEN		= \033[0;32m
COLOR_LBLUE		= \033[0;94m
COLOR_YELLOW	= \033[0;33m
COLOR_MAGENTA	= \033[0;35m
COLOR_WHITE		= \033[0;0m

ifdef BONUS
	F_OBJS = ${B_OBJS}
	F_OBJS_DIR = ${B_OBJS_DIR}
	F_SRCS_DIR = ${B_SRCS_DIR}
else
	F_OBJS = ${OBJS}
	F_OBJS_DIR = ${OBJS_DIR}
	F_SRCS_DIR = ${SRCS_DIR}
endif

all:		${NAME}

${NAME}:	${LIBFT} ${F_OBJS_DIR} ${F_OBJS}
	@echo "\n${COLOR_WHITE}${NAME}: \
	${COLOR_GREEN}objects were created${COLOR_WHITE}"
	@${CC} ${CFLAGS} ${LIBFT} ${MLXFLAGS} ${F_OBJS} -o $@
	@echo "${COLOR_LBLUE}${NAME}: finished!!${COLOR_WHITE}"

bonus:
	@make BONUS=1 ${NAME}

${OBJS_DIR}:
	@echo "${NAME}: ${COLOR_YELLOW}objects were creating\c"
	@mkdir ${OBJS_DIR}

${OBJS_DIR}%.o:	${SRCS_DIR}%.c
	@echo ".\c"
	@${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

${B_OBJS_DIR}:
	@echo "${NAME}: ${COLOR_YELLOW}objects were creating\c"
	@mkdir ${B_OBJS_DIR}

${B_OBJS_DIR}%.o:	${B_SRCS_DIR}%.c
	@echo ".\c"
	@${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

${LIBFT}:
	@echo "${LIBFT_NAME} : ${COLOR_YELLOW}creating...${COLOR_WHITE}"
	@${MAKE} -sC ${LIBFT_DIR} bonus
	@echo "${LIBFT_NAME} : ${COLOR_GREEN}created!!${COLOR_WHITE}"

clean:
	@${MAKE} -sC ${LIBFT_DIR} clean
	@${RM} ${RMFLAGS} ${OBJS_DIR} ${B_OBJS_DIR}
	@echo "${COLOR_RED}all objects were deleted${COLOR_WHITE}"

fclean:		clean
	@${MAKE} -sC ${LIBFT_DIR} fclean
	@${RM} ${RMFLAGS} ${NAME}
	@echo "${COLOR_RED}${NAME} and ${LIBFT_NAME} were deleted${COLOR_WHITE}"

re:
	@${MAKE} fclean
	@echo "${COLOR_MAGENTA}-------------------------------${COLOR_WHITE}"
	@${MAKE} all

.PHONY:		all clean fclean re bonus
