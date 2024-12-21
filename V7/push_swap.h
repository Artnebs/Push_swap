/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:26:33 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/21 19:41:14 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft_GNL_Printf/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

/* Node Structure */
typedef struct s_node {
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

/* Stack Structure */
typedef struct s_stack {
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

/* Main Functions */
int		main(int argc, char **argv);
void	push_swap(t_stack *stack_a, t_stack *stack_b);

/* Initialization & Cleanup */
t_stack	*init_stack(void);
void	free_stack(t_stack *stack);
int		push_bottom(t_stack *stack, int value);

/* Parsing */
int		*parse_arguments(int argc, char **argv, int *count);

/* Core Operations */
void	swap(t_stack *stack);
void	push(t_stack *src, t_stack *dest);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

/* Actions */
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

/* Utility Functions */
int		is_sorted(t_stack *stack);
void	ft_free_split(char **array); // Provided by libft

/* Small Stack Sorting */
void	sort_three(t_stack *stack_a);
void	sort_five(t_stack *stack_a, t_stack *stack_b);

void sort_large(t_stack *stack_a, t_stack *stack_b);

/* Ranking */
int		*rank_array(int *array, int size);
int stack_size(t_stack *stack);
int stack_max_value(t_stack *stack);
int stack_top_value(t_stack *stack);

/* Rotation Calculations */
int		get_insert_position(t_stack *stack, int value);
int		calc_rotations_for_a(t_stack *stack_a, int position);
int		calc_rotations_for_b(t_stack *stack_b, int position);

/* Cost Moves */
void	move_with_min_cost(t_stack *stack_a, t_stack *stack_b, int target_value);

/* Debugging */
void	print_stack(const char *name, t_stack *stack);

#endif
