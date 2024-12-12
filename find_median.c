/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:13:40 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/12 16:10:45 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Copies values from stack into an array
static void copy_stack_to_array(int *values, t_stack *stack)
{
    t_node *current = stack->top;
    int index = 0;

    while (current)
    {
        values[index] = current->value;
        index++;
        current = current->next;
    }
}

// Performs a quick sort on the array
void quick_sort(int *array, int low, int high)
{
    if (low >= high)
        return;

    int pivot = array[high];
    int i = low - 1;
    int j = low;

    while (j < high)
    {
        if (array[j] < pivot)
        {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
        j++;
    }
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

    quick_sort(array, low, i);
    quick_sort(array, i + 2, high);
}


// Finds the median value in the stack
int find_median(t_stack *stack)
{
    if (!stack || stack->size == 0)
        return -1;

    int *values = malloc(sizeof(int) * stack->size);
    if (!values)
        return -1;

    copy_stack_to_array(values, stack);
    quick_sort(values, 0, stack->size - 1);

    int median = values[stack->size / 2];
    free(values);
    return median;
}
