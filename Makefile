# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/22 16:56:22 by lramirez          #+#    #+#              #
#    Updated: 2019/07/20 16:49:18 by msaliuta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf
CC=gcc
SRC=./srcs/main.c ./srcs/errors.c ./srcs/key_input.c ./srcs/bresenham.c ./srcs/ft_fill_tab.c ./srcs/ft_math.c
OBJ=main.o errors.o key_input.o bresenham.o ft_fill_tab.o ft_math.o
FLAGS=-Wall -Wextra -Werror
LIB=./libftprintf/libft.a
MLX=-L ./miniLibx -l mlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	@ make -C ./libftprintf
	@ $(CC) $(FLAGS) $(OBJ) -o $(NAME) $(MLX) $(LIB)
$(OBJ): $(SRC)
	@ $(CC) $(FLAGS) -c $(SRC)
clean:
	@ rm -f $(OBJ)
	@ make -C ./libftprintf clean
fclean: clean
	@ rm -f $(NAME)
	@ make -C ./libftprintf fclean
re: fclean all

.PHONY: clean, fclean, re
