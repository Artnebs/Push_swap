/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:19:48 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/08 13:34:49 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//swap first 2 elements of B
void sb(t_stack *stack_b)
{
	swap(stack_b);
}

//push from A to B
void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
}

//rotate B top -> bottom
void	rb(t_stack *stack_b)
{
	rotate(stack_b);
}

//rotate B bottom -> top
void	rrb(t_stack *stack_b)
{
	reverse_rotate(stack_b);
}

