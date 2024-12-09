/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:29:50 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/09 13:02:59 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ************************************************************************** */
/* INCLUDES */
/* ************************************************************************** */
# include "Libft_GNL_Printf/includes/libft.h"
# include "Libft_GNL_Printf/includes/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>

/* ************************************************************************** */
/* STRUCTURES */
/* ************************************************************************** */

//Node struct double linked list
typedef struct s_node
{
	int	value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

//Stack struct
typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int	size;
}	t_stack;


/* ************************************************************************** */
/* PROTOTYPES */
/* ************************************************************************** */

void	push_swap(t_stack *stack_a, t_stack *stack_b);

//Operations
void	swap(t_stack *stack);
void	push(t_stack *src, t_stack *dest);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

// Stack Operations
t_stack	*init_stack(void);
void	push_bottom(t_stack *stack, int value);
void	pa(t_stack *stack_b, t_stack *stack_a);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack);
void	rra(t_stack *stack);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

// Sorting Functions
void	sort_five(t_stack *stack_a, t_stack *stack_b);
void	sort_three(t_stack *stack_a);
void	radix_sort(t_stack *stack_a, t_stack *stack_b);
int		find_median(t_stack *stack);
void	partition_stack(t_stack *stack_a, t_stack *stack_b);
void	sort_large(t_stack *stack_a, t_stack *stack_b);

// Utility Functions
int		get_smallest(t_stack *stack);
int		get_position(t_stack *stack, int value);
void	push_smallest_to_b(t_stack *stack_a, t_stack *stack_b);
void	print_error(void);
int		is_valid_input(int ac);
void	print_stack(t_stack *stack);
void	ft_free_split(char **array);
void	quick_sort(int *array, int low, int high);
int		partition(int *array, int low, int high);
void	sort_array(int *array, int size);
int		max_bits(t_stack *stack);
void	free_stack(t_stack *stack);
int		adjust_for_negative_values(t_stack *stack);
void	restore_original_values(t_stack *stack, int offset);
void	process_bit(t_stack *stack_a, t_stack *stack_b, int bit);

// Validation and Parsing
int		ft_atoi_safe(const char *str, int *value);
int		is_valid_integer(const char *str);
int		populate_stack(t_stack *stack, char **values);

// Error Handling
t_stack	*handle_error(t_stack *stack, char **values, int split);
void	print_stack(t_stack *stack);

/* ************************************************************************** */
/* BONUS (Pour une éventuelle extension) */
/* ************************************************************************** */

#endif