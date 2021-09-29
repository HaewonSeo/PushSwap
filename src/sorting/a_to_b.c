/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haseo <haseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 00:31:55 by haseo             #+#    #+#             */
/*   Updated: 2021/09/29 19:02:37 by haseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void sort_small_stack(t_stack *a, int size)
{
    if (size <= 1)
        return ;
    else if (size == 2)
        if (a->top->data > a->bottom->data)
            sa(a);
}

static void partition(t_stack *a, t_stack *b, t_var *var, int size)
{
    int cnt_pb;

    cnt_pb = 0;
    while (size--)
    {
        if (a->top->data > var->pivot_l)
        {
            ra(a);
            var->size_l++;
        }
        else
        {
            pb(a, b);
            cnt_pb++;
            if (b->top->data > var->pivot_s)
            {
                rb(b);
                var->size_m++;
            }
        }
    }
    var->size_s = cnt_pb - var->size_m;
}

static void locate(t_stack *a, t_stack *b, t_var *var)
{
    int cnt_rrr;
    int cnt_rest;

    if (var->size_l < var->size_m)
    {
        cnt_rrr = var->size_l;
        cnt_rest = var->size_m - var->size_l;
        while (cnt_rrr--)
            rrr(a, b);
        while (cnt_rest--)
            rrb(b);
    }
    else
    {
        cnt_rrr = var->size_m;
        cnt_rest = var->size_l - var->size_m;
        while (cnt_rrr--)
            rrr(a, b);
        while (cnt_rest--)
            rra(a);
    }
}

void a_to_b(t_stack *a, t_stack *b, int size)
{
    t_var var;

    if (size <= 2)
    {
        sort_small_stack(a, size);
        return ;
    }
    init_var(a, &var, size);
    partition(a, b, &var, size);
    locate(a, b, &var);
    a_to_b(a, b, var.size_l);
    b_to_a(a, b, var.size_m);
    b_to_a(a, b, var.size_s);
}