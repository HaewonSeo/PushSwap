/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haseo <haseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 21:12:20 by haseo             #+#    #+#             */
/*   Updated: 2021/09/25 22:54:29 by haseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	rotate(t_stack *stack)
{
	t_node	*second;

	if (stack->size <= 1)
		return ;
	second = stack->top->next;
	second->prev = NULL;
	stack->bottom->next = stack->top;
	stack->top->prev = stack->bottom;
	stack->top->next = NULL;
	stack->bottom = stack->top;
	stack->top = second;
}

void	ra(t_stack *a)
{
	rotate(a);
	ft_putstr("ra\n");
}

void	rb(t_stack *b)
{
	rotate(b);
	ft_putstr("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_putstr("rr\n");
}
