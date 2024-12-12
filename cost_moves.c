/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:26:39 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/12 13:43:52 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Perform simultaneous rotations (rr or rrr) to minimize total moves
static void	do_rr(t_stack *stack_a, t_stack *stack_b, int *rotation_a_count, int *rotation_b_count)
{
	while (*rotation_a_count > 0 && *rotation_b_count > 0)
	{
		rr(stack_a, stack_b);
		(*rotation_a_count)--;
		(*rotation_b_count)--;
	}
	while (*rotation_a_count < 0 && *rotation_b_count < 0)
	{
		rrr(stack_a, stack_b);
		(*rotation_a_count)++;
		(*rotation_b_count)++;
	}
}

// Perform independent rotations for each stack after simultaneous rotations
static void	do_rotations(t_stack *stack_a, t_stack *stack_b, int *rotation_a_count, int *rotation_b_count)
{
	while (*rotation_a_count > 0)
	{
		ra(stack_a);
		(*rotation_a_count)--;
	}
	while (*rotation_a_count < 0)
	{
		rra(stack_a);
		(*rotation_a_count)++;
	}
	while (*rotation_b_count > 0)
	{
		rb(stack_b);
		(*rotation_b_count)--;
	}
	while (*rotation_b_count < 0)
	{
		rrb(stack_b);
		(*rotation_b_count)++;
	}
}

// Move target_value from stack_b to its correct position in stack_a with minimal cost
void	move_with_min_cost(t_stack *stack_a, t_stack *stack_b, int target_value)
{
	if (!stack_a || !stack_b || stack_b->size == 0)
		return;

	int insert_position_a = get_insert_position(stack_a, target_value);
	int position_b = get_position(stack_b, target_value);

	int rotation_a_count = calc_rotations_for_a(stack_a, insert_position_a);
	int rotation_b_count = calc_rotations_for_b(stack_b, position_b);

	do_rr(stack_a, stack_b, &rotation_a_count, &rotation_b_count);
	do_rotations(stack_a, stack_b, &rotation_a_count, &rotation_b_count);

	pa(stack_b, stack_a);
}
