/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:23:57 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/12 17:04:53 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* stack_utils.c */
#include "push_swap.h"
#include <stdlib.h>

void push_bottom(t_stack *stack, int value)
{
	t_node *new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return;
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = stack->bottom;
	if (stack->bottom)
		stack->bottom->next = new_node;
	else
		stack->top = new_node;
	stack->bottom = new_node;
	stack->size++;
}

int get_smallest(t_stack *stack)
{
	t_node *current_node;
	int smallest_value;

	if (!stack || stack->size == 0)
		return (0);
	current_node = stack->top;
	smallest_value = current_node->value;
	while (current_node)
	{
		if (current_node->value < smallest_value)
			smallest_value = current_node->value;
		current_node = current_node->next;
	}
	return (smallest_value);
}

