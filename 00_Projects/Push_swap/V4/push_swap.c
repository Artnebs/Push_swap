/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:44:18 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/16 20:52:49 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int get_chunk_count(int size)
{
	if(size<=100)return(5);
	return(11);
}

static int count_in_chunk(t_stack*a,int minr,int maxr)
{
	t_node*c;int cnt=0;
	c=a->top;
	while(c){if(c->value>=minr&&c->value<=maxr)cnt++;c=c->next;}
	return(cnt);
}

static void apply_chunks(t_stack*a,t_stack*b,int size)
{
	int chunks;int ch_size;int i;int minr;int maxr;int count;
	chunks=get_chunk_count(size);ch_size=size/chunks;
	i=0;
	while(i<chunks)
	{
		minr=i*ch_size;
		if(i==chunks-1)maxr=size-1;else maxr=(i+1)*ch_size-1;
		count=count_in_chunk(a,minr,maxr);
		while(count>0)
		{
			if(a->top->value>=minr && a->top->value<=maxr)
			{
				pb(a,b);count--;
			}
			else ra(a);
		}
		i++;
	}
}

static int get_smallest_value(t_stack *a)
{
	t_node *c=a->top;
	int min=c->value;
	while(c){if(c->value<min)min=c->value;c=c->next;}
	return(min);
}

static int get_position_value(t_stack *a,int val)
{
	t_node*c=a->top;int p=0;
	while(c)
	{
		if(c->value==val)return(p);
		p++;c=c->next;
	}
	return(-1);
}

void	push_swap(t_stack*a,t_stack*b)
{
	int size=a->size;
	if(is_sorted(a))return;
	if(size<=3){sort_three(a);return;}
	if(size<=5){sort_five(a,b);return;}
	apply_chunks(a,b,size);

	while(b->size>0)
		move_with_min_cost(a,b,b->top->value);

	// After final insertion, if not sorted, rotate smallest to top
	if(!is_sorted(a))
	{
		int smallest = get_smallest_value(a);
		int pos = get_position_value(a, smallest);
		if(pos>=0)
		{
			// If pos ≤ half, use ra pos times
			// If pos > half, use rra until pos is 0
			if(pos <= a->size/2)
			{
				while(pos>0){ra(a);pos--;}
			}
			else
			{
				while(pos<a->size){rra(a);pos++;}
			}
		}
	}
}
