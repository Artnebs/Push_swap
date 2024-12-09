/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:23:40 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/09 21:23:43 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack *st = malloc(sizeof(t_stack));
	if (!st)
		return (NULL);
	st->top = NULL;
	st->bottom = NULL;
	st->size = 0;
	return (st);
}

void	free_stack(t_stack *stack)
{
	t_node *c;
	t_node *n;

	if (!stack)
		return;
	c = stack->top;
	while (c)
	{
		n = c->next;
		free(c);
		c = n;
	}
	free(stack);
}
