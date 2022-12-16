# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ratinax <ratinax@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 14:46:33 by tibernot          #+#    #+#              #
#    Updated: 2022/12/16 15:33:05 by ratinax          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Changing variables
NAME = so_long

HEADER = get_next_line.h \
		so_long.h

HEADER_DIR = .

SRCS = get_next_line.c \
	get_next_line_utils.c \
	parsing.c \
	check_input.c \
	lists_breakpoint.c \
	test_path.c \
	test_path_tools.c \
	game.c \
	initialize.c \
	main.c

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -I $(HEADER_DIR)

RM = rm
RM_FLAGS = -rf
FRAMEWORK = -framework OpenGL -framework AppKit
OBJS = $(SRCS:.c=.o)

DIROBJS=objs/

all: makemlx makelibft $(NAME)

$(NAME): $(DIROBJS) $(addprefix $(DIROBJS), $(OBJS))
	$(CC) $(CFLAGS) $(FRAMEWORK) $(addprefix $(DIROBJS), $(OBJS)) libft/libft.a ./minilibx/libmlx.a -o $(NAME)

$(DIROBJS)%.o: %.c Makefile $(HEADER) ./libft/libft.a ./minilibx/libmlx.a
	$(CC) $(CFLAGS) -c $< -o $@

$(DIROBJS):
	mkdir $(DIROBJS)

makemlx:
	make -C ./minilibx/.

makelibft:
	make -C ./libft/.

clean:
	make -C ./libft/. clean
	make -C ./minilibx/. clean
	$(RM) $(RM_FLAGS) $(DIROBJS)

fclean : clean
	make -C ./libft/. fclean
	$(RM) $(RM_FLAGS) $(NAME)

re : fclean	all

.PHONY: all re fclean clean makelibft makemlx
