/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:44:20 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/18 12:39:15 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Check if there are no arguments passed */
static int	is_empty(int argc)
{
	return (argc < 2);
}

/* Initialize stack with ranked values */
static int	initialize_stack(t_stack **stack, int *ranked_array, int total)
{
	int	index;

	*stack = init_stack();
	if (!*stack)
		return (0);
	index = 0;
	while (index < total)
	{
		if (!push_bottom(*stack, ranked_array[index]))
		{
			free_stack(*stack);
			return (0);
		}
		index++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		*array;
	int		total;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (is_empty(argc))
		return (0);

	array = parse_arguments(argc, argv, &total);
	if (!array)
		return (1);

	array = rank_array(array, total);
	if (!array)
		return (ft_putstr_fd("Error\n", 2), 1);

	if (!initialize_stack(&stack_a, array, total))
		return (free(array), ft_putstr_fd("Error\n", 2), 1);
	free(array);

	if (is_sorted(stack_a))
		return (free_stack(stack_a), 0);

	stack_b = init_stack();
	if (!stack_b)
		return (free_stack(stack_a), ft_putstr_fd("Error\n", 2), 1);

	push_swap(stack_a, stack_b);

	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
