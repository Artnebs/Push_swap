/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:27:35 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/09 21:27:37 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
  get_insert_position:
  Find where target_value should be placed in A to keep A sorted ascending.
  We find the spot just before the first element larger than target_value.
*/
int	get_insert_position(t_stack *a, int val)
{
	t_node *c;
	int pos = 0;
	if (a->size == 0)
		return (0);
	c = a->top;
	while (c)
	{
		if (c->value > val)
			return (pos);
		pos++;
		c = c->next;
	}
	return (pos);
}
