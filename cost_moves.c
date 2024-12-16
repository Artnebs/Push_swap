/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:26:39 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/12 20:48:55 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* cost_moves.c */
#include "push_swap.h"

static void do_rr(t_stack *stack_a, t_stack *stack_b, int *rotation_a_count, int *rotation_b_count)
{
    printf("Initial Rotations: A: %d, B: %d\n", *rotation_a_count, *rotation_b_count);

    while (*rotation_a_count > 0 && *rotation_b_count > 0)
    {
        rr(stack_a, stack_b);
        *rotation_a_count = *rotation_a_count - 1;
        *rotation_b_count = *rotation_b_count - 1;
    }
    while (*rotation_a_count < 0 && *rotation_b_count < 0)
    {
        rrr(stack_a, stack_b);
        *rotation_a_count = *rotation_a_count + 1;
        *rotation_b_count = *rotation_b_count + 1;
    }

    printf("After do_rr: Rotations Remaining A: %d, B: %d\n", *rotation_a_count, *rotation_b_count);
}


static void do_rotations(t_stack *stack_a, t_stack *stack_b, int *rotation_a_count, int *rotation_b_count)
{
    printf("Remaining Rotations Before Individual Operations: A: %d, B: %d\n", *rotation_a_count, *rotation_b_count);

    while (*rotation_a_count > 0)
    {
        ra(stack_a);
        *rotation_a_count = *rotation_a_count - 1;
    }
    while (*rotation_a_count < 0)
    {
        rra(stack_a);
        *rotation_a_count = *rotation_a_count + 1;
    }
    while (*rotation_b_count > 0)
    {
        rb(stack_b);
        *rotation_b_count = *rotation_b_count - 1;
    }
    while (*rotation_b_count < 0)
    {
        rrb(stack_b);
        *rotation_b_count = *rotation_b_count + 1;
    }

    printf("After Individual Rotations: A: %d, B: %d\n", *rotation_a_count, *rotation_b_count);
}


void move_with_min_cost(t_stack *stack_a, t_stack *stack_b, int target_value)
{
    if (!stack_a || !stack_b || stack_b->size == 0)
        return;

    int insert_position_a = get_insert_position(stack_a, target_value);
    int position_b = get_position(stack_b, target_value);
    int rotation_a_count = calc_rotations_for_a(stack_a, insert_position_a);
    int rotation_b_count = calc_rotations_for_b(stack_b, position_b);

    printf("Target: %d, Insert Position A: %d, Position B: %d\n", target_value, insert_position_a, position_b);
    printf("Initial Rotations A: %d, B: %d\n", rotation_a_count, rotation_b_count);

    do_rr(stack_a, stack_b, &rotation_a_count, &rotation_b_count);
    do_rotations(stack_a, stack_b, &rotation_a_count, &rotation_b_count);

    printf("After Rotations: A Size: %d, B Size: %d\n", stack_a->size, stack_b->size);

    if (stack_b->size > 0)
        pa(stack_b, stack_a);
}
