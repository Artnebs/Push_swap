/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:25:22 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/21 16:43:43 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Check if the stack is sorted in ascending order */
int	is_sorted(t_stack *stack)
{
	t_node	*current_node;

	if (!stack || stack->size < 2)
		return (1);
	current_node = stack->top;
	while (current_node->next)
	{
		if (current_node->value > current_node->next->value)
			return (0);
		current_node = current_node->next;
	}
	return (1);
}

/* Free a 2D array created by ft_split */
void	ft_free_split(char **array)
{
	int	index;

	if (!array)
		return ;
	index = 0;
	while (array[index])
	{
		free(array[index]);
		index++;
	}
	free(array);
}

/* Debug: Print the current state of the stack */
void	print_stack(const char *stack_name, t_stack *stack)
{
	t_node	*current_node;

	if (!stack || stack->size == 0)
	{
		printf("%s: (empty)\n", stack_name);
		return ;
	}
	printf("%s (size=%d):", stack_name, stack->size);
	current_node = stack->top;
	while (current_node)
	{
		printf(" %d", current_node->value);
		current_node = current_node->next;
	}
	printf("\n");
}

#include "push_swap.h"

/* Return the size of the stack */
int stack_size(t_stack *stack)
{
    int size = 0;
    t_node *current_node = stack->top;

    while (current_node)
    {
        size++;
        current_node = current_node->next;
    }
    return size;
}

/* Return the maximum value in the stack */
int stack_max_value(t_stack *stack)
{
    int max;
    t_node *current_node;

    if (!stack || !stack->top)
        return (0); // Assuming 0 is a default for empty stacks.
    current_node = stack->top;
    max = current_node->value;
    while (current_node)
    {
        if (current_node->value > max)
            max = current_node->value;
        current_node = current_node->next;
    }
    return max;
}

/* Return the value at the top of the stack */
int stack_top_value(t_stack *stack)
{
    if (!stack || !stack->top)
        return (0); // Assuming 0 for empty stacks.
    return stack->top->value;
}
