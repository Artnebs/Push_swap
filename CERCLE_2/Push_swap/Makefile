# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 10:28:35 by anebbou           #+#    #+#              #
#    Updated: 2024/12/04 10:29:00 by anebbou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker

# Libft
LIBFT_DIR = Libft_GNL_Printf
LIBFT = $(LIBFT_DIR)/libft.a

# Sources
SRCS = main.c parsing.c operations.c sorting_small.c sorting_large.c utils.c
CHECKER_SRCS = checker.c

# Objets
OBJS = $(SRCS:.c=.o)
CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)

# Compilateur et flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Règles
all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(CHECKER): $(CHECKER_OBJS)
	$(CC) $(CFLAGS) $(CHECKER_OBJS) $(LIBFT) -o $(CHECKER)

$(LIBFT):
	git clone https://github.com/Artnebs/Libft_GNL_Printf.git $(LIBFT_DIR)
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS) $(CHECKER_OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(CHECKER)
	make -C $(LIBFT_DIR) fclean

re: fclean all
