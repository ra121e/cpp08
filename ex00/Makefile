# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/23 10:40:55 by athonda           #+#    #+#              #
#    Updated: 2025/06/24 13:26:10 by athonda          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Easyfind

SRC_F	=	main.cpp

SRC_DIR	=	.
SRC		=	$(SRC_F:%.cpp=$(SRC_DIR)/%.cpp)

OBJ_DIR	=	obj
OBJ		=	$(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SRC_F))

DEP_EX	=	easyfind.hpp
INC_DIR	=	.
DEP		=	$(wildcard $(patsubst %.cpp,$(INC_DIR)/%.hpp,$(SRC_F))) $(DEP_EX)

CC		=	c++
CFLAGS	=	-g -Wall -Wextra -Werror -std=c++98
IFLAGS	=	-I$(INC_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(DEP)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

.PHONY: all clean fclean re

all: $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	clear
	nm -u $(NAME)
	grep -n -e "main" $(SRC) $(DEP) || true
	grep -n -e "printf" $(SRC) $(DEP) || true
	grep -n -e "alloc" $(SRC) $(DEP) || true
	grep -n -e "free" $(SRC) $(DEP) || true
