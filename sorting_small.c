/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:24:56 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/09 21:24:58 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a)
{
	int v1 = a->top->value;
	int v2 = a->top->next->value;
	int v3 = a->bottom->value;

	if (v1 > v2 && v1 < v3)
		sa(a);
	else if (v1 > v2 && v2 > v3)
	{ sa(a); rra(a); }
	else if (v1 > v3 && v2 < v3)
		ra(a);
	else if (v1 < v2 && v1 < v3 && v2 > v3)
	{ sa(a); ra(a); }
	else if (v1 < v2 && v2 > v3 && v1 > v3)
		rra(a);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int sm;

	while (a->size > 3)
	{
		sm = get_smallest(a);
		while (a->top->value != sm)
		{
			if (get_position(a, sm) < a->size / 2)
				ra(a);
			else
				rra(a);
		}
		pb(a, b);
	}
	sort_three(a);
	while (b->size > 0)
		pa(b, a);
}
