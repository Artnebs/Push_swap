/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations_calc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:27:56 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/12 19:00:59 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* rotations_calc.c */
#include "push_swap.h"

int calc_rotations_for_a(t_stack *a, int position)
{
    if (!a || position < 0 || position >= a->size)
    {
        ft_putstr_fd("Error: Invalid position for rotations in A\n", 2);
        return (0);
    }

    // Debugging log
    ft_printf("Calculating rotations for A: Position = %d, Size = %d\n", position, a->size);

    if (position <= a->size / 2)
        return (position);
    else
        return (position - a->size);
}

int calc_rotations_for_b(t_stack *b, int position)
{
    if (!b || position < 0 || position >= b->size)
    {
        ft_putstr_fd("Error: Invalid position for rotations in B\n", 2);
        return (0);
    }

    // Debugging log
    ft_printf("Calculating rotations for B: Position = %d, Size = %d\n", position, b->size);

    if (position <= b->size / 2)
        return (position);
    else
        return (position - b->size);
}

