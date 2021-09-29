/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haseo <haseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 17:30:58 by haseo             #+#    #+#             */
/*   Updated: 2021/09/29 17:40:43 by haseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"
#include <stdio.h>

#define MAXINT  2147483647
#define MININT  -2147483648

typedef struct		s_node {
    int				data;
    struct s_node	*prev;
    struct s_node	*next;
}					t_node;

typedef struct	s_stack {
    int			size;
    t_node		*top;
    t_node		*bottom;
}				t_stack;

// typedef struct  s_count {
//     int			pa;
//     int			pb;
//     int			ra;
//     int			rb;
// }				t_count;

// typedef struct	s_pivot
// {
// 	int			small;
// 	int			large;
// }				t_pivot;

typedef struct	s_var {
	int			size_l;
	int			size_m;
	int			size_s;
	int			pivot_l;
	int			pivot_s;
}				t_var;

void			init_stack(t_stack *stack);
t_node			*alloc_node(void);
void			free_stack_nodes(t_stack *stack);
void			push_argv(t_stack *stack, int argc, char *argv[]);
void			valid_dup(t_stack *stack);
void			valid_sort(t_stack *stack);

void			sa(t_stack *a);
void			sb(t_stack *b);
void			ss(t_stack *a, t_stack *b);
void			pa(t_stack *a, t_stack *b);
void			pb(t_stack *a, t_stack *b);
void			ra(t_stack *a);
void			rb(t_stack *b);
void			rr(t_stack *a, t_stack *b);
void			rra(t_stack *a);
void			rrb(t_stack *b);
void			rrr(t_stack *a, t_stack *b);


void init_var(t_stack *stack, t_var *var, int size);
void a_to_b(t_stack *a, t_stack *b, int size);
void b_to_a(t_stack *a, t_stack *b, int size);
void sort(t_stack *a, t_stack *b);

#endif