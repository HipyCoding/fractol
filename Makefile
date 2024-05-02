# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: candrese <candrese@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 03:55:54 by candrese          #+#    #+#              #
#    Updated: 2024/04/30 20:04:25 by candrese         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= fractol
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ./lib/MLX42


HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	:= main.c utils.c fractols.c colors.c events.c move.c
OBJS	:= ${SRCS:.c=.o}

all: MLX libmlx $(LIB) $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

MLX:
	chmod 755 setup.sh
	sh setup.sh

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(LIB):
	@make -sC $(LIB_PATH)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) $(LIB) -o $(NAME)

clean:
	@echo "cleaning up..."
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	

fclean: clean
	@echo "full cleaning up..."
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
