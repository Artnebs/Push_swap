/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:25:25 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/09 21:25:27 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_median_sort(t_stack *a, t_stack *b)
{
	int median;
	int size;

	if (a->size <= 3)
	{
		sort_three(a);
		return;
	}
	if (a->size <= 5)
	{
		sort_five(a,b);
		return;
	}
	size = a->size;
	median = find_median(a);
	partition_stack(a, b, median, size);
	quick_median_sort(a, b);
	/* After sorting upper part in A, 
	   you may also sort lower part currently in B if needed. 
	   For simplicity, we rely on merging later. */
}
