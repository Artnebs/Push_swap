/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:27:35 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/12 19:00:37 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* insert_position.c */
#include "push_swap.h"

int get_position(t_stack *stack, int value)
{
	t_node *current_node;
	int position;

	if (!stack || stack->size == 0)
		return (-1);
	position = 0;
	current_node = stack->top;
	while (current_node)
	{
		if (current_node->value == value)
			return (position);
		position++;
		current_node = current_node->next;
	}
	return (-1);
}

int get_insert_position(t_stack *a, int target_value)
{
    t_node *current;
    int position;

    if (!a || a->size == 0)
        return (0);

    position = 0;
    current = a->top;

    while (current)
    {
        // Case 1: Target fits between two nodes
        if (current->value > target_value && 
           (!current->next || current->next->value < target_value))
            return (position);

        // Case 2: Wrap-around at the end
        if (current->value < a->top->value && target_value < current->value)
            return (position);

        position++;
        current = current->next;
    }

    // Case 3: If we get here, the target fits at the bottom
    return position;
}

