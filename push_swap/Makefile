# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 19:42:10 by mingkang          #+#    #+#              #
#    Updated: 2022/12/14 15:58:24 by mingkang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_NAME	= deque_utils.c execute_best.c hand_over.c hand_over_utils.c \
hard_code.c init_deque.c libft_utils.c operation.c push_swap.c common.c

SRCS_DIR	= ./push_swap_srcs/

SRCS		= ${addprefix ${SRCS_DIR}, ${SRCS_NAME}}

OBJ_DIR 	= push_swap_objs

OBJS		= ${addprefix ${OBJ_DIR}/, ${notdir ${SRCS:.c=.o}}}

NAME		= push_swap
################################################################################
B_SRCS_NAME	= checker_bonus.c command_bonus.c deque_utils_bonus.c \
init_deque_bonus.c libft_utils_bonus.c operation_bonus.c \

B_SRCS_DIR	= ./checker_srcs/

B_SRCS		= ${addprefix ${B_SRCS_DIR}, ${B_SRCS_NAME}}

vpath %.c ${SRCS_DIR} ${B_SRCS_DIR}

B_OBJ_DIR 	= checker_objs

GNL		= $(B_SRCS_DIR)/get_next_line/get_next_line.a

B_OBJS		= ${addprefix ${B_OBJ_DIR}/, ${notdir ${B_SRCS:.c=.o}}} $(GNL)

B_NAME		= checker
################################################################################
CC			= cc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -rf

all:		${NAME}

$(OBJ_DIR)/%.o:	%.c $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

${NAME}:	${OBJS}
	${CC} -o $@ $^

${OBJ_DIR}:
	mkdir ${OBJ_DIR}

bonus:		${B_NAME}

$(B_OBJ_DIR)/%.o : %.c $(B_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

${B_NAME}:	${B_OBJS}
	${CC} -o $@ $^

${B_OBJ_DIR}:
	mkdir ${B_OBJ_DIR}

${GNL}:
	$(MAKE) -C ${dir $(GNL)}

clean:
	${MAKE} -C ${dir $(GNL)} clean
	${RM} ${OBJ_DIR} ${B_OBJ_DIR} ${GNL}

fclean:		clean
	${RM} ${NAME} ${B_NAME}

re:
	${MAKE} fclean
	${MAKE} all

.PHONY:		all clean fclean re bonus
