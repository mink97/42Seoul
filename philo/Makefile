# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 13:07:45 by mingkang          #+#    #+#              #
#    Updated: 2023/02/10 17:01:09 by mingkang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm

RMFLAGS		= -rf

AR			= ar

ARFLAGS		= -crs
# **************************************************************************** #

# philo
SRCS_DIR	= ./sources/

SRCS_NAME	= init.c main.c routine.c utils.c

SRCS		= ${addprefix ${SRCS_DIR}, ${SRCS_NAME}}

OBJS_DIR 	= objects/

OBJS_NAME	= ${SRCS_NAME:.c=.o}

OBJS		= ${addprefix ${OBJS_DIR}, ${OBJS_NAME}}

# **************************************************************************** #

COLOR_RED		= \033[0;31m
COLOR_GREEN		= \033[0;32m
COLOR_LBLUE		= \033[0;94m
COLOR_YELLOW	= \033[0;33m
COLOR_MAGENTA	= \033[0;35m
COLOR_WHITE		= \033[0;0m

all:		${NAME}

${NAME}:	${OBJS_DIR} ${OBJS}
	@echo "\n${COLOR_WHITE}${NAME}: \
	${COLOR_GREEN}objects were created${COLOR_WHITE}"
	@${CC} ${CFLAGS} ${OBJS} -o $@

${OBJS_DIR}:
	@echo "${NAME}: ${COLOR_YELLOW}objects were creating\c"
	@mkdir ${OBJS_DIR}

${OBJS_DIR}%.o:	${SRCS_DIR}%.c
	@echo ".\c"
	@${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

clean:
	@${RM} ${RMFLAGS} ${OBJS_DIR} ${B_OBJS_DIR}
	@echo "${COLOR_RED}all objects were deleted${COLOR_WHITE}"

fclean:		clean
	@${RM} ${RMFLAGS} ${NAME}
	@echo "${COLOR_RED}${NAME} were deleted${COLOR_WHITE}"

re:
	@${MAKE} fclean
	@echo "${COLOR_MAGENTA}-------------------------------${COLOR_WHITE}"
	@${MAKE} all

.PHONY:		all clean fclean re bonus
