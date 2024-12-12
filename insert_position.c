/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:27:35 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/12 16:43:08 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
 * get_insert_position:
 * Determines the position in stack A where `target_value` should be inserted
 * to maintain the ascending order.
 */
int get_insert_position(t_stack *a, int target_value)
{
    printf("Checking insert position for %d\n", target_value);

    if (is_sorted(a))  // If the stack is sorted
    {
        printf("Stack is sorted, using binary search.\n");
        return binary_search(a, target_value);  // Use binary search for sorted stacks
    }

    // For unsorted stacks, traverse to find the correct position
    printf("Stack is unsorted, using linear search.\n");
    t_node *current_node = a->top;
    int position = 0;

    // Traverse the stack to find the insert position
    while (current_node)
    {
        if (current_node->value > target_value)  // Find the first element larger than the target
        {
            printf("Insert position found at %d\n", position);
            return position;
        }
        position++;
        current_node = current_node->next;
    }

    // If target_value is larger than all elements, insert at the end
    printf("Inserting at the end, position %d\n", position);
    return position;
}

/*
 * get_position:
 * Returns the position (0-indexed) of a specific `value` in the stack.
 * If the value is not found, returns -1.
 */
int get_position(t_stack *stack, int value)
{
    t_node *current_node;
    int position = 0;

    if (!stack || stack->size == 0)
        return (-1);

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