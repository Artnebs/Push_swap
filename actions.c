/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:24:22 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/09 21:24:23 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	sa(t_stack *a) { swap(a); ft_putstr_fd("sa\n", 1); }
void	sb(t_stack *b) { swap(b); ft_putstr_fd("sb\n", 1); }
void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	ft_putstr_fd("ss\n", 1);
}
void	pa(t_stack *b, t_stack *a) { push(b,a); ft_putstr_fd("pa\n", 1); }
void	pb(t_stack *a, t_stack *b) { push(a,b); ft_putstr_fd("pb\n", 1); }

void	ra(t_stack *a) { rotate(a); ft_putstr_fd("ra\n",1); }
void	rb(t_stack *b) { rotate(b); ft_putstr_fd("rb\n",1); }
void	rr(t_stack *a, t_stack *b) { rotate(a); rotate(b); ft_putstr_fd("rr\n",1); }
void	rra(t_stack *a) { reverse_rotate(a); ft_putstr_fd("rra\n",1); }
void	rrb(t_stack *b) { reverse_rotate(b); ft_putstr_fd("rrb\n",1); }
void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putstr_fd("rrr\n",1);
}
