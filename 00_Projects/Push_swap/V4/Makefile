# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 10:28:35 by anebbou           #+#    #+#              #
#    Updated: 2024/12/18 12:42:55 by anebbou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Name
NAME = push_swap

# Libft Setup
LIBFT_DIR = Libft_GNL_Printf
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_REPO = https://github.com/Artnebs/Libft_GNL_Printf.git

# Source Files
SRCS = main.c \
	   push_swap.c \
	   parsing.c \
	   stack_init.c \
	   operations.c \
	   actions.c \
	   actions2.c \
	   actions3.c \
	   sorting_small.c \
	   ranking.c \
	   rotations_calc.c \
	   cost_moves.c \
	   utils.c
OBJS = $(SRCS:.c=.o)

# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I. -I$(LIBFT_DIR)/includes

# Silence unnecessary make outputs
MAKEFLAGS += --silent

# Default Rule
all: $(LIBFT) $(NAME)

# Build the executable
$(NAME): $(OBJS)
	@echo "Linking $(NAME)..."
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft

# Compile object files
%.o: %.c
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# Build Libft
$(LIBFT):
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
		echo "Cloning Libft repository..."; \
		git clone $(LIBFT_REPO) $(LIBFT_DIR); \
	fi
	@echo "Building Libft library..."
	@make -C $(LIBFT_DIR)

# Clean object files
clean:
	@echo "Cleaning object files..."
	rm -f $(OBJS)
	@if [ -d "$(LIBFT_DIR)" ]; then \
		make -C $(LIBFT_DIR) clean; \
	fi

# Clean all files
fclean: clean
	@echo "Cleaning $(NAME) and Libft..."
	rm -f $(NAME)
	@if [ -d "$(LIBFT_DIR)" ]; then \
		rm -rf $(LIBFT_DIR); \
		echo "Deleted Libft_GNL_Printf directory."; \
	fi

# Rebuild everything
re: fclean all

# Ensure makefile targets are not interpreted as filenames
.PHONY: all clean fclean re
