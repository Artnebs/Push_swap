/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:24:12 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/12 17:03:10 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* operations.c */
#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_node *first;
	t_node *second;

	if (!stack || stack->size < 2)
		return;
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
	t_node *node_to_move;

	if (!src || src->size == 0)
		return;
	node_to_move = src->top;
	src->top = node_to_move->next;
	if (src->top)
		src->top->prev = NULL;
	else
		src->bottom = NULL;
	node_to_move->next = dest->top;
	if (dest->top)
		dest->top->prev = node_to_move;
	else
		dest->bottom = node_to_move;
	dest->top = node_to_move;
	src->size--;
	dest->size++;
}

void rotate(t_stack *stack)
{
	t_node *top_node;
	t_node *bottom_node;

	if (!stack || stack->size < 2)
		return;
	top_node = stack->top;
	bottom_node = stack->bottom;
	stack->top = top_node->next;
	stack->top->prev = NULL;
	bottom_node->next = top_node;
	top_node->prev = bottom_node;
	top_node->next = NULL;
	stack->bottom = top_node;
}

void reverse_rotate(t_stack *stack)
{
	t_node *top_node;
	t_node *bottom_node;

	if (!stack || stack->size < 2)
		return;
	top_node = stack->top;
	bottom_node = stack->bottom;
	stack->bottom = bottom_node->prev;
	stack->bottom->next = NULL;
	bottom_node->prev = NULL;
	bottom_node->next = top_node;
	top_node->prev = bottom_node;
	stack->top = bottom_node;
}
