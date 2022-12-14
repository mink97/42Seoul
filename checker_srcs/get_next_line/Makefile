# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 10:05:39 by mingkang          #+#    #+#              #
#    Updated: 2022/12/14 11:39:28 by mingkang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= get_next_line_bonus.c get_next_line_utils_bonus.c

OBJ_DIR = objs

OBJS	= ${addprefix ${OBJ_DIR}/, ${SRCS:.c=.o}}

NAME	= get_next_line.a

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -rf

all:		${NAME}

${NAME}:	${OBJS}
	ar -csr $@ $^

$(OBJ_DIR)/%.o:	%.c $(OBJ_DIR)
	${CC} ${CFLAGS} -c $< -o $@

${OBJ_DIR}:
	mkdir ${OBJ_DIR}

clean:
	${RM} ${OBJ_DIR}

fclean:		clean
	${RM} ${NAME}

re:
	${MAKE} fclean
	${MAKE} all

.PHONY:		all clean fclean re
