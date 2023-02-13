# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbok <jbok@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/07 11:20:10 by jbok              #+#    #+#              #
#    Updated: 2023/02/03 20:30:24 by jbok             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_bzero.c ft_memcpy.c ft_memset.c ft_memmove.c ft_memchr.c ft_memcmp.c \
	ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
	ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_atoi.c \
	ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
	ft_itoa.c ft_strmapi.c ft_striteri.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
	get_next_line.c get_next_line_utils.c free_strs.c \
	ft_printf_format.c ft_printf_format2.c ft_printf_parse.c \
	ft_printf_utils.c ft_printf_utils2.c ft_printf.c check.c
OBJS = ${SRCS:.c=.o}
RM = rm -f
INCLUDES = -I./includes/ -I${LIBFT_DIR}includes/

all:	${NAME}

${NAME}:	${OBJS}
	ar rcus $@ ${OBJS}

%.o:	%.c
	${CC} -c ${CFLAGS} ${INCLUDES} -c $< -o $@

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:
	${MAKE} fclean
	${MAKE} all

.PHONY:	all clean fclean re
