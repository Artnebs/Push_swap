/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:45:51 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/16 19:52:44 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_position(t_stack*s,int val)
{
	t_node*c;int p=0;c=s->top;
	while(c){if(c->value==val)return(p);p++;c=c->next;}
	return(-1);
}

static void	do_rr(t_stack*a,t_stack*b,int*ra_count,int*rb_count)
{
	while(*ra_count>0 && *rb_count>0){rr(a,b);(*ra_count)--;(*rb_count)--;}
	while(*ra_count<0 && *rb_count<0){rrr(a,b);(*ra_count)++;(*rb_count)++;}
}

static void	do_rotations(t_stack*a,t_stack*b,int*ra_count,int*rb_count)
{
	while(*ra_count>0){ra(a);(*ra_count)--;}
	while(*ra_count<0){rra(a);(*ra_count)++;}
	while(*rb_count>0){rb(b);(*rb_count)--;}
	while(*rb_count<0){rrb(b);(*rb_count)++;}
}

void	move_with_min_cost(t_stack*a,t_stack*b,int val)
{
	int ins;int pb;int ra_count;int rb_count;
	if(!a||!b||b->size==0)return;
	ins=get_insert_position(a,val);
	pb=get_position(b,val);
	ra_count=calc_rotations_for_a(a,ins);
	rb_count=calc_rotations_for_b(b,pb);
	do_rr(a,b,&ra_count,&rb_count);
	do_rotations(a,b,&ra_count,&rb_count);
	if(b->size>0)pa(b,a);
}
