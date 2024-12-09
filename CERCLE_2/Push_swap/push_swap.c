/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:53:52 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/09 13:02:24 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 3)
	{
		sort_three(stack_a);
		return ;
	}
	if (stack_a->size <= 5)
	{
		sort_five(stack_a, stack_b);
		return ;
	}
	radix_sort(stack_a, stack_b);
}