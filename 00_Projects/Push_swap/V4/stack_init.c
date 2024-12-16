/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:36:25 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/16 19:49:32 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_stack*init_stack(void)
{
	t_stack*stack=(t_stack*)malloc(sizeof(t_stack));
	if(!stack)return(NULL);
	stack->top=NULL;stack->bottom=NULL;stack->size=0;
	return(stack);
}

void	free_stack(t_stack *stack)
{
	t_node*cur; t_node*next;
	if(!stack)return;
	cur=stack->top;
	while(cur){next=cur->next;free(cur);cur=next;}
	free(stack);
}

int	push_bottom(t_stack *stack,int value)
{
	t_node*new_node=(t_node*)malloc(sizeof(t_node));
	if(!new_node)return(0);
	new_node->value=value;new_node->next=NULL;new_node->prev=stack->bottom;
	if(stack->bottom)stack->bottom->next=new_node;else stack->top=new_node;
	stack->bottom=new_node;stack->size++;
	return(1);
}
