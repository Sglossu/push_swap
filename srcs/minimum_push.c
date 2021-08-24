/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimum_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:17:29 by sglossu           #+#    #+#             */
/*   Updated: 2021/08/19 18:50:57 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	int	max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

static	void	write_right_moves(t_struct *psw, int mode)
{
	psw->ra = psw->a_perv;
	psw->rra = psw->ra_perv;
	psw->rb = psw->b_perv;
	psw->rrb = psw->rb_perv;
	psw->mode = mode;
}

static	int	min_min_min(t_struct *psw, int min)
{
	if (max(psw->a_perv, psw->b_perv) < min)
	{
		min = max(psw->a_perv, psw->b_perv);
		write_right_moves(psw, RARB);
	}
	if (psw->a_perv + psw->rb_perv < min)
	{
		min = psw->a_perv + psw->rb_perv;
		write_right_moves(psw, RARRB);
	}
	if (psw->ra_perv + psw->b_perv < min)
	{
		min = psw->ra_perv + psw->b_perv;
		write_right_moves(psw, RRARB);
	}
	if (max(psw->ra_perv, psw->rb_perv) < min)
	{
		min = max(psw->ra_perv, psw->rb_perv);
		write_right_moves(psw, RRARRB);
	}
	return (min);
}

static	t_struct	min_psh_ut(t_list **stack_a, t_list **stack_b, t_struct psw)
{
	t_list	*tmp_b;
	int		min;

	tmp_b = *stack_b;
	min = psw.count_a + psw.count_b;
	while (tmp_b)
	{
		psw = move_b(tmp_b->index_ab, psw);
		psw = move_a(stack_a, tmp_b->index, psw);
		min = min_min_min(&psw, min);
		tmp_b = tmp_b->next;
	}
	return (psw);
}

t_struct	minimum_push(t_list **stack_a, t_list **stack_b, t_struct psw)
{
	if ((*stack_b)->index == 16)
		 (*stack_b)->index = 16;
	psw = min_psh_ut(stack_a, stack_b, psw);
	return (psw);
}
