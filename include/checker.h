/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:11:22 by sglossu           #+#    #+#             */
/*   Updated: 2021/08/19 18:11:23 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_list {
	int				field;
	int				index;
	int				index_scd;
	int				index_ab;
	struct s_list	*next;
}				t_list;

typedef struct s_list_c {
	char			*field;
	struct s_list_c	*next;
}				t_list_c;

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
void		checker_cont(t_list **stack_a, t_list **stack_b);
int			if_ordered(t_list **stack_a);
void		error(int	err);
void		push_swap_check(t_list **stack_a, t_list **stack_b, t_list_c **com);

#endif
