/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:50:23 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/18 12:31:08 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Swap the first two nodes of the stack */
void	swap(t_stack *stack)
{
	t_node	*first_node;
	t_node	*second_node;

	if (!stack || stack->size < 2)
		return ;
	first_node = stack->top;
	second_node = first_node->next;
	first_node->next = second_node->next;
	if (second_node->next)
		second_node->next->prev = first_node;
	second_node->prev = NULL;
	second_node->next = first_node;
	first_node->prev = second_node;
	stack->top = second_node;
	if (stack->size == 2)
		stack->bottom = first_node;
}

/* Push the top node from source stack to destination stack */
void	push(t_stack *src, t_stack *dest)
{
	t_node	*node_to_move;

	if (!src || src->size == 0)
		return ;
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

/* Rotate the stack: move the top node to the bottom */
void	rotate(t_stack *stack)
{
	t_node	*top_node;
	t_node	*bottom_node;

	if (!stack || stack->size < 2)
		return ;
	top_node = stack->top;
	bottom_node = stack->bottom;
	stack->top = top_node->next;
	stack->top->prev = NULL;
	bottom_node->next = top_node;
	top_node->prev = bottom_node;
	top_node->next = NULL;
	stack->bottom = top_node;
}

/* Reverse rotate: move the bottom node to the top */
void	reverse_rotate(t_stack *stack)
{
	t_node	*top_node;
	t_node	*bottom_node;

	if (!stack || stack->size < 2)
		return ;
	top_node = stack->top;
	bottom_node = stack->bottom;
	stack->bottom = bottom_node->prev;
	stack->bottom->next = NULL;
	bottom_node->prev = NULL;
	bottom_node->next = top_node;
	top_node->prev = bottom_node;
	stack->top = bottom_node;
}
