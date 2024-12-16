/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:40:09 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/16 19:51:33 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack*a)
{
	int v1;int v2;int v3;
	if(!a||a->size<2)return;
	if(a->size==2&&a->top->value>a->top->next->value)sa(a);
	if(a->size==3)
	{
		v1=a->top->value;v2=a->top->next->value;v3=a->bottom->value;
		if(v1>v2&&v2<v3&&v1<v3)sa(a);
		else if(v1>v2&&v2>v3){sa(a);rra(a);}
		else if(v1>v2&&v2<v3&&v1>v3)ra(a);
		else if(v1<v2&&v2>v3&&v1<v3){sa(a);ra(a);}
		else if(v1<v2&&v2>v3&&v1>v3)rra(a);
	}
}

static int get_smallest(t_stack*stack)
{
	t_node*c;int min;
	c=stack->top;min=c->value;
	while(c){if(c->value<min)min=c->value;c=c->next;}
	return(min);
}

static int get_position(t_stack*stack,int val)
{
	t_node*c;int p;
	p=0;c=stack->top;
	while(c){if(c->value==val)return(p);p++;c=c->next;}
	return(p);
}

void	sort_five(t_stack*a,t_stack*b)
{
	int sm;int pos;
	while(a->size>3)
	{
		sm=get_smallest(a);
		pos=get_position(a,sm);
		while(pos>0&&pos<=a->size/2){ra(a);pos=get_position(a,sm);}
		while(pos>a->size/2){rra(a);pos=get_position(a,sm);}
		pb(a,b);
	}
	sort_three(a);
	while(b->size>0)pa(b,a);
}
