/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:38:28 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/18 12:29:54 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Swap the first two elements of stack a and print "sa" */
void	sa(t_stack *stack_a)
{
	swap(stack_a);
	ft_putstr_fd("sa\n", 1);
}

/* Swap the first two elements of stack b and print "sb" */
void	sb(t_stack *stack_b)
{
	swap(stack_b);
	ft_putstr_fd("sb\n", 1);
}

/* Swap the first two elements of both stacks a and b and print "ss" */
void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr_fd("ss\n", 1);
}
