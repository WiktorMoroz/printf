# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmoroz <wmoroz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/28 18:26:12 by wmoroz            #+#    #+#              #
#    Updated: 2024/05/29 19:37:49 by wmoroz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_put_un.c ft_putchar.c ft_putptr.c \
	ft_puthexa.c ft_putnbr.c ft_putstr.c \
	ft_strlen.c ft_printf.c

OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a
LIBC = ar rcs
CC = gcc
RM = rm -f
CFFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
		${LIBC} ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY : all clean fclean re