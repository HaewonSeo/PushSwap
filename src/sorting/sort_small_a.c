/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haseo <haseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 18:33:17 by haseo             #+#    #+#             */
/*   Updated: 2021/10/01 16:55:58 by haseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void sort_only_three(t_stack *a, int min, int max)
{
    if (a->top->data == min && a->top->next->data == max)
    {
        rra(a);
        sa(a);
    }
    else if (a->top->next->data == min)
    {
        if (a->top->data == max)
            ra(a);
        else
            sa(a);
    }
    else if (a->top->next->next->data == min)
    {
        if (a->top->data == max)
            sa(a);
        rra(a);
    }
}

static void sort_three(t_stack *a, int min, int max)
{
    if (a->top->data == min && a->top->next->data == max)
    {
        ra(a);
        sa(a);
        rra(a);
    }
    else if (a->top->next->data == min)
    {
        sa(a);
        if (a->top->next->data == max)
        {
            ra(a);
            sa(a);
            rra(a);
        }
    }
    else if (a->top->next->next->data == min)
    {
        if (a->top->data == max)
            sa(a);
        ra(a);
        sa(a);
        rra(a);
        sa(a);
    }
}

void sort_a_three(t_stack *a)
{
    int min;
    int max;

    min = get_min(a, 3);
    max = get_max(a, 3);
    if (a->size == 3)
        sort_only_three(a, min, max);
    else
        sort_three(a, min, max);    
}

void divide_a_four(t_stack *a, t_stack *b)
{
    int i;
    int mid;
    int cnt_pb;
    int cnt_ra;

    i = 4;
    mid = get_mid(a, 4);
    cnt_pb = 0;
    cnt_ra = 0;
    while (i-- && cnt_pb < 2)
    {
        if (a->top->data < mid)
        {
            pb(a, b);
            cnt_pb++;
        }
        else
        {
            ra(a);
            cnt_ra++;
        }
    }
    if (a->size != 2)
    {
        while (cnt_ra--)
            rra(a);
    }
}

void divide_a_five(t_stack *a, t_stack *b)
{
    int i;
    int mid;
    int cnt_pb;
    int cnt_ra;

    i = 5;
    mid = get_mid(a, 5);
    cnt_pb = 0;
    cnt_ra = 0;
    while (i-- && cnt_pb < 2)
    {
        if (a->top->data < mid)
        {
            pb(a, b);
            cnt_pb++;
        }
        else
        {
            ra(a);
            cnt_ra++;
        }
    }
    if (a->size != 3)
    {
        while (cnt_ra--)
            rra(a);
    }
}