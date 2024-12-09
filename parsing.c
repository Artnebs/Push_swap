/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:30:04 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/09 21:23:26 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_integer(const char *str)
{
	int i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_atoi_safe(const char *str, int *val)
{
	long r = 0;
	int s = 1;

	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			s = -1;
		str++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		r = r * 10 + (*str - '0');
		if ((r * s) > 2147483647 || (r * s) < -2147483648)
			return (0);
		str++;
	}
	*val = (int)(r * s);
	return (1);
}

static int	has_duplicates(t_stack *st)
{
	t_node *c, *ch;
	c = st->top;
	while (c)
	{
		ch = c->next;
		while (ch)
		{
			if (ch->value == c->value)
				return (1);
			ch = ch->next;
		}
		c = c->next;
	}
	return (0);
}

static int	populate_stack(t_stack *s, char **vals)
{
	int v;
	int i = 0;
	while (vals[i])
	{
		if (!is_valid_integer(vals[i]) || !ft_atoi_safe(vals[i], &v))
			return (0);
		push_bottom(s, v);
		i++;
	}
	return (1);
}

t_stack	*parse_arguments(int ac, char **av)
{
	t_stack	*s;
	char	**vals;

	if (ac < 2)
		return (NULL);
	s = init_stack();
	if (!s)
		return (NULL);
	if (ac == 2)
		vals = ft_split(av[1], ' ');
	else
		vals = &av[1];
	if ((ac == 2 && !vals) || !populate_stack(s, vals))
	{
		if (ac == 2)
			ft_free_split(vals);
		free_stack(s);
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	if (ac == 2)
		ft_free_split(vals);
	if (has_duplicates(s))
	{
		free_stack(s);
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	return (s);
}
