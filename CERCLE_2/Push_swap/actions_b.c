/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:19:48 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/04 13:28:58 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

