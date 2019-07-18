# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/18 17:48:21 by msaliuta          #+#    #+#              #
#    Updated: 2019/07/18 18:16:26 by msaliuta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c coord.c draw.c init.c message.c util.c valid.c
OBJ = $(SRC:.c=.o)
MLX = -L $(MLXDIR) -lmlx -framework OpenGL -framework Appkit

SRCDIR = srcs
OBJDIR = objs
LIBDIR = libftprintf
MLXDIR = libs/mlx

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(OBJ))
LIBS = $(LIBDIR)/libft.a $(MLX)
HEADER = -I includes -I $(LIBDIR)/includes -I $(MLXDIR)

CC = gcc
CFLAGS = -c -Wall -Wextra -Werror

NAME = fdf

.PHONY: all clean fclean re
.SUFFIXES: .c .o

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -I includes -I $(LIBDIR)/includes -I $(MLXDIR) $< -o $@

$(NAME): $(OBJS)
	@make -C $(MLXDIR)
	@$(MAKE) -C $(LIBDIR)
	@$(CC) $(OBJS) $(LIBS) -o $@
	@echo "[FdF - is ready!]"

clean:
	@/bin/rm -rf $(OBJDIR)
	@make -C $(MLXDIR) clean
	@make -C $(LIBDIR) clean
	@echo "[FdF - clean]"

fclean: clean
	@/bin/rm -f $(NAME)
	@rm -f $(LIBDIR)/libft.a
	@echo "[FdF - fclean]"

re: fclean all
