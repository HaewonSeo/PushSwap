/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haseo <haseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 12:15:55 by haseo             #+#    #+#             */
/*   Updated: 2021/09/30 20:52:30 by haseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int valid_dup(t_stack *stack)
{
    t_node *cur;
    t_node *tmp;

    cur = stack->top;
    while (cur->next)
    {
        tmp = cur->next;
        while (tmp)
        {
            if (cur->data == tmp->data)
                return (1);
                //ft_exit("[Error] Duplicate data exists in stack\n");
            tmp = tmp->next;
        }
        cur = cur->next;
    }
    return (0);
}

int valid_a_sort(t_stack *a, int size)
{
    t_node *cur;

    cur = a->top;
    size--;
    while (cur->next && size--)
    {
        if (cur->data >= cur->next->data)
            return (0);
        cur = cur->next;
    }
    return (1);
    //ft_exit("[Error] Stack is already sorted\n");
}

int valid_b_sort(t_stack *b, int size)
{
    t_node *cur;

    cur = b->top;
    size--;
    while (cur->next && size--)
    {
        if (cur->data <= cur->next->data)
            return (0);
        cur = cur->next;
    }
    return (1);
    //ft_exit("[Error] Stack is already sorted\n");
}
