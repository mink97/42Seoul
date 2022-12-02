# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 19:42:10 by mingkang          #+#    #+#              #
#    Updated: 2022/12/01 19:45:40 by mingkang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=

# B_SRCS	=

HEADER	= push_swap.h

OBJS	= ${SRCS:.c=.o}

# B_OBJS	= ${B_SRCS:.c=.o}

NAME	= push_swap

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

all:		${NAME}

${NAME}:	${OBJS}
#			ar -csr $@ $^

# bonus:
# 	make BONUS=1 ${NAME}

# .c.o:
# 	${CC} ${CFLAGS} -I ${HEADER} -c $< -o ${<:.c=.o}

# clean:
# 			${RM} ${B_OBJS}

# fclean:		clean
# 			${RM} ${NAME}

# re:			fclean all

# .PHONY:		all clean fclean re
