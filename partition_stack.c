/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:10:31 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/09 21:26:15 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	partition_stack(t_stack *a, t_stack *b, int median, int size)
{
	int i = 0;
	int rotations = 0;

	while (i < size)
	{
		if (a->top->value < median)
			pb(a, b);
		else
		{
			ra(a);
			rotations++;
		}
		i++;
	}
	while (rotations > 0)
	{
		rra(a);
		rotations--;
	}
}
