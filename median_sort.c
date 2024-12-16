/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:25:25 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/12 21:07:57 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static void copy_stack_to_array(int *values, t_stack *stack)
{
	t_node *current;
	int index;

	current = stack->top;
	index = 0;
	while (current)
	{
		values[index] = current->value;
		current = current->next;
		index++;
	}
}

static void quick_sort(int *array, int low, int high)
{
	int pivot, i, j, temp;

	if (low >= high)
		return;
	pivot = array[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
		j++;
	}
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	quick_sort(array, low, i);
	quick_sort(array, i + 2, high);
}

int find_median(t_stack *stack)
{
    if (!stack || stack->size == 0)
        return (-1);

    int *values = malloc(sizeof(int) * stack->size);
    if (!values)
        return (-1);

    // Copy stack values into an array
    copy_stack_to_array(values, stack);

    // Sort the array
    quick_sort(values, 0, stack->size - 1);

    // Find the median
    int median = values[stack->size / 2];
    free(values); // Free allocated memory

    return median;
}

int find_median_for_chunk(t_stack *stack, int median, int is_upper)
{
    int *values;
    int chunk_size = 0;
    int i = 0;
    t_node *current = stack->top;

    // Count values in the chunk
    while (current)
    {
        if ((is_upper && current->value >= median) || (!is_upper && current->value < median))
            chunk_size++;
        current = current->next;
    }

    if (chunk_size == 0) // No values in the chunk
        return median;

    // Allocate memory for the chunk values
    values = malloc(sizeof(int) * chunk_size);
    if (!values)
        return median;

    // Collect values in the chunk
    current = stack->top;
    while (current)
    {
        if ((is_upper && current->value >= median) || (!is_upper && current->value < median))
            values[i++] = current->value;
        current = current->next;
    }

    // Sort the chunk
    quick_sort(values, 0, chunk_size - 1);

    // Find and return the median
    int chunk_median = values[chunk_size / 2];
    free(values);
    return chunk_median;
}

void quick_median_sort(t_stack *stack_a, t_stack *stack_b)
{
    if (!stack_a || !stack_b)
        return;

    printf("Quick Median Sort: Stack A Size = %d, Stack B Size = %d\n", stack_a->size, stack_b->size);

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

    partition_stack(stack_a, stack_b, stack_a->size);

    while (stack_b->size > 0)
    {
        printf("Merging: Stack B Top = %d\n", stack_b->top->value);
        move_with_min_cost(stack_a, stack_b, stack_b->top->value);
    }

    if (!is_sorted(stack_a)) // Ensure the final stack is sorted
        sort_three(stack_a);
}
