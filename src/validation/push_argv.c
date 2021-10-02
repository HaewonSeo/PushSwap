/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haseo <haseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 00:27:16 by haseo             #+#    #+#             */
/*   Updated: 2021/10/02 00:05:52 by haseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*alloc_node(void)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		ft_exit("[Error] Fail to allocate a node\n");
	node->data = 0;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

static void	valid_arg_len(char *arg)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (arg[i] == '+' || arg[i] == '-')
		i++;
	while (arg[i] == '0')
		i++;
	while (arg[i++])
		len++;
	if (len > 10)
		ft_exit("Error\n");
}

static int	arg_to_int(char *arg)
{
	int			i;
	int			sign;
	long long	num;

	valid_arg_len(arg);
	i = 0;
	sign = 1;
	num = 0;
	if (arg[i] == '+' || arg[i] == '-')
	{
		if (arg[i] == '-')
			sign = -1;
		i++;
	}
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			ft_exit("Error\n");
		num = num * 10 + (arg[i++] - '0');
	}
	num *= sign;
	if (num > MAXINT || num < MININT)
		ft_exit("Error\n");
	return ((int)num);
}

static void	push_node(t_stack *stack, t_node *new)
{
	if (!stack->size)
	{
		stack->top = new;
		stack->bottom = new;
	}
	else
	{
		stack->bottom->next = new;
		new->prev = stack->bottom;
		stack->bottom = new;
	}
	stack->size++;
}

void	push_argv(t_stack *stack, int argc, char *argv[])
{
	char	**split;
	int		i;
	int		j;
	t_node	*node;

	i = 0;
	while (++i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split || !(*split))
			ft_exit("[Error] Fail to allocate split\n");
		j = -1;
		while (split[++j])
		{
			node = alloc_node();
			node->data = arg_to_int(split[j]);
			push_node(stack, node);
			free(split[j]);
		}
		free(split);
	}
}
