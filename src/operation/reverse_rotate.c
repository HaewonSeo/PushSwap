/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haseo <haseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 21:12:09 by haseo             #+#    #+#             */
/*   Updated: 2021/09/26 00:15:32 by haseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void reverse_rotate(t_stack *stack)
{
    t_node *bottom_prev;
    
    if (stack->size <= 1)
        return ;
    bottom_prev = stack->bottom->prev;
    bottom_prev->next = NULL;
    stack->top->prev = stack->bottom;
    stack->bottom->prev = NULL;
    stack->bottom->next = stack->top;
    stack->top = stack->bottom;
    stack->bottom = bottom_prev;
}

void rra(t_stack *a)
{
    reverse_rotate(a);
    ft_putstr("ra\n");
}

void rrb(t_stack *b)
{
    reverse_rotate(b);
    ft_putstr("rb\n");
}

void rrr(t_stack *a, t_stack *b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    ft_putstr("rr\n");
}
