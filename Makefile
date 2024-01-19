# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younesmoukhlij <younesmoukhlij@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 15:55:17 by youmoukh          #+#    #+#              #
#    Updated: 2024/01/18 23:40:51 by younesmoukh      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	=	main.c          \
		ft_parse.c       \
		check_error.c     \
		ft_split.c         \
		get_next_line.c     \
		solong_functions_0.c \
		read_map_from_file.c  \
		get_next_line_utils.c  \

OBJ = ${SRC:.c=.o}
CFLAGS = -Wall -Wextra -Werror
HEADER = so_long.h
NAME = so_long

all : ${NAME}

%.o : %.c ${HEADER}
	@cc ${CFLAGS} -c $< -o $@

${NAME} : ${OBJ}
	@cc ${OBJ} -o $@

clean :
	@rm -rf ${OBJ}

fclean : clean
	@rm -rf ${NAME}

re : all fclean

.PHONY : all re fclean clean
