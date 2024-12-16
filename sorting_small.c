/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:24:56 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/12 19:17:00 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* sorting_small.c */
#include "push_swap.h"

void sort_three(t_stack *stack_a)
{
    int v1, v2, v3;

    if (stack_a->size < 3)
        return;
    v1 = stack_a->top->value;
    v2 = stack_a->top->next->value;
    v3 = stack_a->bottom->value;

    if (v1 > v2 && v2 < v3 && v1 < v3) // 2 1 3 -> sa
        sa(stack_a);
    else if (v1 > v2 && v2 > v3) // 3 2 1 -> sa + rra
    {
        sa(stack_a);
        rra(stack_a);
    }
    else if (v1 > v2 && v2 < v3 && v1 > v3) // 3 1 2 -> ra
        ra(stack_a);
    else if (v1 < v2 && v2 > v3 && v1 < v3) // 1 3 2 -> sa + ra
    {
        sa(stack_a);
        ra(stack_a);
    }
    else if (v1 < v2 && v2 > v3 && v1 > v3) // 2 3 1 -> rra
        rra(stack_a);
}

void sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int smallest;

	while (stack_a->size > 3)
	{
		smallest = get_smallest(stack_a);
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
