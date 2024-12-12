/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:24:12 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/12 16:19:39 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> // For debug prints

// Swap the top two elements of the stack
void swap(t_stack *stack)
{
    if (!stack || stack->size < 2)
        return;

    t_node *first = stack->top;
    t_node *second = first->next;

    if (!second)
    {
        fprintf(stderr, "Error: Second node is NULL\n");
        return;
    }

    first->next = second->next;
    if (second->next)
        second->next->prev = first;

    second->prev = NULL;
    second->next = first;
    first->prev = second;

    stack->top = second;

    // Update bottom if there are exactly two elements
    if (stack->size == 2)
        stack->bottom = first;

    printf("Swapped top two elements: %d, %d\n", first->value, second->value);
}

// Push the top element from src stack to dest stack
void	push(t_stack *src, t_stack *dest)
{
	t_node *node_to_move;

	if (!src || src->size == 0)
		return;

	node_to_move = src->top;
	src->top = node_to_move->next;

	// Update src stack pointers
	if (src->top)
		src->top->prev = NULL;
	else
		src->bottom = NULL;

	// Add node to dest stack
	node_to_move->next = dest->top;
	if (dest->top)
		dest->top->prev = node_to_move;
	else
		dest->bottom = node_to_move;

	dest->top = node_to_move;

	// Update sizes
	src->size--;
	dest->size++;

	print_debug_state("After push operation (src):", src);
	print_debug_state("After push operation (dest):", dest);
}

// Rotate the stack (top element becomes the bottom)
void rotate(t_stack *stack)
{
    if (!stack || stack->size < 2)
    {
        printf("Rotate skipped (stack size=%d)\n", stack ? stack->size : 0);
        return; // No rotation needed for empty or single-element stacks.
    }

    t_node *top_node = stack->top;
    t_node *bottom_node = stack->bottom;

    printf("Rotating stack (size=%d)...\n", stack->size);

    stack->top = top_node->next;
    stack->top->prev = NULL;

    bottom_node->next = top_node;
    top_node->prev = bottom_node;
    top_node->next = NULL;

    stack->bottom = top_node;

    print_debug_state("After rotate operation:", stack);
}

// Reverse rotate the stack (bottom element becomes the top)
void reverse_rotate(t_stack *stack)
{
    if (!stack || stack->size < 2)
        return;

    t_node *top_node = stack->top;
    t_node *bottom_node = stack->bottom;

    if (stack->size == 1)
        return; // No reverse rotation needed for a single-element stack.

    stack->bottom = bottom_node->prev;
    stack->bottom->next = NULL;

    bottom_node->prev = NULL;
    bottom_node->next = top_node;
    top_node->prev = bottom_node;

    stack->top = bottom_node;

    print_debug_state("After reverse rotate operation:", stack);
}
