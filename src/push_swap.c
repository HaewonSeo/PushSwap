/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haseo <haseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 18:11:31 by haseo             #+#    #+#             */
/*   Updated: 2021/09/26 00:01:29 by haseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

long long argtoi(char *arg)
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
            ft_exit("[Error] Invalid argument value\n");
        num = num * 10 + (arg[len++] - '0');
    }
    num *= sign;
    if (len > 11 || num > MAXINT || num < MININT)
        ft_exit("[Error] Invalid argument range\n");
    return (num);
}

t_stack *alloc_stack(void)
{
    t_stack *stack;

    stack = (t_stack *)malloc(sizeof(t_stack));
    if (!stack)
        ft_exit("[Error] fail to allocate a stack\n");
    stack->size = 0;
    stack->top = NULL;
    stack->bottom = NULL;
    return (stack);
}

t_node *alloc_node(void)
{
    t_node *node;
    
    node = (t_node *)malloc(sizeof(t_node));
    if (!node)
        ft_exit("[Error] fail to allocate a node\n");
    node->data = 0;
    node->prev = NULL;
    node->next = NULL; 
    return (node);
}

void push_node(t_stack *stack, t_node *new)
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

void push_arg(t_stack *stack, char *arg)
{
    char **split;
    int i;
    t_node *node;
    
    split = ft_split(arg, ' ');
    if (!split || !(*split))
        ft_exit("[Error] Fail to allocate split\n");
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

void print_stack(t_stack *stack)
{
    t_node *cur;

    cur = stack->top;
    while (cur)
    {
        ft_putchar_fd('[', 1);
        ft_putnbr_fd(cur->data, 1);
        ft_putstr("]\t");
        cur = cur->next;
    }
    printf("\ntop:\t%d \nbottom:\t%d \nsize:\t%d\n", stack->size, stack->top->data, stack->bottom->data);
}

void free_stack(t_stack *stack)
{
    t_node *node;
    t_node *tmp;

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
    free(stack);
}

void valid_dup(t_stack *stack)
{
    t_node *cur;
    t_node *tmp;

    cur = stack->top;
    while (cur->next)
    {
        tmp = cur->next;
        while (tmp)
        {
            if (cur->data == tmp->data)
                ft_exit("[Error] Duplicate data exists in stack\n");
            tmp = tmp->next;
        }
        cur = cur->next;
    }
}

void valid_sort(t_stack *stack)
{
    t_node *cur;

    cur = stack->top;
    while (cur->next)
    {
        if (cur->data >= cur->next->data)
            return ;
        cur = cur->next;
    }
    ft_exit("[Error] Stack is already sorted\n");
}

static void test(t_stack *a, t_stack *b)
{
    sa(a);
    print_stack(a);

    pb(a, b);
    pb(a, b);
    pb(a, b);
    print_stack(a);
    print_stack(b);

    rr(a, b);
    print_stack(a);
    print_stack(b);

    rrr(a, b);
    print_stack(a);
    print_stack(b);
}

int main(int argc, char *argv[])
{
    t_stack *a;
    t_stack *b;
    
    if (argc == 1)
        ft_exit("[Usage] ./push_swap arguments\n");
        
    a = alloc_stack();
    push_argv(a, argc, argv);
    print_stack(a); //
    valid_dup(a);
    valid_sort(a);
    b = alloc_stack();

    test(a, b);

    //push_swap();
    
    free_stack(a);
    free_stack(b);
    return (0);
}