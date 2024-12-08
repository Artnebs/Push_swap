/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:30:32 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/08 14:02:21 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//sort 3 elements
void	sort_three(t_stack *stack_a)
{
	int	first;
	int	second;
	int	third;

	first = stack_a->top->value;
	second = stack_a->top->next->value;
	third = stack_a->bottom->value;
	if (first > second && second < third && first < third) // Case: 2 -> 1 -> 3
		sa(stack_a);
	else if (first > second && second > third) // Case: 3 -> 2 -> 1
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first > second && second < third && first > third) // Case: 3 -> 1 -> 2
		ra(stack_a);
	else if (first < second && second > third && first < third) // Case: 1 -> 3 -> 2
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first < second && second > third && first > third) // Case: 2 -> 3 -> 1
		rra(stack_a);
}

int	get_smallest(t_stack *stack)
{
	t_node	*current;
	int	smallest;
	
	current = stack->top;
	smallest = current->value;
	while (current)
	{
		if (current->value < smallest)
			smallest = current->value;
		current = current->next;
	}
	return (smallest);
}
int	get_position(t_stack *stack, int value)
{
	t_node *current;
	int position;

	current = stack->top;
	position = 0;
	while (current)
	{
		if (current->value == value)
			return (position);
		current = current->next;
		position++;
	}
	return (-1); // Shouldn't happen in this context
}


void sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int smallest;

	while (stack_a->size > 3)
	{
		smallest = get_smallest(stack_a);

		// Bring the smallest value to the top using efficient rotations
		while (stack_a->top->value != smallest)
		{
			if (get_position(stack_a, smallest) <= stack_a->size / 2)
				ra(stack_a); // Rotate if it's in the top half
			else
				rra(stack_a); // Reverse rotate if it's in the bottom half
		}
		pb(stack_a, stack_b); // Push the smallest value to stack_b
	}
	sort_three(stack_a); // Sort the remaining 3 elements in stack_a
	while (stack_b->size > 0)
		pa(stack_b, stack_a); // Push everything back to stack_a
}

