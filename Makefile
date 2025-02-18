# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/12 11:38:45 by dgeorgiy          #+#    #+#              #
#    Updated: 2025/02/17 11:04:58 by dgeorgiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
# 	
SOURCES = main.c
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