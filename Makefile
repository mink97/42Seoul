# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 19:42:10 by mingkang          #+#    #+#              #
#    Updated: 2022/12/13 20:50:43 by mingkang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= common.c deque_utils.c execute_best.c hand_over.c hand_over_utils.c \
hard_code.c init_deque.c libft_utils.c operation.c push_swap.c

B_SRCS_NAME	= checker_bonus.c command_bonus.c deque_utils_bonus.c \
init_deque_bonus.c libft_utils_bonus.c operation_bonus.c \
get_next_line/get_next_line_bonus.c get_next_line/get_next_line_utils_bonus.c

B_SRCS_DIR	= ./bonus/

B_SRCS	= ${addprefix ${B_SRCS_DIR}, ${B_SRCS_NAME}}

HEADER	= push_swap.h

OBJS	= ${SRCS:.c=.o}

B_OBJS	= ${B_SRCS:.c=.o}

NAME	= push_swap

B_NAME	= checker

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

all:		${NAME}

bonus:		${B_NAME}

${NAME}:	${OBJS}
	${CC} ${CFLAGS} -o $@ $^

${B_NAME}:	${B_OBJS}
	${CC} ${CFLAGS} -o $@ $^

clean:
	${RM} ${OBJS} ${B_OBJS}

fclean:		clean
	${RM} ${NAME} ${B_NAME}

re:
	${MAKE} fclean
	${MAKE} all

.PHONY:		all clean fclean re
