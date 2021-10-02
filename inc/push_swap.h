/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haseo <haseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 17:30:58 by haseo             #+#    #+#             */
/*   Updated: 2021/10/02 01:51:57 by haseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include	"../libft/libft.h"

# define MAXINT		2147483647
# define MININT		-2147483648

typedef struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	int				size;
	t_node			*top;
	t_node			*bottom;
}					t_stack;

typedef struct s_var
{
	int				size_l;
	int				size_m;
	int				size_s;
	int				pivot_l;
	int				pivot_s;
}					t_var;

/*
**	Validation
*/

void			push_argv(t_stack *stack, int argc, char *argv[]);
int				valid_dup(t_stack *stack);
int				valid_a_sort(t_stack *a, int size);
int				valid_b_sort(t_stack *b, int size);

/*
**	Operation
*/

void			pa(t_stack *a, t_stack *b);
void			pb(t_stack *a, t_stack *b);
void			sa(t_stack *a);
void			sb(t_stack *b);
void			ss(t_stack *a, t_stack *b);
void			ra(t_stack *a);
void			rb(t_stack *b);
void			rr(t_stack *a, t_stack *b);
void			rra(t_stack *a);
void			rrb(t_stack *b);
void			rrr(t_stack *a, t_stack *b);

/*
**	Sorting
*/

int				get_mid(t_stack *stack, int size);
int				get_max(t_stack *stack, int size);
int				get_min(t_stack *stack, int size);
void			init_var(t_stack *stack, t_var *var, int size);
void			a_to_b(t_stack *a, t_stack *b, int size, int *first);
void			b_to_a(t_stack *a, t_stack *b, int size, int *first);
void			sort_small_a(t_stack *a, t_stack *b, int size);
void			sort_a_two(t_stack *a);
void			sort_a_three(t_stack *a);
void			divide_a_four(t_stack *a, t_stack *b, int size);
void			divide_a_five(t_stack *a, t_stack *b, int size);
void			sort_small_b(t_stack *a, t_stack *b, int size);
void			sort_b_two(t_stack *a, t_stack *b);
void			divide_b_four(t_stack *a, t_stack *b, int size);
void			divide_b_five(t_stack *a, t_stack *b, int size);

#endif
