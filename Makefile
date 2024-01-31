# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younesmoukhlij <younesmoukhlij@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 15:55:17 by youmoukh          #+#    #+#              #
#    Updated: 2024/01/31 22:33:52 by younesmoukh      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	=	so_long.c             \
		fill_out_image.c  \
		key_controller.c   \
		moves_function.c    \
		error_message.c      \
		ft_parse.c     \
		ft_split.c      \
		check_error.c    \
		solong_functions_0.c     \
		solong_functions_1.c      \
		solong_functions_2.c       \
		solong_functions_3.c        \
		get_next_line.c     \
		check_valid_path.c     \
		read_map_from_file.c    \
		get_next_line_utils.c  \

bonus_folder = bonus/

SRC_B = $(bonus_folder)get_next_line_bonus.c \
		$(bonus_folder)get_next_line_utils_bonus.c \
		$(bonus_folder)check_error_bonus.c \
		$(bonus_folder)animation_bonus.c \
		$(bonus_folder)ft_parse_bonus.c \
		$(bonus_folder)so_long_bonus.c \
		$(bonus_folder)read_map_from_file_bonus.c \
		$(bonus_folder)ft_split_bonus.c \
		$(bonus_folder)solong_functions_0_bonus.c \
		$(bonus_folder)solong_functions_1_bonus.c \
		$(bonus_folder)solong_functions_2_bonus.c \
		$(bonus_folder)solong_functions_3_bonus.c \
		$(bonus_folder)fill_out_image_bonus.c \
		$(bonus_folder)moves_function_bonus.c \
		$(bonus_folder)key_controller_bonus.c \
		$(bonus_folder)error_message_bonus.c \
		$(bonus_folder)check_valid_path_bonus.c\

OBJ = ${SRC:.c=.o}

OBJ_B = ${SRC_B:.c=.o}

CFLAGS = -Wall -Wextra -Werror

HEADER_M = so_long.h

NAME = so_long

B_NAME = so_long_bonus

all : ${NAME}

bonus : ${B_NAME}

${B_NAME}: ${OBJ_B}
			@echo "\033[31m bonus Linked $@\033[0m"
			@cc ${CFLAGS} ${OBJ_B} -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@

%_bonus.o : %_bonus.c $(bonus_folder)so_long_bonus.h
			@echo "Compiling bonus $<"
			@cc ${CFLAGS} -Imlx -c $< -o $@

%.o: %.c ${HEADER_M}
	@echo "Compiling mandatory $<"
	@cc ${CFLAGS} -Imlx -c $< -o $@

$(NAME): $(OBJ)
		@echo "\033[32m mandatory Linked $@\033[0m"
		@cc $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@

clean :
	@rm -rf ${OBJ} ${OBJ_B}

fclean : clean
	@rm -rf ${NAME} ${B_NAME}

re : fclean all

.PHONY : all re fclean clean
