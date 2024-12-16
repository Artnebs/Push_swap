# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 10:28:35 by anebbou           #+#    #+#              #
#    Updated: 2024/12/12 18:44:50 by anebbou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker

# Libft
LIBFT_DIR = Libft_GNL_Printf
LIBFT = $(LIBFT_DIR)/libft.a

# Sources
SRCS = main.c \
push_swap.c \
parsing.c \
stack_init.c \
stack_utils.c \
operations.c \
actions.c \
sorting_small.c \
median_sort.c \
partition_stack.c \
merge_stacks.c \
cost_moves.c \
insert_position.c \
rotations_calc.c \
utils.c \
actions2.c \
actions3.c \
actions4.c

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

# Building push_swap
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft

# Building checker
$(CHECKER): $(CHECKER_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(CHECKER_OBJS) -o $(CHECKER) -L$(LIBFT_DIR) -lft

# Rule for compiling .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Handling the Libft repository
$(LIBFT):
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
		echo "Cloning Libft repository..."; \
		git clone $(LIBFT_REPO) $(LIBFT_DIR); \
	fi
	@make -C $(LIBFT_DIR)

# Clean the object files
clean:
	rm -f $(OBJS) $(CHECKER_OBJS)
	@if [ -d "$(LIBFT_DIR)" ]; then \
		make -C $(LIBFT_DIR) clean; \
	fi

# Clean everything and remove the executable and checker
fclean: clean
	rm -f $(NAME) $(CHECKER)
	@if [ -d "$(LIBFT_DIR)" ]; then \
		rm -rf $(LIBFT_DIR); \
		echo "Deleted Libft_GNL_Printf directory."; \
	fi

# Rebuild everything from scratch
re: fclean all

# Phony targets to avoid conflicts with file names
.PHONY: all clean fclean re
