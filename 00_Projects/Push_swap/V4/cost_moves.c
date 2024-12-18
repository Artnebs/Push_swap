/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:52:44 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/18 12:34:21 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Get the position of a value in the stack */
static int	get_position(t_stack *stack, int value)
{
	t_node	*current_node;
	int		position;

	current_node = stack->top;
	position = 0;
	while (current_node)
	{
		if (current_node->value == value)
			return (position);
		position++;
		current_node = current_node->next;
	}
	return (-1);
}

/* Perform combined rotations (rr or rrr) to minimize moves */
static void	do_rr(t_stack *stack_a, t_stack *stack_b, int *ra_count, int *rb_count)
{
	while (*ra_count > 0 && *rb_count > 0)
	{
		rr(stack_a, stack_b);
		(*ra_count)--;
		(*rb_count)--;
	}
	while (*ra_count < 0 && *rb_count < 0)
	{
		rrr(stack_a, stack_b);
		(*ra_count)++;
		(*rb_count)++;
	}
}

/* Perform remaining rotations for stacks a and b */
static void	do_rotations(t_stack *stack_a, t_stack *stack_b, int *ra_count, int *rb_count)
{
	while (*ra_count > 0)
	{
		ra(stack_a);
		(*ra_count)--;
	}
	while (*ra_count < 0)
	{
		rra(stack_a);
		(*ra_count)++;
	}
	while (*rb_count > 0)
	{
		rb(stack_b);
		(*rb_count)--;
	}
	while (*rb_count < 0)
	{
		rrb(stack_b);
		(*rb_count)++;
	}
}

/* Move the value from stack b to stack a with minimal cost */
void	move_with_min_cost(t_stack *stack_a, t_stack *stack_b, int value)
{
	int	insert_pos;
	int	pb_pos;
	int	ra_count;
	int	rb_count;

	if (!stack_a || !stack_b || stack_b->size == 0)
		return ;
	insert_pos = get_insert_position(stack_a, value);
	pb_pos = get_position(stack_b, value);
	ra_count = calc_rotations_for_a(stack_a, insert_pos);
	rb_count = calc_rotations_for_b(stack_b, pb_pos);
	do_rr(stack_a, stack_b, &ra_count, &rb_count);
	do_rotations(stack_a, stack_b, &ra_count, &rb_count);
	if (stack_b->size > 0)
		pa(stack_b, stack_a);
}
