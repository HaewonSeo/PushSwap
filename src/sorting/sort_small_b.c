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

void	sort_b_two(t_stack *a, t_stack *b)
{
	if (b->top->data < b->top->next->data)
		sb(b);
	pa(a, b);
	pa(a, b);
}

static void	sort_b_only_three(t_stack *b, int min, int max)
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

static void	sort_b_not_only_three(t_stack *b, int min, int max)
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

static void	sort_b_three(t_stack *a, t_stack *b)
{
	int	min;
	int	max;

	min = get_min(b, 3);
	max = get_max(b, 3);
	if (b->size == 3)
		sort_b_only_three(b, min, max);
	else
		sort_b_not_only_three(b, min, max);
	pa(a, b);
	pa(a, b);
	pa(a, b);
}

void	sort_small_b(t_stack *a, t_stack *b, int size)
{
	if (size == 1)
		pa(a, b);
	else if (size == 2)
		sort_b_two(a, b);
	else if (size == 3)
		sort_b_three(a, b);
	else if (size == 4)
	{
		divide_b_four(a, b, 4);
		sort_a_two(a);
		sort_b_two(a, b);
	}
	else if (size == 5)
	{
		divide_b_five(a, b, 5);
		sort_a_three(a);
		sort_b_two(a, b);
	}
}
