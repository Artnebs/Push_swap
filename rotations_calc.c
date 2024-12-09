/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations_calc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:27:56 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/09 21:27:58 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
  calc_rotations_for_a:
  If pos <= size/2, we need pos times ra.
  Else, we need (pos - size) times rra (negative).
*/
int	calc_rotations_for_a(t_stack *a, int pos)
{
	if (pos <= a->size / 2)
		return (pos);
	else
		return (pos - a->size);
}

/*
  calc_rotations_for_b is similar logic:
*/
int	calc_rotations_for_b(t_stack *b, int pos)
{
	if (pos <= b->size / 2)
		return (pos);
	else
		return (pos - b->size);
}
