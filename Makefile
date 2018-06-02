# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vferreir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/08 17:09:44 by vferreir          #+#    #+#              #
#    Updated: 2018/03/08 17:09:45 by vferreir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	./wolf3d

SRCS	=	./srcs/main.c 						\
				./srcs/mlx.c							\
				./srcs/key_fonction.c			\
				./srcs/display.c					\
				./srcs/calcul.c						\
				./srcs/read_map.c					\
				./srcs/mini_map.c

OBJS	=	$(SRCS:.c=.o)

CC	=	@clang -Wall -Werror -Wextra

CFLAGS	=	-I ./libft/includes -I ./includes -I ./minilibx_macos

LIB_PATH	=	./libft/libft.a ./minilibx_macos/libmlx.a

RM	=	/bin/rm -f

all	:	$(NAME)

$(NAME)	:	$(OBJS)
	@make -C libft
	@make -C minilibx_macos
	@$(CC) $(OBJS) $(LIB_PATH) -o $(NAME) -framework OpenGL -framework AppKit
	@echo "\033[32mWOLF 3D COMPILATING DONE\033[0m"

clean	:
	@make clean -C libft
	@make clean -C minilibx_macos
	@$(RM) $(OBJS)

fclean	:
	@make fclean -C libft
	@make clean -C minilibx_macos
	@$(RM) $(OBJS)
	@$(RM) $(NAME)
	@echo "\033[31mWOLF 3D CLEANING DONE"

re	:	fclean all

.PHONY	:	all clean fclean re
