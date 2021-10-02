/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haseo <haseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 23:43:39 by haseo             #+#    #+#             */
/*   Updated: 2021/10/02 14:45:28 by haseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include	"../../libft/libft.h"

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
**	Checking
*/

void			check(t_stack *a, t_stack *b);

#endif
