/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haseo <haseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 00:58:11 by haseo             #+#    #+#             */
/*   Updated: 2021/10/01 16:56:43 by haseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void sort_only_three(t_stack *b, int min, int max)
{
    if (b->top->data == min)
    {
        rb(b);
        if (b->top->data != max)
            sb(b);
    }
    else if (b->top->next->data == min)
    {
        rrb(b);
        if (b->top->data != max)
            sb(b);
    }
    else if (b->top->next->next->data == min)
        sb(b);
}

static void sort_three(t_stack *b, int min, int max)
{
    if (b->top->data == min)
    {
        sb(b);
        rb(b);
        sb(b);
        rrb(b);
        if (b->top->data != max)
            sb(b);
    }
    else if (b->top->next->data == min)
    {
        rb(b);
        sb(b);
        rrb(b);
        if (b->top->data != max)
            sb(b);
    }
    else if (b->top->next->next->data == min)
        sb(b);
}

void sort_b_three(t_stack *a, t_stack *b)
{
    int min;
    int max;

    min = get_min(b, 3);
    max = get_max(b, 3);
    if (b->size == 3)
        sort_only_three(b, min, max);
    else
        sort_three(b, min, max);
    pa(a, b);
    pa(a, b);
    pa(a, b);     
}

void divide_b_four(t_stack *a, t_stack *b)
{
    int i;
    int mid;
    int cnt_pa;
    int cnt_rb;

    i = 4;
    mid = get_mid(b, 4);
    cnt_pa = 0;
    cnt_rb = 0;
    while (i-- && cnt_pa < 2)
    {
        if (b->top->data >= mid)
        {
            pa(a, b);
            cnt_pa++;
        }
        else
        {
            rb(b);
            cnt_rb++;
        }
    }
    if (b->size != 2)
    {
        while (cnt_rb--)
            rrb(b);
    }
}

void divide_b_five(t_stack *a, t_stack *b)
{
    int i;
    int mid;
    int cnt_pa;
    int cnt_rb;

    i = 5;
    mid = get_mid(b, 5);
    cnt_pa = 0;
    cnt_rb = 0;
    while (i-- && cnt_pa < 3)
    {
        if (b->top->data >= mid)
        {
            pa(a, b);
            cnt_pa++;
        }
        else
        {
            rb(b);
            cnt_rb++;
        }
    }
    if (b->size != 2)
    {
        while (cnt_rb--)
            rrb(b);
    }
}

