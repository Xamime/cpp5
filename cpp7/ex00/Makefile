# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdesrose <mdesrose@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 16:24:35 by maxime            #+#    #+#              #
#    Updated: 2024/02/05 16:02:51 by mdesrose         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	main.cpp 
		
NAME = ex00
CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
OBJ = $(SRC:cpp=o)

all: $(NAME)

%.o: %.c
	${CXX} ${CPPFLAGS} -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re bonus