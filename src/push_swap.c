/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haseo <haseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 18:11:31 by haseo             #+#    #+#             */
/*   Updated: 2021/09/26 00:29:47 by haseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

static void print_stack(t_stack *stack)
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

    //sort();
    
    free_stack(a);
    free_stack(b);
    return (0);
}