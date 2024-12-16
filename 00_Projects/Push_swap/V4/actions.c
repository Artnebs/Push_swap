/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:38:28 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/16 19:50:46 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	sa(t_stack *a){swap(a);ft_putstr_fd("sa\n",1);}
void	sb(t_stack *b){swap(b);ft_putstr_fd("sb\n",1);}
void	ss(t_stack *a,t_stack *b){swap(a);swap(b);ft_putstr_fd("ss\n",1);}
