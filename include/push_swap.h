/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:11:19 by sglossu           #+#    #+#             */
/*   Updated: 2021/08/19 19:03:10 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"

# define RARB	0
# define RARRB	1
# define RRARB	2
# define RRARRB	3

typedef struct s_list {
	int				field;
	int				index;
	int				index_scd;
	int				index_ab;
	struct s_list	*next;
}				t_list;

typedef struct s_struct
{
	int	count_a;
	int	count_b;
	int	push_a;
	int	push_b;
	int	i_a;
	int	i_b;
	int	index_b;
	int	a_perv;
	int	b_perv;
	int	ra_perv;
	int	rb_perv;
	int	min_ord;
	int	max_ord;
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
	int	mode;
}				t_struct;

void		ft_putstr(char *s);
void		sa(t_list **lst);
void		sb(t_list **lst);
void		ss(t_list **lst_a, t_list **lst_b);
void		pa(t_list **stack_a, t_list **stack_b);
void		pb(t_list **stack_a, t_list **stack_b);
void		ra(t_list **stack_a);
void		rb(t_list **stack_b);
void		rr(t_list **stack_a, t_list **stack_b);
void		rra(t_list **stack_a);
void		rrb(t_list **stack_b);
void		rrr(t_list **stack_a, t_list **stack_b);
int			if_numbers(char **argv, int i);
void		sorted(t_list **stack_a, t_list **stack_b);
int			counter(t_list **stack_a);
void		ft_index(t_list **stack_a);
void		ft_index_second(t_list **stack_a);
int			if_ordered(t_list **stack_a);
void		sort_two(t_list **lst);
void		sort_three(t_list **lst);
void		sort_four(t_list **stack_a, t_list **stack_b);
void		sort_five(t_list **stack_a, t_list **stack_b);
void		big_sort(t_list **stack_a, t_list **stack_b, int count_all);
t_struct	move_counter(t_list **stack_a, t_list **stack_b, t_struct psw);
t_struct	init_struct(t_struct psw);
void		moving_ba(t_list **stack_a, t_list **stack_b, t_struct psw);
t_struct	max_ordered(t_list	**stack_a, t_struct psw);
void		error(int	err);
void		f_few(t_list **stack_a, t_list **stack_b, int count, t_struct psw);
t_struct	minimum_push(t_list **stack_a, t_list **stack_b, t_struct psw);
t_struct	move_b(int index_b, t_struct psw);
t_struct	move_a(t_list **stack_a, int index, t_struct psw);
t_struct	double_rotate(t_list **stack_a, t_list **stack_b, t_struct psw);

#endif
