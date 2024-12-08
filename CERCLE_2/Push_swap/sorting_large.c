/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:30:45 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/08 14:48:56 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_median(t_stack *stack)
{
	int *values;
	int	i;
	t_node	*current;
	int	median;

	values = malloc(stack->size * sizeof(int));
	current = stack->top;
	i = 0;

	while (current)
	{
		values[i++] = current->value;
		current = current->next;
	}
	sort_a
}