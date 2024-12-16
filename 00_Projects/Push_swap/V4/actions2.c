/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:38:43 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/16 19:50:55 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"
void	pa(t_stack*b,t_stack*a){push(b,a);ft_putstr_fd("pa\n",1);}
void	pb(t_stack*a,t_stack*b){push(a,b);ft_putstr_fd("pb\n",1);}
void	ra(t_stack*a){rotate(a);ft_putstr_fd("ra\n",1);}
void	rb(t_stack*b){rotate(b);ft_putstr_fd("rb\n",1);}
