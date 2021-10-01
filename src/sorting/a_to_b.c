/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haseo <haseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 00:31:55 by haseo             #+#    #+#             */
/*   Updated: 2021/10/01 16:09:33 by haseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

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

static void locate(t_stack *a, t_stack *b, t_var var, int first)
{
    int rest;

    if (first)
    {
        while(var.size_m--)
            rrb(b);
    }
    else if (var.size_l < var.size_m)
    {
        rest = var.size_m - var.size_l;
        while (var.size_l--)
            rrr(a, b);
        while (rest--)
            rrb(b);
    }
    else
    {
        rest = var.size_l - var.size_m;
        while (var.size_m--)
            rrr(a, b);
        while (rest--)
            rra(a);
    }
}

void sort_a_two(t_stack *a)
{
    if (a->top->data > a->top->next->data)
        sa(a);
}

void sort_small_a(t_stack *a, t_stack *b, int size)
{
    if (size <= 1)
        return ;
    else if (size == 2)
        sort_a_two(a);
    else if (size == 3)
        sort_a_three(a);
    else if (size == 4)
    {
        divide_a_four(a, b);
        sort_a_two(a);
        sort_b_two(a, b);
    }
    else if (size == 5)
    {
        divide_a_five(a, b);
        sort_a_three(a);
        sort_b_two(a, b);
    }
}

void a_to_b(t_stack *a, t_stack *b, int size, int *first)
{
    t_var var;

    if (size <= 1 || valid_a_sort(a, size))
        return ;
    if (size <= 5)
    {
        sort_small_a(a, b, size);
        return ;
    }
    init_var(a, &var, size);
    partition(a, b, &var, size);
    locate(a, b, var, *first);
    a_to_b(a, b, var.size_l, first);
    b_to_a(a, b, var.size_m, first);
    b_to_a(a, b, var.size_s, first);
}