/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:30:04 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/04 12:29:13 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int is_valid_integer(const char *str)
{
	int i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	has_duplicates(t_stack *stack)
{
	t_node	*current;
	t_node	*checker;

	current = stack->top;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (checker->value == current->value)
				return (1);
			checker = checker->next;
		}
		current = current->next;
	}
	return (0);
}

static t_stack	*handle_error(t_stack *stack, char **values, int split)
{
	if (split)
		ft_free_split(values);
	free(stack);
	ft_putstr_fd("Error\n", 2);
	return (NULL);
}

static int	populate_stack(t_stack *stack, char **values)
{
	int	value;
	int	i;

	i = 0;
	while (values[i])
	{
		if (!is_valid_integer(values[i]) || !ft_atoi_safe(values[i], &value))
			return (0);
		push_bottom(stack, value);
		i++;
	}
	return (1);
}

t_stack	*parse_arguments(int ac, char **av)
{
	t_stack	*stack;
	char	**values;
	int	value;
	int	i;

	stack = init_stack();
	if (!stack)
		return (NULL);
	i = 0;
	if (ac == 2)
		values = ft_split(av[1], ' ');
	else
		values = &av[1];
	if (ac == 2 && !values)
		return (handle_error(stack, NULL, 0));
	if (!populate_stack(stack, values))
		return (handle_error(stack, values, ac == 2));
	if (ac == 2)
		ft_free_split(values);
	if (has_duplicates(stack))
		return (handle_error(stack, NULL, 0))
	return (stack);
}
