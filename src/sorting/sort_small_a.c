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

void	sort_a_two(t_stack *a)
{
	if (a->top->data > a->top->next->data)
		sa(a);
}

static void	sort_a_only_three(t_stack *a, int min, int max)
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

static void	sort_a_not_only_three(t_stack *a, int min, int max)
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

void	sort_a_three(t_stack *a)
{
	int	min;
	int	max;

	min = get_min(a, 3);
	max = get_max(a, 3);
	if (a->size == 3)
		sort_a_only_three(a, min, max);
	else
		sort_a_not_only_three(a, min, max);
}

void	sort_small_a(t_stack *a, t_stack *b, int size)
{
	if (size <= 1)
		return ;
	else if (size == 2)
		sort_a_two(a);
	else if (size == 3)
		sort_a_three(a);
	else if (size == 4)
	{
		divide_a_four(a, b, 4);
		sort_a_two(a);
		sort_b_two(a, b);
	}
	else if (size == 5)
	{
		divide_a_five(a, b, 5);
		sort_a_three(a);
		sort_b_two(a, b);
	}
}
