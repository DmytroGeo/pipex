# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/12 12:03:28 by dgeorgiy          #+#    #+#              #
#    Updated: 2025/02/12 12:04:43 by dgeorgiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
AR = ar rcs
# 'ar' is like 'cc' but for compiling static libraries.
# "Create (c) the archive if it doesn't exist, replace (r) existing object files, and generate an index (s)."
HEADERS = libft.h
FLAGS = -Wall -Wextra -Werror
SOURCES = ft_array_len.c \
			ft_atoi.c \
			ft_contains_only_digit.c \
			ft_find_in_list.c \
			ft_free.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_lstmax.c \
			ft_lstmin.c \
			ft_lstnew.c \
			ft_lstsize.c \
			ft_max_int.c \
			ft_memcpy.c \
			ft_min_int.c \
			ft_printf.c \
			ft_putchar_fd.c \
			ft_putchex_fd.c \
			ft_puthex_fd.c \
			ft_putnbr_fd.c \
			ft_putptr_fd.c \
			ft_putstr_fd.c \
			ft_putuns_fd.c \
			ft_split.c \
			ft_strcmp.c \
			ft_strlen.c 
				
OBJECTS = $(SOURCES:.c=.o)

%.o : %.c $(HEADERS)
		$(CC) $(FLAGS) -c $< -o $@

# You don’t need -o when using ar! That flag is used by cc to specify an output file, but ar works differently. 
# The correct way to archive object files looks like this:
# $(AR) expands to ar rcs, meaning "create or update the archive".
# $(NAME) (which is libft.a) is the output archive.
# $(OBJECTS) are the input files (the compiled .o files).

$(NAME): $(OBJECTS)
		$(AR) $(NAME) $(OBJECTS)

# I could instead write 'libft.a: $(OBJECTS)
# 	$(AR) libft.a $(OBJECTS)' but using variables is better.

all: $(NAME)

clean: 
		rm -f $(OBJECTS)

fclean:	clean
		rm -f libft.a
		
re: fclean all

.PHONY: all clean fclean re