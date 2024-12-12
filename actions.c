/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:24:22 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/11 14:55:18 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> // For debug prints


// Swap the top two elements of stack A and print the operation
void sa(t_stack *stack_a)
{
    swap(stack_a);
    ft_putstr_fd("sa\n", 1);
    print_stack_state("After sa (swap stack A):", stack_a, NULL);
}

// Swap the top two elements of stack B and print the operation
void sb(t_stack *stack_b)
{
    swap(stack_b);
    ft_putstr_fd("sb\n", 1);
    print_stack_state("After sb (swap stack B):", NULL, stack_b);
}

// Swap the top two elements of both stacks and print the operation
void ss(t_stack *stack_a, t_stack *stack_b)
{
    swap(stack_a);
    swap(stack_b);
    ft_putstr_fd("ss\n", 1);
    print_stack_state("After ss (swap both stacks):", stack_a, stack_b);
}

// Push the top element from stack B to stack A and print the operation
void pa(t_stack *stack_b, t_stack *stack_a)
{
    push(stack_b, stack_a);
    ft_putstr_fd("pa\n", 1);
    print_stack_state("After pa (push stack B to stack A):", stack_a, stack_b);
}

// Push the top element from stack A to stack B and print the operation
void pb(t_stack *stack_a, t_stack *stack_b)
{
    push(stack_a, stack_b);
    ft_putstr_fd("pb\n", 1);
    print_stack_state("After pb (push stack A to stack B):", stack_a, stack_b);
}

// Rotate stack A and print the operation
void ra(t_stack *stack_a)
{
    rotate(stack_a);
    ft_putstr_fd("ra\n", 1);
    print_stack_state("After ra (rotate stack A):", stack_a, NULL);
}

// Rotate stack B and print the operation
void rb(t_stack *stack_b)
{
    rotate(stack_b);
    ft_putstr_fd("rb\n", 1);
    print_stack_state("After rb (rotate stack B):", NULL, stack_b);
}

// Rotate both stacks and print the operation
void rr(t_stack *stack_a, t_stack *stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
    ft_putstr_fd("rr\n", 1);
    print_stack_state("After rr (rotate both stacks):", stack_a, stack_b);
}

// Reverse rotate stack A and print the operation
void rra(t_stack *stack_a)
{
    reverse_rotate(stack_a);
    ft_putstr_fd("rra\n", 1);
    print_stack_state("After rra (reverse rotate stack A):", stack_a, NULL);
}

// Reverse rotate stack B and print the operation
void rrb(t_stack *stack_b)
{
    reverse_rotate(stack_b);
    ft_putstr_fd("rrb\n", 1);
    print_stack_state("After rrb (reverse rotate stack B):", NULL, stack_b);
}

// Reverse rotate both stacks and print the operation
void rrr(t_stack *stack_a, t_stack *stack_b)
{
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
    ft_putstr_fd("rrr\n", 1);
    print_stack_state("After rrr (reverse rotate both stacks):", stack_a, stack_b);
}
