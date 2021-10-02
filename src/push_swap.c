/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haseo <haseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 18:11:31 by haseo             #+#    #+#             */
/*   Updated: 2021/10/02 00:05:39 by haseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stack(t_stack *stack)
{
	stack->size = 0;
	stack->top = NULL;
	stack->bottom = NULL;
}

static void	free_nodes(t_stack *stack)
{
	t_node	*node;
	t_node	*tmp;

	node = stack->top;
	tmp = NULL;
	while (node)
	{
		if (node->next)
			tmp = node->next;
		else
			tmp = NULL;
		free(node);
		node = tmp;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	int		first;

	if (argc == 1)
		return (0);
	init_stack(&a);
	init_stack(&b);
	push_argv(&a, argc, argv);
	if (valid_dup(&a))
		ft_exit("Error\n");
	if (valid_a_sort(&a, a.size))
		return (0);
	first = 1;
	a_to_b(&a, &b, a.size, &first);
	free_nodes(&a);
	free_nodes(&b);
	return (0);
}
