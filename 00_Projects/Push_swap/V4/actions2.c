/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:50:55 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/18 12:32:12 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Push the top node from stack b to stack a and print "pa" */
void	pa(t_stack *stack_b, t_stack *stack_a)
{
	push(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}

/* Push the top node from stack a to stack b and print "pb" */
void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}

/* Rotate stack a and print "ra" */
void	ra(t_stack *stack_a)
{
	rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
}

/* Rotate stack b and print "rb" */
void	rb(t_stack *stack_b)
{
	rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
}
