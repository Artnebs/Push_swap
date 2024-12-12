/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations_calc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:27:56 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/12 14:02:22 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * calc_rotations_for_a:
 * Calculates the number of rotations required to position `target_value`
 * correctly in stack A.
 * - Positive return value: Rotate (`ra`) the stack.
 * - Negative return value: Reverse rotate (`rra`) the stack.
 */
int calc_rotations_for_a(t_stack *a, int position)
{
    if (!a || position < 0 || position >= a->size)
        return (0);

    if (position <= a->size / 2)
        return (position); // Rotate (`ra`).
    else
        return (position - a->size); // Reverse rotate (`rra`).
}

/*
 * calc_rotations_for_b:
 * Similar to `calc_rotations_for_a`, but for stack B.
 */
int calc_rotations_for_b(t_stack *b, int position)
{
    if (!b || position < 0 || position >= b->size)
        return (0);

    if (position <= b->size / 2)
        return (position); // Rotate (`rb`).
    else
        return (position - b->size); // Reverse rotate (`rrb`).
}
