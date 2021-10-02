/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haseo <haseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:21:04 by haseo             #+#    #+#             */
/*   Updated: 2021/10/02 00:06:13 by haseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	divide_b_four(t_stack *a, t_stack *b, int size)
{
	int	mid;
	int	cnt_pa;
	int	cnt_rb;

	mid = get_mid(b, 4);
	cnt_pa = 0;
	cnt_rb = 0;
	while (size-- && cnt_pa < 2)
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

void	divide_b_five(t_stack *a, t_stack *b, int size)
{
	int	mid;
	int	cnt_pa;
	int	cnt_rb;

	mid = get_mid(b, 5);
	cnt_pa = 0;
	cnt_rb = 0;
	while (size-- && cnt_pa < 3)
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

static void	partition_b_to_a(t_stack *a, t_stack *b, t_var *var, int size)
{
	int	cnt_pa;

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

static void	locate_b_to_a(t_stack *a, t_stack *b, t_var var)
{
	int	rest;

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

void	b_to_a(t_stack *a, t_stack *b, int size, int *first)
{
	t_var	var;

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
	partition_b_to_a(a, b, &var, size);
	a_to_b(a, b, var.size_l, first);
	locate_b_to_a(a, b, var);
	a_to_b(a, b, var.size_m, first);
	b_to_a(a, b, var.size_s, first);
}
