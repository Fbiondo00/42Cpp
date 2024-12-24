# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/24 15:58:34 by flaviobiond       #+#    #+#              #
#    Updated: 2024/12/24 15:58:35 by flaviobiond      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = BurSigns

CC = g++

FLAGS = -Wall -Werror -Wextra -std=c++98 -g

SOURCE = $(wildcard *.cpp) \

OBJS = $(SOURCE:.cpp=.o)

all: $(NAME)

%.o : %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@g++ $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
