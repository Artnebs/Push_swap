/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:06:20 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/12 16:25:24 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft_GNL_Printf/includes/libft.h"
# include "Libft_GNL_Printf/includes/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>

/* ************************************************************************** */
/*                                Structures                                  */
/* ************************************************************************** */

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

/* ************************************************************************** */
/*                           Main function                           */
/* ************************************************************************** */

void push_swap(t_stack *stack_a, t_stack *stack_b);

/* ************************************************************************** */
/*                           Initialization & Free                           */
/* ************************************************************************** */

t_stack	*init_stack(void);
void	free_stack(t_stack *stack);

/* ************************************************************************** */
/*                                Parsing                                     */
/* ************************************************************************** */

t_stack	*parse_arguments(int ac, char **av);

/* ************************************************************************** */
/*                             Core Operations                               */
/* ************************************************************************** */

void	swap(t_stack *stack);
void	push(t_stack *src, t_stack *dest);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

/* ************************************************************************** */
/*                           Actions (With Output)                           */
/* ************************************************************************** */

void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_b, t_stack *stack_a);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

/* ************************************************************************** */
/*                             Stack Utilities                               */
/* ************************************************************************** */

int		is_sorted(t_stack *stack);
int		get_smallest(t_stack *stack);
int		get_position(t_stack *stack, int value);
void	push_bottom(t_stack *stack, int value);

/* ************************************************************************** */
/*                         Sorting Small Stacks                              */
/* ************************************************************************** */

void	sort_three(t_stack *stack_a);
void	sort_five(t_stack *stack_a, t_stack *stack_b);

/* ************************************************************************** */
/*                     Median-Based Sorting Utilities                        */
/* ************************************************************************** */

void	quick_median_sort(t_stack *stack_a, t_stack *stack_b);
void quick_sort(int *arr, int low, int high);
void	partition_stack(t_stack *stack_a, t_stack *stack_b, int median, int size);
int		find_median(t_stack *stack);

/* ************************************************************************** */
/*                     Cost-Based Move Utilities                             */
/* ************************************************************************** */

void	merge_stacks(t_stack *stack_a, t_stack *stack_b);
void	move_with_min_cost(t_stack *stack_a, t_stack *stack_b, int target_value);

/* ************************************************************************** */
/*                    Insert Position & Rotation Utils                       */
/* ************************************************************************** */

int		get_insert_position(t_stack *stack, int value);
t_node *get_node_at_position(t_stack *stack, int position);
int		calc_rotations_for_a(t_stack *stack_a, int position);
int		calc_rotations_for_b(t_stack *stack_b, int position);

/* ************************************************************************** */
/*                                 Helpers                                   */
/* ************************************************************************** */

void	ft_free_split(char **array);
void print_stack_state(const char *msg, t_stack *stack_a, t_stack *stack_b);
int binary_search(t_stack *a, int target_value);
void print_debug_state(const char *msg, t_stack *stack);


#endif