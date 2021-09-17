/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haseo <haseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 17:30:58 by haseo             #+#    #+#             */
/*   Updated: 2021/09/18 00:13:43 by haseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"
#include <stdio.h>

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

#endif