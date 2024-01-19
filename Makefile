# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younesmoukhlij <younesmoukhlij@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 15:55:17 by youmoukh          #+#    #+#              #
#    Updated: 2024/01/19 21:07:14 by younesmoukh      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	=	so_long.c                    \
		srcs/parser/ft_parse.c        \
		srcs/parser/ft_split.c         \
		srcs/parser/check_error.c       \
		srcs/solong_functions_0.c        \
		srcs/solong_functions_1.c         \
		srcs/parser/read_map_from_file.c   \
		get_next_line/get_next_line.c       \
		get_next_line/get_next_line_utils.c  \

OBJ = ${SRC:.c=.o}
CFLAGS = -Wall -Wextra -Werror
HEADER = so_long.h
NAME = so_long

all : ${NAME} execute clean

%.o: %.c ${HEADER}
	@cc ${CFLAGS} -c $< -o $@

execute :
	@./so_long maps/1.ber

$(NAME): $(OBJ)
	 @cc $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@

clean :
	@rm -rf ${OBJ}

fclean : clean
	@rm -rf ${NAME}

re : all fclean

.PHONY : all re fclean clean
