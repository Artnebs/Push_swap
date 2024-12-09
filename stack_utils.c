/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:23:57 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/09 21:23:59 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_bottom(t_stack *stack, int value)
{
	t_node *new = malloc(sizeof(t_node));
	if (!new)
		return;
	new->value = value;
	new->next = NULL;
	new->prev = stack->bottom;
	if (stack->bottom)
		stack->bottom->next = new;
	else
		stack->top = new;
	stack->bottom = new;
	stack->size++;
}

int	is_sorted(t_stack *stack)
{
	t_node *c;
	if (stack->size < 2)
		return (1);
	c = stack->top;
	while (c->next)
	{
		if (c->value > c->next->value)
			return (0);
		c = c->next;
	}
	return (1);
}

int	get_smallest(t_stack *stack)
{
	t_node *c = stack->top;
	int small = c->value;
	while (c)
	{
		if (c->value < small)
			small = c->value;
		c = c->next;
	}
	return (small);
}

int	get_position(t_stack *stack, int value)
{
	t_node *c = stack->top;
	int pos = 0;
	while (c)
	{
		if (c->value == value)
			return (pos);
		pos++;
		c = c->next;
	}
	return (-1);
}
