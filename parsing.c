/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:30:04 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/12 12:53:44 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Validate and convert a string to an integer
// Kept non-static because it might be useful in other parsing contexts.
int	ft_atoi_safe(const char *input, int *output)
{
	long	result = 0;
	int		sign = 1;

	if (*input == '-' || *input == '+')
	{
		if (*input == '-')
			sign = -1;
		input++;
	}
	if (!*input) // Ensure there's at least one digit
		return (0);
	while (*input)
	{
		if (!ft_isdigit(*input))
			return (0);
		result = result * 10 + (*input - '0');
		if ((result * sign) > 2147483647 || (result * sign) < -2147483648)
			return (0); // Overflow or underflow
		input++;
	}
	*output = (int)(result * sign);
	return (1);
}

// Check for duplicate values in the stack
// Kept static because duplicates are specific to parsing the stack.
static int	has_duplicates(t_stack *stack)
{
	int		hash_table[2000001] = {0};
	t_node	*current_node = stack->top;

	while (current_node)
	{
		int index = current_node->value + 1000000; // Map [-1M, 1M] to [0, 2M]
		if (hash_table[index] != 0)
			return (1);
		hash_table[index] = 1;
		current_node = current_node->next;
	}
	return (0);
}

// Populate the stack with integers from a string array
// Kept static because it is specific to this parsing logic.
static int populate_stack(t_stack *stack, char **string_values)
{
    int current_value;
    int i = 0;

    while (string_values[i])
    {
        if (!ft_atoi_safe(string_values[i], &current_value))
            return 0; // Failed to convert value
        push_bottom(stack, current_value); // Push value to stack
        i++;
    }
    return 1; // Successfully populated stack
}

// Parse arguments into a stack
// Handles both space-separated strings and multiple arguments
t_stack	*parse_arguments(int argc, char **argv)
{
	t_stack	*stack;
	char	**values;

	if (argc < 2)
		return (NULL);

	// Initialize the stack
	stack = init_stack();
	if (!stack)
		return (NULL);

	// Handle space-separated input or regular argument list
	if (argc == 2)
		values = ft_split(argv[1], ' ');
	else
		values = &argv[1];

	// Populate the stack and handle errors
	if ((argc == 2 && !values) || !populate_stack(stack, values))
	{
		if (argc == 2)
			ft_free_split(values);
		free_stack(stack);
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}

	// Free split array if used
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
