/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:28:27 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/12 17:05:13 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* utils.c */
#include "push_swap.h"
#include <stdlib.h>

int	is_sorted(t_stack *stack)
{
	t_node *current_node;

	if (!stack || stack->size < 2)
		return (1);
	current_node = stack->top;
	while (current_node->next)
	{
		if (current_node->value > current_node->next->value)
			return (0);
		current_node = current_node->next;
	}
	return (1);
}

void	ft_free_split(char **arr)
{
	int i;

	if (!arr)
		return;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
