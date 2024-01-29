# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younesmoukhlij <younesmoukhlij@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 15:55:17 by youmoukh          #+#    #+#              #
#    Updated: 2024/01/29 22:46:10 by younesmoukh      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	=	so_long.c             \
		srcs/animation.c       \
		srcs/fill_out_image.c   \
		srcs/key_controller.c    \
		srcs/moves_function.c     \
		srcs/parser/ft_parse.c     \
		srcs/parser/ft_split.c      \
		srcs/parser/check_error.c    \
		srcs/solong_functions_0.c     \
		srcs/solong_functions_1.c      \
		srcs/solong_functions_2.c         \
		get_next_line/get_next_line.c    \
		srcs/parser/check_valid_path.c    \
		srcs/parser/read_map_from_file.c   \
		get_next_line/get_next_line_utils.c \

OBJ = ${SRC:.c=.o}
CFLAGS = -Wall -Wextra -Werror
HEADER = so_long.h
NAME = so_long

all : ${NAME}   clean play

%.o: %.c ${HEADER}
	@cc ${CFLAGS} -Imlx -c $< -o $@

play :
	@./so_long maps/1.ber

$(NAME): $(OBJ)
	 @cc $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@

clean :
	@rm -rf ${OBJ}

fclean : clean
	@rm -rf ${NAME}

re : all fclean

.PHONY : all re fclean clean
