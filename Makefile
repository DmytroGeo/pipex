# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/12 11:38:45 by dgeorgiy          #+#    #+#              #
#    Updated: 2025/03/05 12:50:14 by dgeorgiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
FLAGS = -Wall -Wextra -Werror -g3
LIBFT = libft/libft.a
SOURCES = src/close_pipes.c \
			src/flags_and_paths.c \
			src/dup_read_and_write.c \
			src/execute.c \
			src/initialise.c \
			src/free_and_exit.c \
			src/proc_call.c \
			src/process_loop.c \
			src/wait_for_processes.c \
			main.c
			
OBJECTS = $(SOURCES:.c=.o)

%.o: %.c
		$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(LIBFT): 
		$(MAKE) -C libft

$(NAME): $(LIBFT) $(OBJECTS)
		$(CC) $(FLAGS) -o $(NAME) $(OBJECTS) $(LIBFT)

clean:
		$(MAKE) -C libft clean
		rm -f $(OBJECTS)

fclean: clean
		$(MAKE) -C libft fclean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re run