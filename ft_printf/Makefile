# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 14:28:28 by mingkang          #+#    #+#              #
#    Updated: 2022/11/29 14:28:29 by mingkang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c print_func1.c print_func2.c

HEADER	= ft_printf.h

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

all:		${NAME}

${NAME}:	${OBJS}
			ar -csr $@ $^

.c.o:
	${CC} ${CFLAGS} -I ${HEADER} -c $< -o ${<:.c=.o}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
