/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:30:04 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/12 18:54:55 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* parsing.c */
#include "push_swap.h"

#include <stdio.h> // Include for debugging

static int	ft_atoi_safe(const char *input, int *output)
{
	long	result;
	int		sign;

	// Skip leading spaces
	while (*input == ' ' || *input == '\t' || *input == '\n' ||
		   *input == '\v' || *input == '\f' || *input == '\r')
		input++;

	result = 0;
	sign = 1;

	// Handle sign
	if (*input == '-' || *input == '+')
	{
		if (*input == '-')
			sign = -1;
		input++;
	}

	// Check if the input is empty after handling spaces and signs
	if (!*input)
	{
		fprintf(stderr, "Error: Input is empty or invalid\n");
		return (0);
	}

	// Process the number
	while (*input)
	{
		if (!ft_isdigit(*input)) // Validate character is a digit
		{
			fprintf(stderr, "Error: Non-numeric character encountered\n");
			return (0);
		}

		result = result * 10 + (*input - '0');

		// Check for overflow or underflow
		if ((result * sign) > 2147483647 || (result * sign) < -2147483648)
		{
			fprintf(stderr, "Error: Integer overflow or underflow\n");
			return (0);
		}

		input++;
	}

	*output = (int)(result * sign);
	return (1);
}

static int	has_duplicates(t_stack *stack)
{
	int		hash_table[2000001];
	int		index;
	t_node	*current_node;
	int		i;

	i = 0;
	while (i < 2000001)
	{
		hash_table[i] = 0;
		i++;
	}
	current_node = stack->top;
	while (current_node)
	{
		index = current_node->value + 1000000;
		if (hash_table[index] != 0)
			return (1);
		hash_table[index] = 1;
		current_node = current_node->next;
	}
	return (0);
}

static int	populate_stack(t_stack *stack, char **string_values)
{
	int current_value;
	int i;

	i = 0;
	while (string_values[i])
	{
		// Validate and convert the current string to an integer
		if (!ft_atoi_safe(string_values[i], &current_value))
		{
			ft_putstr_fd("Error: Invalid number\n", 2);
			free_stack(stack); // Free the partially filled stack
			return (0);
		}

		// Add the validated number to the stack
		push_bottom(stack, current_value);
		i++;
	}

	return (1);
}


t_stack	*parse_arguments(int argc, char **argv)
{
	t_stack	*stack;
	char	**values;

	// Check if there are enough arguments
	if (argc < 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}

	stack = init_stack();
	if (!stack)
		return (NULL);

	// Handle single string input (e.g., "./push_swap '1 2 3'")
	if (argc == 2)
		values = ft_split(argv[1], ' ');
	else
		values = &argv[1];

	// Validate and populate the stack
	if ((argc == 2 && !values) || !populate_stack(stack, values))
	{
		if (argc == 2)
			ft_free_split(values); // Free split result if it was allocated
		free_stack(stack);
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}

	// Free split result if it was allocated
	if (argc == 2)
		ft_free_split(values);

	// Check for duplicates
	if (has_duplicates(stack))
	{
		free_stack(stack);
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}

	return (stack);
}

