/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:37:46 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/16 19:50:23 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_node*first; t_node*second;
	if(!stack||stack->size<2)return;
	first=stack->top;second=first->next;
	first->next=second->next;
	if(second->next)second->next->prev=first;
	second->prev=NULL;second->next=first;first->prev=second;
	stack->top=second;if(stack->size==2)stack->bottom=first;
}

void	push(t_stack *src,t_stack *dest)
{
	t_node*n;
	if(!src||src->size==0)return;
	n=src->top;src->top=n->next;
	if(src->top)src->top->prev=NULL;else src->bottom=NULL;
	n->next=dest->top;if(dest->top)dest->top->prev=n;else dest->bottom=n;
	dest->top=n;src->size--;dest->size++;
}

void	rotate(t_stack *stack)
{
	t_node*top; t_node*bot;
	if(!stack||stack->size<2)return;
	top=stack->top;bot=stack->bottom;
	stack->top=top->next;stack->top->prev=NULL;
	bot->next=top;top->prev=bot;top->next=NULL;
	stack->bottom=top;
}

void	reverse_rotate(t_stack *stack)
{
	t_node*top; t_node*bot;
	if(!stack||stack->size<2)return;
	top=stack->top;bot=stack->bottom;
	stack->bottom=bot->prev;stack->bottom->next=NULL;
	bot->prev=NULL;bot->next=top;top->prev=bot;
	stack->top=bot;
}
