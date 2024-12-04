/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:19:48 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/04 13:29:27 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
//rotate B bottom -> top
