/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:51:33 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/18 12:36:04 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Sort a stack of three elements */
void	sort_three(t_stack *stack_a)
{
	int	top_value;
	int	middle_value;
	int	bottom_value;

	if (!stack_a || stack_a->size < 2)
		return ;
	if (stack_a->size == 2 && stack_a->top->value > stack_a->top->next->value)
		sa(stack_a);
	if (stack_a->size == 3)
	{
		top_value = stack_a->top->value;
		middle_value = stack_a->top->next->value;
		bottom_value = stack_a->bottom->value;
		if (top_value > middle_value && middle_value < bottom_value && top_value < bottom_value)
			sa(stack_a);
		else if (top_value > middle_value && middle_value > bottom_value)
		{
			sa(stack_a);
			rra(stack_a);
		}
		else if (top_value > middle_value && middle_value < bottom_value && top_value > bottom_value)
			ra(stack_a);
		else if (top_value < middle_value && middle_value > bottom_value && top_value < bottom_value)
		{
			sa(stack_a);
			ra(stack_a);
		}
		else if (top_value < middle_value && middle_value > bottom_value && top_value > bottom_value)
			rra(stack_a);
	}
}

/* Get the smallest value in the stack */
static int	get_smallest(t_stack *stack)
{
	t_node	*current_node;
	int		smallest;

	if (!stack || stack->size == 0)
		return (0); // Handle appropriately if empty
	current_node = stack->top;
	smallest = current_node->value;
	while (current_node)
	{
		if (current_node->value < smallest)
			smallest = current_node->value;
		current_node = current_node->next;
	}
	return (smallest);
}

/* Get the position of a specific value in the stack */
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

/* Sort a stack of five elements */
void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	smallest_value;
	int	position;

	while (stack_a->size > 3)
	{
		smallest_value = get_smallest(stack_a);
		position = get_position(stack_a, smallest_value);
		while (position > 0 && position <= stack_a->size / 2)
		{
			ra(stack_a);
			position = get_position(stack_a, smallest_value);
		}
		while (position > stack_a->size / 2)
		{
			rra(stack_a);
			position = get_position(stack_a, smallest_value);
		}
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (stack_b->size > 0)
		pa(stack_b, stack_a);
}
