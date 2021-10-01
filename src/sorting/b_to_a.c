/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haseo <haseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:21:04 by haseo             #+#    #+#             */
/*   Updated: 2021/10/01 16:12:40 by haseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void partition(t_stack *a, t_stack *b, t_var *var, int size)
{
    int cnt_pa;

    cnt_pa = 0;
    while (size--)
    {
        if (b->top->data <= var->pivot_s)
        {
            rb(b);
            var->size_s++;
        }
        else
        {
            pa(a, b);
            cnt_pa++;
            if (a->top->data <= var->pivot_l)
            {
                ra(a);
                var->size_m++;
            }
        }
    }
    var->size_l = cnt_pa - var->size_m;
}

static void locate(t_stack *a, t_stack *b, t_var var)
{
    int rest;

    if (var.size_s < var.size_m)
    {
        rest = var.size_m - var.size_s;
        while (var.size_s--)
            rrr(a, b);
        while (rest--)
            rra(a);
    }
    else
    {
        rest = var.size_s - var.size_m;
        while (var.size_m--)
            rrr(a, b);
        while (rest--)
            rrb(b);
    }
}

void sort_b_two(t_stack *a, t_stack *b)
{
    if (b->top->data < b->top->next->data)
        sb(b);
    pa(a, b);
    pa(a, b);
}

void sort_small_b(t_stack *a, t_stack *b, int size)
{
    if (size == 1)
        pa(a, b);
    else if (size == 2)
        sort_b_two(a, b);
    else if (size == 3)
        sort_b_three(a, b);
    else if (size == 4)
    {
        divide_b_four(a, b);
        sort_a_two(a);
        sort_b_two(a, b);
    }
    else if (size == 5)
    {
        divide_b_five(a, b);
        sort_a_three(a);
        sort_b_two(a, b);
    }
}

void b_to_a(t_stack *a, t_stack *b, int size, int *first)
{
    t_var var;
    
    *first = 0;
    if (size == 0)
        return ;
    if (valid_b_sort(b, size))
    {
        while (size--)
            pa(a, b);
        return ;
    }
    if (size <= 5)
    {
        sort_small_b(a, b, size);
        return ;
    }
    init_var(b, &var, size);
    partition(a, b, &var, size);
    a_to_b(a, b, var.size_l, first);
    locate(a, b, var);
    a_to_b(a, b, var.size_m, first);
    b_to_a(a, b, var.size_s, first);
}