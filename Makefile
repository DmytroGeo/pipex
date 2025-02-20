# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgeorgiy <dgeorgiy@student.42london.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/12 11:38:45 by dgeorgiy          #+#    #+#              #
#    Updated: 2025/02/20 10:37:55 by dgeorgiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
FLAGS = -g3
SOURCES = tutorial.c
OBJECTS = $(SOURCES:.c=.o)
HEADERS = pipex.h libft/libft.h
LIBFT = libft/libft.a

%.o: %.c $(HEADERS)
		$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(LIBFT): 
		$(MAKE) -C libft

$(NAME): $(LIBFT) $(OBJECTS) $(HEADERS)
		$(CC) $(FLAGS) -o $(NAME) $(OBJECTS) $(LIBFT)

clean:
		$(MAKE) -C libft clean
		rm -f $(OBJECTS)

fclean: clean
		$(MAKE) -C libft fclean
		rm -f $(NAME)

re: fclean all

run: $(NAME)
	./$(NAME)

.PHONY: all clean fclean re run