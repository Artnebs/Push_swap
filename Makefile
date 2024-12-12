# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 10:28:35 by anebbou           #+#    #+#              #
#    Updated: 2024/12/12 15:07:41 by anebbou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker

# Libft
LIBFT_DIR = Libft_GNL_Printf
LIBFT = $(LIBFT_DIR)/libft.a

# Sources
SRCS = main.c push_swap.c parsing.c stack_init.c stack_utils.c operations.c actions.c \
       sorting_small.c median_sort.c partition_stack.c merge_stacks.c \
       cost_moves.c find_median.c insert_position.c rotations_calc.c utils.c
CHECKER_SRCS = checker.c

# Objects
OBJS = $(SRCS:.c=.o)
CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)

# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I. -I$(LIBFT_DIR)/includes

# Git Repository URL
LIBFT_REPO = https://github.com/Artnebs/Libft_GNL_Printf.git

# Rules
all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft

$(CHECKER): $(CHECKER_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(CHECKER_OBJS) -o $(CHECKER) -L$(LIBFT_DIR) -lft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
		echo "Cloning Libft repository..."; \
		git clone $(LIBFT_REPO) $(LIBFT_DIR); \
	fi
	@make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS) $(CHECKER_OBJS)
	@if [ -d "$(LIBFT_DIR)" ]; then \
		make -C $(LIBFT_DIR) clean; \
	fi

fclean: clean
	rm -f $(NAME) $(CHECKER)
	@if [ -d "$(LIBFT_DIR)" ]; then \
		rm -rf $(LIBFT_DIR); \
		echo "Deleted Libft_GNL_Printf directory."; \
	fi

re: fclean all

.PHONY: all clean fclean re
