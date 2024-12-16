/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:10:31 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/16 14:10:50 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void partition_stack(t_stack *stack_a, t_stack *stack_b, int size)
{
    if (size <= 3)
    {
        // Base case: Small stack sizes handled directly
        if (size == 2 && stack_a->top->value > stack_a->top->next->value)
            sa(stack_a);
        else if (size == 3)
            sort_three(stack_a);
        return;
    }

    int median = find_median_for_chunk(stack_a, find_median(stack_a), 1); // Calculate the median for the chunk
    int count = size;
    int pushed = 0;

    while (count > 0 && stack_a->size > 0) // Partition the stack
    {
        if (stack_a->top->value < median)
        {
            pb(stack_a, stack_b);
            pushed++;
        }
        else
        {
            ra(stack_a);
        }
        count--;
    }

    // Debugging logs
    printf("Partitioning Complete: Pushed = %d, Remaining Size = %d\n", pushed, size - pushed);

    // Recursive calls to partition smaller chunks
    if (pushed > 0 && stack_b->size > 0) // Only partition stack_b if elements were pushed
        partition_stack(stack_b, stack_a, pushed);

    if (stack_a->size > 0) // Partition remaining elements in stack_a
        partition_stack(stack_a, stack_b, size - pushed);
}
