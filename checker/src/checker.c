/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haseo <haseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 23:44:27 by haseo             #+#    #+#             */
/*   Updated: 2021/10/02 14:43:00 by haseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

static void	do_operation(t_stack *a, t_stack *b, char *line)
{
	if (ft_strcmp(line, "pa") == 0)
		pa(a, b);
	else if (ft_strcmp(line, "pb") == 0)
		pb(a, b);
	else if (ft_strcmp(line, "sa") == 0)
		sa(a);
	else if (ft_strcmp(line, "sb") == 0)
		sb(b);
	else if (ft_strcmp(line, "ss") == 0)
		ss(a, b);
	else if (ft_strcmp(line, "ra") == 0)
		ra(a);
	else if (ft_strcmp(line, "rb") == 0)
		rb(b);
	else if (ft_strcmp(line, "rr") == 0)
		rr(a, b);
	else if (ft_strcmp(line, "rra") == 0)
		rra(a);
	else if (ft_strcmp(line, "rrb") == 0)
		rrb(b);
	else if (ft_strcmp(line, "rrr") == 0)
		rrr(a, b);
	else
		ft_exit("Error\n");
}

void	check(t_stack *a, t_stack *b)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		do_operation(a, b, line);
		free(line);
	}
	free(line);
	if (valid_a_sort(a, a->size) && b->size == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	if (argc == 1)
		return (0);
	init_stack(&a);
	init_stack(&b);
	push_argv(&a, argc, argv);
	if (valid_dup(&a))
		ft_exit("Error\n");
	// if (valid_a_sort(&a, a.size))
	// {
	// 	return (0);
	// }
	check(&a, &b);
	free_nodes(&a);
	free_nodes(&b);
	return (0);
}
