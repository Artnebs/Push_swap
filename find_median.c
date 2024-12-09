/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:13:40 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/09 21:27:21 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	copy_values(int *vals, t_stack *s)
{
	t_node *c = s->top;
	int i = 0;
	while (c)
	{
		vals[i] = c->value;
		i++;
		c = c->next;
	}
}

static void	qsort_simple(int *arr, int low, int high)
{
	int p,i,j,tmp;
	if (low < high)
	{
		p = arr[high];
		i = low - 1;
		j = low;
		while (j < high)
		{
			if (arr[j] < p)
			{
				i++;
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		tmp = arr[i+1]; arr[i+1]=arr[high]; arr[high]=tmp;
		qsort_simple(arr, low, i);
		qsort_simple(arr, i+2, high);
	}
}

int	find_median(t_stack *stack)
{
	int *vals;
	int med;

	vals = malloc(sizeof(int)*stack->size);
	if (!vals)
		return (-1);
	copy_values(vals, stack);
	qsort_simple(vals,0,stack->size-1);
	med = vals[stack->size/2];
	free(vals);
	return (med);
}
