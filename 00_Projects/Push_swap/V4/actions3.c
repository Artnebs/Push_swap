/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:38:57 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/16 19:51:16 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	rr(t_stack*a,t_stack*b){rotate(a);rotate(b);ft_putstr_fd("rr\n",1);}
void	rra(t_stack*a){reverse_rotate(a);ft_putstr_fd("rra\n",1);}
void	rrb(t_stack*b){reverse_rotate(b);ft_putstr_fd("rrb\n",1);}
void	rrr(t_stack*a,t_stack*b){reverse_rotate(a);reverse_rotate(b);ft_putstr_fd("rrr\n",1);}
