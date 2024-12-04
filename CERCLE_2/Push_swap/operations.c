/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:30:18 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/04 13:19:36 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	stack->top = second;
	if (stack->size == 2)
		stack->bottom = first;
}

void	push(t_stack *src, t_stack *dest)
{
	t_node	*node;
	
	if (!src || src->size == 0)
		return ;
	node = src->top;
	src->top = node->next;
	if (src->top)
		src->top->prev = NULL;
	else
		src->bottom = NULL;
	node->next = dest->top;
	if (dest->top)
		dest->top->previous = node;
	dest->top = node;
	if(dest->size == 0)
		dest->bottom = node;
	src->size--;
	dest->size++;
}

void	rotate(t_stack *stack)
{
	t_node	*top;
	t_node	*bottom;

	if (!stack || stack->size < 2)
		return ;
	top = stack->top;
	bottom = stack->bottom;
	
	stack->top = top->next;
	stack->top->prev = NULL;
	bottom->next = top;
	top->prev = bottom;
	top->next = NULL;
	stack->bottom = top;
}
void	reverse_rotate(t_stack *stack)
{
	t_node	*top;
	t_node	*bottom;

	if (!stack || stack->size < 2)
		return ;
	top = stack->top;
	bottom = stack->bottom;
	stack->bottom = bottom->prev;
	stack->bottom->next = NULL;
	bottom->prev = NULL;
	bottom->next = top;
	top->prev = bottom;
	stack->top = bottom;
}


