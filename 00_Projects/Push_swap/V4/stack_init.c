/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:36:25 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/18 12:25:25 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

/* Function to initialize an empty stack */
t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	return (stack);
}

/* Function to free a stack and all its nodes */
void	free_stack(t_stack *stack)
{
	t_node	*current_node;
	t_node	*next_node;

	if (!stack)
		return ;
	current_node = stack->top;
	while (current_node)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
	free(stack);
}

/* Function to add a new node to the bottom of the stack */
int	push_bottom(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = stack->bottom;
	if (stack->bottom)
		stack->bottom->next = new_node;
	else
		stack->top = new_node;
	stack->bottom = new_node;
	stack->size++;
	return (1);
}
