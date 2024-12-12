/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:25:25 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/12 15:47:25 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void quick_median_sort(t_stack *stack_a, t_stack *stack_b)
{
    int current_median;
    int stack_size;

    // Ensure stacks are valid
    if (!stack_a || !stack_b)
        return;

    // Base cases: small sizes
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

    // Recursive case: Median partitioning
    stack_size = stack_a->size;
    current_median = find_median(stack_a);
    partition_stack(stack_a, stack_b, current_median, stack_size);

    // Sort upper part in A
    quick_median_sort(stack_a, stack_b);

    // Sort or merge lower part in B (if necessary)
    if (stack_b->size > 0)
        quick_median_sort(stack_b, stack_a);
}


int median_of_medians(int *arr, int n)
{
    if (n <= 5)
    {
        quick_sort(arr, 0, n - 1);
        return arr[n / 2];
    }

    // Split array into groups of 5
    int groups = (n + 4) / 5;
    int medians[groups];

    for (int i = 0; i < groups; i++)
    {
        int start = i * 5;
        int end = (i + 1) * 5 < n ? (i + 1) * 5 : n;
        quick_sort(arr, start, end - 1);
        medians[i] = arr[(start + end - 1) / 2]; // Select median of each group
    }

    // Find the median of the medians
    return median_of_medians(medians, groups);
}
