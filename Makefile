# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/25 03:45:12 by msaliuta          #+#    #+#              #
#    Updated: 2019/07/26 08:12:18 by msaliuta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS 	=	src/init.c \
	   		src/coord.c \
	   		src/help.c \
	   		src/draw.c \
	   		src/main.c \
	   		src/clors.c \
	   		src/parse.c \

FLAGS = -Wall -Werror -Wextra -I./includes

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libftprintf
	@gcc -o $(NAME) $(FLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit libftprintf/libft.a
	@echo "Fdf done"

clean:
	@make clean -C libftprintf
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libftprintf
	@rm -f $(NAME)

re: fclean all