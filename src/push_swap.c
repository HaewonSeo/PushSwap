/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haseo <haseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 18:11:31 by haseo             #+#    #+#             */
/*   Updated: 2021/09/18 00:19:33 by haseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void init_stack(t_stack **stack)
{
    *stack = (t_stack *)malloc(sizeof(t_stack));
    if (!(*stack))
        ft_exit("[Error] fail to allocate stack\n");
    (*stack)->size = 0;
    (*stack)->top = NULL;
    (*stack)->bottom = NULL;
    return ;  
}

void init_node(t_node **node)
{
    *node = (t_node *)malloc(sizeof(t_node));
    if (!(*node))
        return ;
    (*node)->data = 0;
    (*node)->prev = NULL;
    (*node)->next = NULL; 
    return ;
}

void push_node(t_stack **stack, t_node *node)
{
    if (!(*stack)->size)
    {
        (*stack)->top = node;
        (*stack)->bottom = node;
    }
    else
    {
        (*stack)->top->next = node;
        node->prev = (*stack)->top;
        (*stack)->top = node;        
    }
    (*stack)->size++;
}

void push_arg(t_stack **stack, char *arg)
{
    char **split;
    int i;
    t_node *node;
    
    split = ft_split(arg, ' ');
    if (!split || !(*split))
        ft_exit("[Error] fail to allocate split\n");
    i = -1;
    while(split[++i])
    {
        init_node(&node);
        node->data = ft_atoi(split[i]);
        push_node(stack, node);
        free(split[i]);
    }
    free(split);
}

void push_argv(t_stack **stack, int argc, char *argv[])
{
    int i;

    i = 0; 
    while (++i < argc)
        push_arg(stack, argv[i]);
}

void print_stack(t_stack *stack)
{
    t_node *node;

    node = stack->bottom;
    while (node->next)
    {
        ft_putnbr_fd(node->data, 1);
        ft_putchar_fd('\n', 1);
        node = node->next;
    }
}

int main(int argc, char *argv[])
{
    t_stack *sA;
    //t_stack *sB;
    
    if (argc == 1)
        ft_exit("[Usage] ./push_swap arguments\n");
    // make sA, sB

    ///check_arg(argc, argv);
    push_argv(&sA, argc, argv);
    print_stack(sA);
    // init_stack(&sA);
    // init_stack(&sB);
    return 0;
}