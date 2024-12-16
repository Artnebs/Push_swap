/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:11:51 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/12 17:08:58 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Merges the elements from stack B into stack A by moving the top element of stack B
// to its correct position in stack A with minimal cost
void merge_stacks(t_stack *stack_a, t_stack *stack_b)
{
    int target_value;

    if (stack_b->size == 0)
        return;

    // Get the value to be moved from stack B to stack A
    target_value = stack_b->top->value;

    // Move the target value from stack B to stack A with minimal cost
    move_with_min_cost(stack_a, stack_b, target_value);
}

