/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haseo <haseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 00:27:16 by haseo             #+#    #+#             */
/*   Updated: 2021/10/01 18:00:21 by haseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void push_node(t_stack *stack, t_node *new)
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

static long long argtoi(char *arg)
{
    int len;
    int sign;
    long long num;

    len = 0;
    sign = 1;
    num = 0;
    if (arg[len] == '+' || arg[len] == '-')
    {
        if (arg[len] == '-')
            sign = -1;
        len++;
    }
    // 0 padding은 고려 안함
    while (arg[len])
    {
        if (!ft_isdigit(arg[len]))
            ft_exit("Error\n");
            // ft_exit("[Error] Invalid argument value\n");
        num = num * 10 + (arg[len++] - '0');
    }
    num *= sign;
    if (len > 11 || num > MAXINT || num < MININT)
        ft_exit("Error\n");
        // ft_exit("[Error] Invalid argument range\n");
    return (num);
}

static void push_arg(t_stack *stack, char *arg)
{
    char **split;
    int i;
    t_node *node;
    
    split = ft_split(arg, ' ');
    if (!split || !(*split))
        ft_exit("Error\n");
        // ft_exit("[Error] Fail to allocate split\n");
    i = -1;
    while(split[++i])
    {
        node = alloc_node();
        node->data = (int)argtoi(split[i]);
        push_node(stack, node);
        free(split[i]);
    }
    free(split);
}

void push_argv(t_stack *stack, int argc, char *argv[])
{
    int i;

    i = 0; 
    while (++i < argc)
        push_arg(stack, argv[i]);
}
