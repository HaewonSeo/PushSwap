/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haseo <haseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:21:04 by haseo             #+#    #+#             */
/*   Updated: 2021/09/29 19:02:29 by haseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void sort_small_stack(t_stack *a, t_stack *b, int size)
{
    if (size <= 1)
        pa(a, b);
    else if (size == 2)
    {
        if (b->top->data < b->bottom->data)
            sb(b);
        pa(a, b);
        pa(a, b);
    }
}

static void partition(t_stack *a, t_stack *b, t_var *var, int size)
{
    int cnt_pa;

    cnt_pa = 0;
    while (size--)
    {
        if (b->top->data < var->pivot_s)
        {
            rb(b);
            var->size_s++;
        }
        else
        {
            pa(a, b);
            cnt_pa++;
            if (a->top->data < var->pivot_l)
            {
                ra(a);
                var->size_m++;
            }
        }
    }
    var->size_l = cnt_pa - var->size_m;
}

static void locate(t_stack *a, t_stack *b, t_var *var)
{
    int cnt_rrr;
    int cnt_rest;

    if (var->size_s < var->size_m)
    {
        cnt_rrr = var->size_s;
        cnt_rest = var->size_m - var->size_s;
        while (cnt_rrr--)
            rrr(a, b);
        while (cnt_rest--)
            rra(a);
    }
    else
    {
        cnt_rrr = var->size_m;
        cnt_rest = var->size_s - var->size_m;
        while (cnt_rrr--)
            rrr(a, b);
        while (cnt_rest--)
            rrb(b);
    }
}

void b_to_a(t_stack *a, t_stack *b, int size)
{
    t_var var;

    if (size <= 2)
    {
        sort_small_stack(a, b, size);
        return ;
    }
    init_var(b, &var, size);
    partition(a, b, &var, size);
    a_to_b(a, b, var.size_l);
    locate(a, b, &var);
    a_to_b(a, b, var.size_m);
    b_to_a(a, b, var.size_s);
}