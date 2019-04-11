# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnarbert <mnarbert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/23 13:32:23 by mnarbert          #+#    #+#              #
#    Updated: 2019/02/12 12:22:29 by mnarbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker
NAME2 = push_swap
COMMAND = gcc
FLAGS = -Wall -Wextra -Werror -g
LIB = ./libft/libft.a
INCLUDE = -I libft -I includes
SRC_DIR = ./
SRC_FIL = $(shell ls ./ | grep -E "ft_.+\.c")
SRCS = $(addprefix  $(SRC_DIR), $(SRC_FIL))
OBJ = $(SRCS:.c=.o)
SRC_CHECKER = ./checker.c
OBJ_CHECKER	= $(SRC_CHECKER:.c=.o)
SRC_PUSH_SWAP = ./push_swap.c
OBJ_PUSH_SWAP	= $(SRC_PUSH_SWAP:.c=.o)

all: $(NAME1) $(NAME2)

$(LIB):
	make -C libft

$(NAME1): $(LIB) $(OBJ_CHECKER) $(OBJ)
	$(COMMAND) -g -o $(NAME1) $(INCLUDE) $(OBJ) $(OBJ_CHECKER) $(LIB) 

$(NAME2): $(LIB) $(OBJ_PUSH_SWAP) $(OBJ)
	$(COMMAND) -g -o $(NAME2) $(INCLUDE) $(OBJ) $(OBJ_PUSH_SWAP) $(LIB) 

.c.o:
	$(COMMAND) $(FLAGS) $(INCLUDE) -g -c -o $@ $<

clean:
	make -C libft clean
	/bin/rm -f $(OBJ)
	/bin/rm -f $(OBJ_CHECKER)
	/bin/rm -f $(OBJ_PUSH_SWAP)

fclean: clean
	make -C libft fclean
	/bin/rm -f $(NAME1)
	/bin/rm -f $(NAME2)

re: fclean all
