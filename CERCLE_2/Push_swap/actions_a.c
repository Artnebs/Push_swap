/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:19:48 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/08 13:34:54 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//swap first 2 elements of A
void	sa(t_stack *stack_a)
{
	swap(stack_a);
}

//push from B to A
void	pa(t_stack *stack_b, t_stack *stack_a)
{
	push(stack_b, stack_a);
}

//rotate A top -> bottom
void	ra(t_stack *stack_a)
{
	rotate(stack_a);
}

//rotate A bottom -> top
void	rra(t_stack *stack_a)
{
	reverse_rotate(stack_a);
}

