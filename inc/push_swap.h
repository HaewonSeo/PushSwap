/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haseo <haseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 17:30:58 by haseo             #+#    #+#             */
/*   Updated: 2021/09/24 21:13:46 by haseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"
#include <stdio.h>

#define MAXINT  2147483647
#define MININT  -2147483648

typedef struct	s_node {
    int data;
    struct s_node *prev;
    struct s_node *next;
}				t_node;

typedef struct	s_stack {
    int size;
    t_node *top;
    t_node *bottom;
}				t_stack;


void swap(t_stack *stack);
void sa(t_stack *a);
void sb(t_stack *b);



#endif