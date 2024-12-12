/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:28:27 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/12 16:42:20 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_split(char **arr)
{
	int i;

	if (!arr)
		return;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void print_debug_state(const char *msg, t_stack *stack)
{
    t_node *current;

    printf("%s\n", msg);
    printf("Stack state (size=%d): ", stack->size);
    current = stack->top;
    while (current)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

t_node *get_node_at_position(t_stack *stack, int position)
{
    t_node *current_node = stack->top;
    int current_position = 0;

    while (current_node)
    {
        if (current_position == position)
            return current_node;
        current_node = current_node->next;
        current_position++;
    }

    return NULL;  // Return NULL if position is out of bounds
}

int binary_search(t_stack *a, int target_value)
{
    int low = 0;
    int high = a->size - 1;

    printf("Starting binary search for %d\n", target_value);

    // Create an array to store the stack values
    int *arr = malloc(sizeof(int) * a->size);
    if (!arr)
        return -1;  // Handle memory allocation failure

    // Copy the values of the stack into the array
    t_node *current_node = a->top;
    int i = 0;
    while (current_node)
    {
        arr[i++] = current_node->value;
        current_node = current_node->next;
    }

    // Binary search on the array
    while (low <= high)
    {
        int mid = (low + high) / 2;
        printf("Low: %d, High: %d, Mid: %d\n", low, high, mid);
        t_node *mid_node = get_node_at_position(a, mid); // Use the function you defined earlier

        if (mid_node->value == target_value)
        {
            free(arr);
            return mid;
        }
        else if (mid_node->value < target_value)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    // If the value isn't found, return the insertion position
    free(arr);
    return low;  // Return the index where the value should be inserted
}


int is_sorted(t_stack *stack)
{
    t_node *current_node = stack->top;

    if (!stack || stack->size < 2)
        return 1; // Stack is sorted or has fewer than two elements

    while (current_node && current_node->next)
    {
        if (current_node->value > current_node->next->value)
        {
            printf("Stack is unsorted\n");  // Debug message
            return 0; // Stack is not sorted
        }
        current_node = current_node->next;
    }

    printf("Stack is sorted\n");  // Debug message
    return 1; // Stack is sorted
}
