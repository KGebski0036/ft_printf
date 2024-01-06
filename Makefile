# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/27 20:00:23 by kgebski           #+#    #+#              #
#    Updated: 2023/05/30 12:29:18 by kgebski          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_printf_utils.c

OBJS	= $(SRCS:.c=.o)
NAME	= libftprintf.a
LIBR	= ranlib
CFLAGS	= -Wall -Wextra -Werror
LIBFT_L = libft.a
LIBFT_DIR = libft

.c.o:
	gcc ${CFLAGS} -c $< -o ${<:.c=.o} -I .

all: libft

${NAME}: libft 

clean:
	rm -f ${OBJS} ${OBJSB}
	make -C ${LIBFT_DIR} clean

fclean: clean
	rm -f ${NAME}
	make -C ${LIBFT_DIR} fclean

re: fclean all

libft: $(OBJS)
	make -C ${LIBFT_DIR}
	mv ${LIBFT_DIR}/${LIBFT_L} ./${NAME}
	ar rcs ${NAME} ${OBJS}
	

.PHONY: all clean fclean re libft