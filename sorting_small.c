/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:24:56 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/12 14:23:46 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_stack *stack_a)
{
    if (stack_a->size < 3)
        return;

    int v1 = stack_a->top->value;
    int v2 = stack_a->top->next->value;
    int v3 = stack_a->bottom->value;

    if (v1 > v2 && v1 > v3)
        ra(stack_a);
    if (v1 > v2 && v2 > v3)
        sa(stack_a);
    if (v1 < v2 && v2 > v3 && v1 < v3)
    {
        sa(stack_a);
        ra(stack_a);
    }
    if (v1 < v3 && v2 > v3)
        rra(stack_a);
}

void sort_five(t_stack *stack_a, t_stack *stack_b)
{
    while (stack_a->size > 3)
    {
        int smallest = get_smallest(stack_a);
        while (stack_a->top->value != smallest)
        {
            if (get_position(stack_a, smallest) < stack_a->size / 2)
                ra(stack_a);
            else
                rra(stack_a);
        }
        pb(stack_a, stack_b);
    }
    sort_three(stack_a);
    while (stack_b->size > 0)
        pa(stack_b, stack_a);
}
