/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:51:49 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/18 12:36:57 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Create a copy of the array */
static int	*copy_array(int *array, int size)
{
	int	*copy;
	int	index;

	copy = (int *)malloc(sizeof(int) * size);
	if (!copy)
		return (NULL);
	index = 0;
	while (index < size)
	{
		copy[index] = array[index];
		index++;
	}
	return (copy);
}

/* Sort the array in ascending order using Bubble Sort */
static void	sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

/* Get the rank of a value from the sorted copy */
static int	get_rank_from_copy(int *sorted_copy, int size, int value)
{
	int	index;

	index = 0;
	while (index < size)
	{
		if (sorted_copy[index] == value)
			return (index);
		index++;
	}
	return (0);
}

/* Rank the array by replacing values with their ranks */
int	*rank_array(int *array, int size)
{
	int	*sorted_copy;
	int	index;

	sorted_copy = copy_array(array, size);
	if (!sorted_copy)
		return (NULL);
	sort_array(sorted_copy, size);
	index = 0;
	while (index < size)
	{
		array[index] = get_rank_from_copy(sorted_copy, size, array[index]);
		index++;
	}
	free(sorted_copy);
	return (array);
}
