# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/18 08:24:52 by lcharvol          #+#    #+#              #
#    Updated: 2019/07/22 15:44:58 by msaliuta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = srcs/ft_build_mlx.c \
	   srcs/ft_get_map.c \
	   srcs/ft_tools.c \
	   srcs/ft_tools2.c \
	   srcs/ft_draw_pixel.c \
	   srcs/ft_persp.c \
	   srcs/main.c \

FLAGS = -Wall -Werror -Wextra -I./includes

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libftprintf
	gcc -o $(NAME) $(FLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit libftprintf/libft.a
	echo "Fdf done"

clean:
	make clean -C libftprintf
	rm -f $(OBJ)

fclean: clean
	make fclean -C libftprintf
	rm -f $(NAME)

re: fclean all
