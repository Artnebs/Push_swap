/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:24:12 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/09 21:24:14 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *st)
{
	t_node *f, *s;
	if (!st || st->size < 2)
		return;
	f = st->top;
	s = f->next;
	f->next = s->next;
	if (s->next)
		s->next->prev = f;
	s->prev = NULL;
	s->next = f;
	f->prev = s;
	st->top = s;
	if (st->size == 2)
		st->bottom = f;
}

void	push(t_stack *src, t_stack *dest)
{
	t_node *n;
	if (!src || src->size == 0)
		return;
	n = src->top;
	src->top = n->next;
	if (src->top)
		src->top->prev = NULL;
	else
		src->bottom = NULL;
	n->next = dest->top;
	if (dest->top)
		dest->top->prev = n;
	else
		dest->bottom = n;
	dest->top = n;
	src->size--;
	dest->size++;
}

void	rotate(t_stack *st)
{
	t_node *t, *b;
	if (!st || st->size < 2)
		return;
	t = st->top;
	b = st->bottom;
	st->top = t->next;
	st->top->prev = NULL;
	b->next = t;
	t->prev = b;
	t->next = NULL;
	st->bottom = t;
}

void	reverse_rotate(t_stack *st)
{
	t_node *t, *b;
	if (!st || st->size < 2)
		return;
	t = st->top;
	b = st->bottom;
	st->bottom = b->prev;
	st->bottom->next = NULL;
	b->prev = NULL;
	b->next = t;
	t->prev = b;
	st->top = b;
}
