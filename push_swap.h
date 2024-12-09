/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:06:20 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/09 21:22:12 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft_GNL_Printf/includes/libft.h"
# include "Libft_GNL_Printf/includes/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>

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

/* Initialization and free */
t_stack	*init_stack(void);
void	free_stack(t_stack *stack);

/* Parsing */
t_stack	*parse_arguments(int ac, char **av);

/* Operations (no output) */
void	swap(t_stack *stack);
void	push(t_stack *src, t_stack *dest);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

/* Actions (with output) */
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *b, t_stack *a);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

/* Stack utilities */
int		is_sorted(t_stack *stack);
int		get_smallest(t_stack *stack);
int		get_position(t_stack *stack, int value);
void	push_bottom(t_stack *stack, int value);

/* Sorting small */
void	sort_three(t_stack *a);
void	sort_five(t_stack *a, t_stack *b);

/* Median-based sorting */
void	quick_median_sort(t_stack *a, t_stack *b);
void	partition_stack(t_stack *a, t_stack *b, int median, int size);

/* Merge and cost-based moves */
void	merge_stacks(t_stack *a, t_stack *b);
void	move_with_min_cost(t_stack *a, t_stack *b, int target_value);

/* Median utility */
int		find_median(t_stack *stack);

/* Insert position & rotation calculation */
int		get_insert_position(t_stack *a, int val);
int		calc_rotations_for_a(t_stack *a, int pos);
int		calc_rotations_for_b(t_stack *b, int pos);

/* Utils */
void	ft_free_split(char **array);

#endif
