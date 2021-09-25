/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haseo <haseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 12:15:55 by haseo             #+#    #+#             */
/*   Updated: 2021/09/26 00:36:51 by haseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void valid_dup(t_stack *stack)
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
                ft_exit("[Error] Duplicate data exists in stack\n");
            tmp = tmp->next;
        }
        cur = cur->next;
    }
}

void valid_sort(t_stack *stack)
{
    t_node *cur;

    cur = stack->top;
    while (cur->next)
    {
        if (cur->data >= cur->next->data)
            return ;
        cur = cur->next;
    }
    ft_exit("[Error] Stack is already sorted\n");
}
