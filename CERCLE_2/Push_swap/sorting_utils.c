/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:35:46 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/08 14:48:32 by anebbou          ###   ########.fr       */
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


void	quick_sort(int *array, int low, int high)
{
	int pivot_index;
	
	if (low < high)
	{
		pivot_index = partition(array, low, high);
		quick_sort(array, low, pivot_index - 1);
		quick_sort(array, pivot_index + 1, high);
	}
}

void	sort_array(int *array, int size)
{
	quick_sort(array, 0, size - 1);
}