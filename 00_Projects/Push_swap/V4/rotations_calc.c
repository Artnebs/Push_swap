/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations_calc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:52:12 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/16 20:44:20 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_insert_position(t_stack *a, int val)
{
    t_node *c;
    int min, max, pos;
    int i;

    if (!a || a->size == 0)
        return (0);

    c = a->top;
    min = c->value;
    max = c->value;
    while (c)
    {
        if (c->value < min) min = c->value;
        if (c->value > max) max = c->value;
        c = c->next;
    }

    // If val < min, we must insert at min's position to maintain ascending order.
    // If val > max, we must also insert at min's position, because val goes after max,
    // which is effectively the same as putting it before min in a circular sense.
    if (val < min || val > max)
    {
        pos = 0;
        c = a->top;
        while (c && c->value != min)
        {
            c = c->next;
            pos++;
        }
        // Insert val right before min. Since we can't literally insert before in indexing,
        // returning pos is correct because pa will place val at pos eventually.
        return (pos);
    }

    // Otherwise, find the spot between two consecutive nodes
    i = 0;
    c = a->top;
    while (c->next)
    {
        if (c->value < val && c->next->value > val)
            return (i + 1);
        c = c->next;
        i++;
    }
    // If not found, place at bottom (end)
    return (a->size);
}

int calc_rotations_for_a(t_stack*a,int p)
{
	if(!a||p<0||p>=a->size)return(0);
	if(p<=a->size/2)return(p);
	return(p-a->size);
}

int calc_rotations_for_b(t_stack*b,int p)
{
	if(!b||p<0||p>=b->size)return(0);
	if(p<=b->size/2)return(p);
	return(p-b->size);
}
