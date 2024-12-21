/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations_calc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:44:20 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/18 12:37:59 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Get the position to insert a value into stack a */
int	get_insert_position(t_stack *stack_a, int value)
{
	t_node	*current_node;
	int		min_value;
	int		max_value;
	int		position;
	int		index;

	if (!stack_a || stack_a->size == 0)
		return (0);

	current_node = stack_a->top;
	min_value = current_node->value;
	max_value = current_node->value;

	/* Find minimum and maximum values in the stack */
	while (current_node)
	{
		if (current_node->value < min_value)
			min_value = current_node->value;
		if (current_node->value > max_value)
			max_value = current_node->value;
		current_node = current_node->next;
	}

	/* Insert before the smallest or after the largest value */
	if (value < min_value || value > max_value)
	{
		position = 0;
		current_node = stack_a->top;
		while (current_node && current_node->value != min_value)
		{
			current_node = current_node->next;
			position++;
		}
		return (position);
	}

	/* Find the position between consecutive nodes */
	index = 0;
	current_node = stack_a->top;
	while (current_node->next)
	{
		if (current_node->value < value && current_node->next->value > value)
			return (index + 1);
		current_node = current_node->next;
		index++;
	}

	/* Default to placing at the bottom */
	return (stack_a->size);
}

/* Calculate the number of rotations needed for stack a */
int	calc_rotations_for_a(t_stack *stack_a, int position)
{
	if (!stack_a || position < 0 || position >= stack_a->size)
		return (0);
	if (position <= stack_a->size / 2)
		return (position);
	return (position - stack_a->size);
}

/* Calculate the number of rotations needed for stack b */
int	calc_rotations_for_b(t_stack *stack_b, int position)
{
	if (!stack_b || position < 0 || position >= stack_b->size)
		return (0);
	if (position <= stack_b->size / 2)
		return (position);
	return (position - stack_b->size);
}
