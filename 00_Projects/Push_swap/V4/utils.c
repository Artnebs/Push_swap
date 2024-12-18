/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:25:22 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/18 12:28:00 by anebbou          ###   ########.fr       */
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
