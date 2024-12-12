/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:10:31 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/12 15:46:58 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Partitions the stack based on the median value - 2 pointers approach
void partition_stack(t_stack *stack_a, t_stack *stack_b, int median, int size)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        // Move values smaller than median to stack_b
        if (stack_a->top->value < median)
        {
            pb(stack_a, stack_b);
            left++;
        }
        // Move values larger than or equal to median to the end of stack_a
        else
        {
            ra(stack_a);
            right--;
        }
    }
}
