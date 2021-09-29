/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haseo <haseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 18:11:31 by haseo             #+#    #+#             */
/*   Updated: 2021/09/29 18:06:35 by haseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void init_stack(t_stack *stack)
{
    stack->size = 0;
    stack->top = NULL;
    stack->bottom = NULL;
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

void free_stack_nodes(t_stack *stack)
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
}

static void print_stack(t_stack *stack)
{
    t_node *cur;

    if (stack->size == 0)
    {
        printf("stack is empty\n");
        return ;
    }
    cur = stack->top;
    while (cur)
    {
        ft_putchar_fd('[', 1);
        ft_putnbr_fd(cur->data, 1);
        ft_putstr("]\t");
        cur = cur->next;
    }
    printf("\ntop:\t%d \nbottom:\t%d \nsize:\t%d\n", stack->top->data, stack->bottom->data, stack->size);
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
    t_stack a;
    t_stack b;
    
    if (argc == 1)
        ft_exit("[Usage] ./push_swap arguments\n");
        
    init_stack(&a);
    push_argv(&a, argc, argv);
    print_stack(&a); //
    valid_dup(&a);
    valid_sort(&a);
    init_stack(&b);
    //test(&a, &b);

    sort(&a, &b);
    print_stack(&a);
    print_stack(&b);
    
    free_stack_nodes(&a);
    free_stack_nodes(&b);
    return (0);
}