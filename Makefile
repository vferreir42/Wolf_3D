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

NAME	=	./test

SRCS	=	./main.c 								\
				./mlx.c									\
				./key_fonction.c				\
				./display.c							\
				./calcul.c							\
				./take_map.c


OBJS	=	$(SRCS:.c=.o)

CC	=	@gcc

CFLAGS	=	-I ./libft/includes

LIB_PATH	=	./libft/libft.a

RM	=	/bin/rm -f

all	:	$(NAME)

$(NAME)	:	$(OBJS)
	@$(CC) $(OBJS) $(LIB_PATH) -o $(NAME) -lmlx -framework OpenGL -framework AppKit
	@echo "\033[32mWOLF 3D COMPILATING DONE\033[0m"
	@$(RM) $(OBJS)

clean	:

	@$(RM) $(OBJS)

fclean	:
	@$(RM) $(OBJS)
	@$(RM) $(NAME)
	@echo "\033[31mWOLF 3D CLEANING DONE"

re	:	fclean all

.PHONY	:	all clean fclean re
