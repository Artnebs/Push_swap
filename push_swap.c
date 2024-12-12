/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:03:38 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/12 15:13:54 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_swap(t_stack *stack_a, t_stack *stack_b)
{
    // 1. Check if stack A is already sorted
    if (is_sorted(stack_a))
        return;

    // 2. Handle small stacks directly
    if (stack_a->size == 2)
    {
        sa(stack_a); // swap the top two elements
        return;
    }
    if (stack_a->size == 3)
    {
        sort_three(stack_a); // sort the top three elements
        return;
    }

    // 3. For larger stacks, use partitioning and sorting logic
    int median = find_median(stack_a);

    // 4. Partition stack A based on the median
    partition_stack(stack_a, stack_b, median, stack_a->size);

    // 5. Now recursively sort both stack A and stack B
    // Sort the upper part in stack A
    quick_median_sort(stack_a, stack_b);

    // Sort the lower part in stack B
    if (stack_b->size > 0)
        quick_median_sort(stack_b, stack_a);

    // 6. Final move to get everything back in stack A in the correct order
    while (stack_b->size > 0)
    {
        pa(stack_b, stack_a); // push elements from B back to A
    }

    // 7. Final sorting for Stack A if necessary (size 2 or 3)
    if (stack_a->size == 2)
    {
        sa(stack_a); // swap the top two elements if needed
    }
    else if (stack_a->size == 3)
    {
        sort_three(stack_a); // ensure the remaining 3 elements are sorted
    }
}
