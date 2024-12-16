/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:03:38 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/12 20:16:41 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_swap(t_stack *stack_a, t_stack *stack_b)
{
    if (is_sorted(stack_a)) // Check if the stack is already sorted
        return;

    // Special handling for small stacks
    if (stack_a->size <= 3)
    {
        sort_three(stack_a);
        return;
    }
    if (stack_a->size <= 5)
    {
        sort_five(stack_a, stack_b);
        return;
    }

    // Use the updated partition_stack without passing the median explicitly
    partition_stack(stack_a, stack_b, stack_a->size);

    // Push elements back from Stack B to Stack A with minimal cost
    while (stack_b->size > 0)
    {
        int target_value = stack_b->top->value;
        move_with_min_cost(stack_a, stack_b, target_value);
    }

    // Ensure the final stack is sorted
    if (!is_sorted(stack_a))
        sort_three(stack_a);
}
