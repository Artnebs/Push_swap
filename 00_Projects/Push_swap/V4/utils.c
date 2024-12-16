/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:53:25 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/16 20:25:22 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> // Add this only for debugging

int	is_sorted(t_stack *stack)
{
	t_node*c;
	if(!stack||stack->size<2)return(1);
	c=stack->top;
	while(c->next)
	{
		if(c->value>c->next->value)return(0);
		c=c->next;
	}
	return(1);
}

void	ft_free_split(char **arr)
{
	int i;
	if(!arr)return;
	i=0;
	while(arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

// Debug print function
void	print_stack(const char *name, t_stack *s)
{
	t_node *c;
	printf("%s (size=%d):", name, s?s->size:0);
	if(!s||s->size==0)
	{
		printf(" (empty)\n");
		return;
	}
	c=s->top;
	while(c)
	{
		printf(" %d", c->value);
		c=c->next;
	}
	printf("\n");
}
