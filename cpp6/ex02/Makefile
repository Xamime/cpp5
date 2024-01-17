# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maxime <maxime@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 13:18:04 by maxime            #+#    #+#              #
#    Updated: 2023/12/19 14:36:56 by maxime           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	main.cpp \
		# Base.cpp \
		# A.cpp \
		# B.cpp \
		# C.cpp
		
NAME = base
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