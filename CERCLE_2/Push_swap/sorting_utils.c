/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:35:46 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/09 12:49:16 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	partition(int *array, int low, int high)
{
	int	pivot;
	int	i;
	int	j;
	int	temp;

	pivot = array[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
		j++;
	}
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	return (i + 1);
}

void	sort_array(int *array, int size)
{
	quick_sort(array, 0, size - 1);
}

int	max_bits(t_stack *stack)
{
	int	max;
	int	bits;
	t_node	*current;

	max = 0;
	bits = 0;
	current = stack->top;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	while (max > 0)
	{
		max >>= 1;
		bits++;
	}
	return (bits);
}

int adjust_for_negative_values(t_stack *stack)
{
	int offset;
	t_node *current;

	offset = 0;
	current = stack->top;
	while (current)
	{
		if (current->value < offset)
			offset = current->value;
		current = current->next;
	}
	offset = -offset;
	current = stack->top;
	while (current)
	{
		current->value += offset;
		current = current->next;
	}
	return (offset);
}

void	process_bit(t_stack *stack_a, t_stack *stack_b, int bit)
{
	int	size;
	int	i;
	int	value;
	
	size = stack_a->size;
	i = 0;
	while (i < size)
	{
		value = stack_a->top->value;
		if ((value >> bit) & 1)
			ra(stack_a);
		else
			pb(stack_a, stack_b);
		i++;
	}
	while (stack_b->size > 0)
		pa(stack_b, stack_a);
}