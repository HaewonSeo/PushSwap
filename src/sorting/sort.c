/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haseo <haseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:58:38 by haseo             #+#    #+#             */
/*   Updated: 2021/09/29 17:22:50 by haseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int get_max(t_stack *stack, int size)
{
    t_node *cur;
    int max;

    cur = stack->top;
    max = MININT;
    while (size-- && cur)
    {
        if (cur->data > max)
            max = cur->data;
        cur = cur->next;
    }
    return (max);
}

static int get_min(t_stack *stack, int size)
{
    t_node *cur;
    int min;

    cur = stack->top;
    min = MAXINT;
    while (size-- && cur)
    {
        if (cur->data < min)
            min = cur->data;
        cur = cur->next;
    }
    return (min);
}

void init_var(t_stack *stack, t_var *var, int size)
{
    int max;
    int min;

    var->size_l = 0;
    var->size_m = 0;
    var->size_s = 0;
    // 정확히 3등분도 시도해보기
    max = get_max(stack, size);
    min = get_min(stack, size);
    var->pivot_l = (max + min) / 2;
    var->pivot_s = (min + var->pivot_l) / 2;
}

void sort(t_stack *a, t_stack *b)
{
    a_to_b(a, b, a->size);
}