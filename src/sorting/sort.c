/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haseo <haseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:58:38 by haseo             #+#    #+#             */
/*   Updated: 2021/10/01 01:46:20 by haseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void quick_sort(int arr[], int l, int r)
{
    int s;
    int e;
    int pivot;
    int tmp;

    s = l;
    e = r;
    pivot = arr[(l + r) / 2];
    if (l >= r)
        return;
    while (s <= e)
    {
        while (arr[s] < pivot)
            s++;
        while (arr[e] > pivot)
            e--;
        if (s <= e)
        {
            tmp = arr[s];
            arr[s++] = arr[e];
            arr[e--] = tmp;
        }
    }
    quick_sort(arr, l, e);
    quick_sort(arr, s, r);
}

int get_mid(t_stack *stack, int size)
{
    int i;
    int arr[5];
    t_node *cur;

    i = -1;
    cur = stack->top;
    while (++i < size && cur)
    {
        arr[i] = cur->data;
        cur = cur->next;
    }
    quick_sort(arr, 0, size - 1);
    return (arr[2]);
}

int get_max(t_stack *stack, int size)
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

int get_min(t_stack *stack, int size)
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
    var->pivot_s = (max + 2 * min) / 3;
    var->pivot_l = (2 * max + min) / 3;
    // var->pivot_l = (max + min) / 2;
    // var->pivot_s = (min + var->pivot_l) / 2;
    // var->pivot_s = (max + min) / 2;
    // var->pivot_l = (max + var->pivot_s) / 2;
    //printf("pivot_s=%d, pivot_l=%d\n", var->pivot_s, var->pivot_l);
}