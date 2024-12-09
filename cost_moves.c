/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:26:39 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/09 21:26:41 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_rr(t_stack *a, t_stack *b, int *ra_c, int *rb_c)
{
	while (*ra_c > 0 && *rb_c > 0)
	{
		rr(a,b);
		(*ra_c)--;
		(*rb_c)--;
	}
	while (*ra_c < 0 && *rb_c < 0)
	{
		rrr(a,b);
		(*ra_c)++;
		(*rb_c)++;
	}
}

static void	do_rotations(t_stack *a, t_stack *b, int *ra_c, int *rb_c)
{
	while (*ra_c > 0)
	{
		ra(a);
		(*ra_c)--;
	}
	while (*ra_c < 0)
	{
		rra(a);
		(*ra_c)++;
	}
	while (*rb_c > 0)
	{
		rb(b);
		(*rb_c)--;
	}
	while (*rb_c < 0)
	{
		rrb(b);
		(*rb_c)++;
	}
}

void	move_with_min_cost(t_stack *a, t_stack *b, int target_value)
{
	int pos_a = get_insert_position(a, target_value);
	int pos_b = get_position(b, target_value);
	int ra_c = calc_rotations_for_a(a, pos_a);
	int rb_c = calc_rotations_for_b(b, pos_b);

	do_rr(a,b,&ra_c,&rb_c);
	do_rotations(a,b,&ra_c,&rb_c);
	pa(b,a);
}
