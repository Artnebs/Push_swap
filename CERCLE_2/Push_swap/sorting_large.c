/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:30:45 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/09 12:58:53 by anebbou          ###   ########.fr       */
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
	if (!values)
		return (-1);
	current = stack->top;
	i = 0;
	while (current)
	{
		values[i] = current->value;
		i++;
		current = current->next;
	}
	sort_array(values, stack->size);
	median = values[stack->size / 2];
	free(values);
	return (median);
}

void	partition_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	median;
	int	size;
	int	i;
	int	value;

	median = find_median(stack_a);
	if (median == -1)
		return ;
	size = stack_a->size;
	i = 0;
	while (i < size)
	{
		value = stack_a->top->value;
		if (value < median)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		i++;
	}
}


void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	bits, i;
	int	offset;

	offset = adjust_for_negative_values(stack_a);
	bits = max_bits(stack_a);
	i = 0;
	while (i < bits)
	{
		process_bit(stack_a, stack_b, i);
		i++;
	}
	restore_original_values(stack_a, offset);
}
