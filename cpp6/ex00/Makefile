# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maxime <maxime@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 12:07:04 by maxime            #+#    #+#              #
#    Updated: 2023/12/18 13:59:43 by maxime           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	main.cpp \
		ScalarConverter.cpp
		
NAME = convert
CXX = clang++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -g
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