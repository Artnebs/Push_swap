/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:37:19 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/18 12:32:41 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Validates if a string represents a valid integer */
static int	is_valid_integer(const char *str)
{
	int		index;
	long	number;
	int		sign;

	index = 0;
	sign = 1;
	number = 0;
	if (str[index] == '-' || str[index] == '+')
		sign = (str[index++] == '-') ? -1 : 1;
	if (!str[index])
		return (0);
	while (str[index] && ft_isdigit(str[index]))
	{
		number = number * 10 + (str[index] - '0');
		if ((sign == 1 && number > 2147483647L) 
			|| (sign == -1 && -number < -2147483648L))
			return (0);
		index++;
	}
	return (str[index] == '\0');
}

/* Checks for duplicate integers in an array */
static int	has_duplicates(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/* Counts the total numbers in arguments */
static int	count_numbers_in_args(int argc, char **argv)
{
	int		index;
	int		total_numbers;
	char	**split_values;
	int		sub_index;

	total_numbers = 0;
	index = 1;
	while (index < argc)
	{
		split_values = ft_split(argv[index], ' ');
		if (!split_values)
			return (-1);
		sub_index = 0;
		while (split_values[sub_index])
			sub_index++;
		total_numbers += sub_index;
		ft_free_split(split_values);
		index++;
	}
	return (total_numbers);
}

/* Fills the integer array with parsed numbers */
static int	fill_integer_array(int argc, char **argv, int *integer_array)
{
	int		index;
	int		array_index;
	char	**split_values;
	int		sub_index;

	array_index = 0;
	index = 1;
	while (index < argc)
	{
		split_values = ft_split(argv[index], ' ');
		if (!split_values)
			return (0);
		sub_index = 0;
		while (split_values[sub_index])
		{
			if (!is_valid_integer(split_values[sub_index]))
				return (ft_free_split(split_values), 0);
			integer_array[array_index++] = ft_atoi(split_values[sub_index]);
			sub_index++;
		}
		ft_free_split(split_values);
		index++;
	}
	return (1);
}

/* Parses arguments into an integer array */
int	*parse_arguments(int argc, char **argv, int *count)
{
	int	total_numbers;
	int	*integer_array;

	total_numbers = count_numbers_in_args(argc, argv);
	if (total_numbers <= 0)
		return (ft_putstr_fd("Error\n", 2), NULL);
	integer_array = (int *)malloc(sizeof(int) * total_numbers);
	if (!integer_array)
		return (ft_putstr_fd("Error\n", 2), NULL);
	if (!fill_integer_array(argc, argv, integer_array))
		return (free(integer_array), ft_putstr_fd("Error\n", 2), NULL);
	if (has_duplicates(integer_array, total_numbers))
		return (free(integer_array), ft_putstr_fd("Error\n", 2), NULL);
	*count = total_numbers;
	return (integer_array);
}
