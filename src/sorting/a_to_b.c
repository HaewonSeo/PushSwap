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

void	divide_a_four(t_stack *a, t_stack *b, int size)
{
	int	mid;
	int	cnt_pb;
	int	cnt_ra;

	mid = get_mid(a, 4);
	cnt_pb = 0;
	cnt_ra = 0;
	while (size-- && cnt_pb < 2)
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

void	divide_a_five(t_stack *a, t_stack *b, int size)
{
	int	mid;
	int	cnt_pb;
	int	cnt_ra;

	mid = get_mid(a, 5);
	cnt_pb = 0;
	cnt_ra = 0;
	while (size-- && cnt_pb < 2)
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

static void	partition_a_to_b(t_stack *a, t_stack *b, t_var *var, int size)
{
	int	cnt_pb;

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

static void	locate_a_to_b(t_stack *a, t_stack *b, t_var var, int first)
{
	int	rest;

	if (first)
	{
		while (var.size_m--)
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

void	a_to_b(t_stack *a, t_stack *b, int size, int *first)
{
	t_var	var;

	if (size <= 1 || valid_a_sort(a, size))
		return ;
	if (size <= 5)
	{
		sort_small_a(a, b, size);
		return ;
	}
	init_var(a, &var, size);
	partition_a_to_b(a, b, &var, size);
	locate_a_to_b(a, b, var, *first);
	a_to_b(a, b, var.size_l, first);
	b_to_a(a, b, var.size_m, first);
	b_to_a(a, b, var.size_s, first);
}
