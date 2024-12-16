/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:03:52 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/12 17:03:57 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* actions2.c */
#include "push_swap.h"
#include <unistd.h>

void	pa(t_stack *stack_b, t_stack *stack_a)
{
	push(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}
