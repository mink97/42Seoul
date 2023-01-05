# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/24 14:48:10 by mingkang          #+#    #+#              #
#    Updated: 2022/12/24 17:50:17 by mingkang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

MLXFLAGS	= -lmlx -framework OpenGL -framework AppKit

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

# fdf
SRCS_DIR	= ./sources/

SRCS_NAME	= color_utils.c color.c common.c control_key.c control_mouse.c \
draw.c init_map.c init.c main.c point.c

SRCS		= ${addprefix ${SRCS_DIR}, ${SRCS_NAME}}

OBJS_DIR 	= objects/

OBJS_NAME	= ${SRCS_NAME:.c=.o}

OBJS		= ${addprefix ${OBJS_DIR}, ${OBJS_NAME}}
# **************************************************************************** #

COLOR_RED	= \033[0;31m
COLOR_GREEN	= \033[0;32m
COLOR_LBLUE	= \033[0;94m
COLOR_YELLOW	= \033[0;33m
COLOR_MAGENTA	= \033[0;35m
COLOR_WHITE	= \033[0;0m

all:		${NAME}

${NAME}:	${LIBFT} ${OBJS_DIR} ${OBJS}
	@echo "\n${COLOR_WHITE}${NAME}: \
	${COLOR_GREEN}objects were created${COLOR_WHITE}"
	@${CC} ${CFLAGS} ${LIBFT} ${MLXFLAGS} ${OBJS} -o $@
	@echo "${COLOR_LBLUE}${NAME}: finished!!${COLOR_WHITE}"

${OBJS_DIR}:
	@echo "${NAME}: ${COLOR_YELLOW}objects were creating\c"
	@mkdir ${OBJS_DIR}

${OBJS_DIR}%.o:	${SRCS_DIR}%.c
	@echo ".\c"
	@${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

${LIBFT}:
	@echo "${LIBFT_NAME} : ${COLOR_YELLOW}creating...${COLOR_WHITE}"
	@${MAKE} -sC ${LIBFT_DIR} bonus
	@echo "${LIBFT_NAME} : ${COLOR_GREEN}created!!${COLOR_WHITE}"

clean:
	@${MAKE} -sC ${LIBFT_DIR} clean
	@${RM} ${RMFLAGS} ${OBJS_DIR}
	@echo "${COLOR_RED}all objects were deleted${COLOR_WHITE}"

fclean:		clean
	@${RM} ${RMFLAGS} ${LIBFT}
	@${RM} ${RMFLAGS} ${NAME}
	@echo "${COLOR_RED}fdf and libft.a were deleted${COLOR_WHITE}"

re:
	@${MAKE} fclean
	@echo "${COLOR_MAGENTA}-------------------------------${COLOR_WHITE}"
	@${MAKE} all

.PHONY:		all clean fclean re bonus
