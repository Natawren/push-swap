# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnarbert <mnarbert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/23 13:32:23 by mnarbert          #+#    #+#              #
#    Updated: 2019/02/12 13:54:53 by mnarbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
COMMAND = gcc
FLAGS = -Wall -Wextra -Werror
SRC_DIR = ./
SRC_FIL = $(shell ls ./ | grep -E "ft_.+\.c")
SRCS = $(addprefix  $(SRC_DIR), $(SRC_FIL))
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):$(OBJ)
	$(COMMAND) $(FLAGS) -c $(SRCS) -I libft.h
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
