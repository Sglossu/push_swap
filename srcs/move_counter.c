/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_counter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:17:28 by sglossu           #+#    #+#             */
/*   Updated: 2021/08/19 18:17:29 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_struct	move_a(t_list **stack_a, int index, t_struct psw)
{
	t_list	*tmp_a;

	tmp_a = *stack_a;
	psw.i_a = (psw.count_a + 1) / 2;
	psw.push_a = 0;
	psw.a_perv = 0;
	while (tmp_a)
	{
		psw.push_a++;
		if (tmp_a->next && (tmp_a->index < index && tmp_a->next->index > index))
			break ;
		tmp_a = tmp_a->next;
	}
	psw.a_perv = psw.push_a;
	psw.ra_perv = psw.count_a - psw.a_perv;
	return (psw);
}

t_struct	move_b(int index_b, t_struct psw)
{
	psw.push_b = 0;
	psw.i_b = (psw.count_b + 1) / 2;
	psw.b_perv = index_b - 1;
	psw.rb_perv = psw.count_b - psw.b_perv ;
	return (psw);
}

static	void	index_ab(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		k;

	k = 1;
	tmp = *stack_b;
	while (tmp)
	{
		tmp->index_ab = k;
		tmp = tmp->next;
		k++;
	}
	tmp = *stack_a;
	k = 0;
	while (tmp)
	{
		tmp->index_ab = k;
		tmp = tmp->next;
		k++;
	}
}

t_struct	move_counter(t_list **stack_a, t_list **stack_b, t_struct psw)
{
	psw.count_a = counter(stack_a);
	psw.count_b = counter(stack_b);
	index_ab(stack_a, stack_b);
	psw.index_b = (*stack_b)->index;
	psw = minimum_push(stack_a, stack_b, psw);
	return (psw);
}
