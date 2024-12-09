/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:11:51 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/09 21:26:28 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_stacks(t_stack *a, t_stack *b)
{
	int tgt;
	if (b->size == 0)
		return;
	tgt = b->top->value;
	move_with_min_cost(a, b, tgt);
}
