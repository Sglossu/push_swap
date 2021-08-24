/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:21:11 by sglossu           #+#    #+#             */
/*   Updated: 2021/08/19 18:51:35 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	f_few(t_list **stack_a, t_list **stack_b, int count, t_struct psw)
{
	t_list	*tmp;
	int		max;
	int		flag;

	flag = 0;
	max = count;
	tmp = *stack_a;
	while (count--)
	{
		if ((tmp->index < psw.min_ord && tmp->index > 0) || \
		(tmp->index > psw.max_ord && tmp->index < max))
		{
			if (tmp->index != 1 && tmp->index != max)
			{
				pb(stack_a, stack_b);
				if ((*stack_b)->index < (max / 2) && flag == 1)
					rb(stack_b);
				tmp = *stack_a;
				flag = 1;
				continue ;
			}
		}
		ra(stack_a);
		tmp = *stack_a;
	}
}

static	void	first_five(t_list **stack_a, t_list **stack_b, int count)
{
	t_list	*tmp;
	int		mid;
	int		max;

	tmp = *stack_a;
	max = count;
	mid = (count + 1) / 2;
	while (count > 0)
	{
		count--;
		if (tmp->index != 1 && tmp->index != max && tmp->index != mid && \
			tmp->index != 2 && tmp->index != max - 1)
		{
			pb(stack_a, stack_b);
			if ((*stack_b)->index > mid && count != max - 1)
				rb(stack_b);
			tmp = *stack_a;
			continue ;
		}
		ra(stack_a);
		tmp = *stack_a;
	}
}

static	void	sort_few(t_list **stack_a, t_struct psw)
{
	if ((*stack_a)->index == 1)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if ((*stack_a)->index == psw.min_ord)
	{
		rra(stack_a);
		if ((*stack_a)->index != 1)
		{
			rra(stack_a);
			sa(stack_a);
			ra(stack_a);
		}
	}
	else if ((*stack_a)->index == psw.count_a && (*stack_a)->next->index != 1)
	{
		rra(stack_a);
		sa(stack_a);
		ra(stack_a);
	}
	else if ((*stack_a)->index == psw.count_a && (*stack_a)->next->index == 1)
		ra(stack_a);
}

static	void	rotate_for_sorted(t_list **stack_a, int count_all)
{
	t_list	*tmp;
	int		i;

	tmp = *stack_a;
	i = (count_all + 1) / 2;
	if (tmp->index > i)
	{
		while (tmp->index != 1)
		{
			rra(stack_a);
			tmp = *stack_a;
		}
	}
	else
	{
		while (tmp->index != 1)
		{
			ra(stack_a);
			tmp = *stack_a;
		}
	}
}

void	big_sort(t_list **stack_a, t_list **stack_b, int count_all)
{
	t_struct	psw;
	int			count;

	psw.i_a = 0;
	psw = init_struct(psw);
	psw = max_ordered(stack_a, psw);
	if (psw.max_ord - psw.min_ord >= 3)
		f_few(stack_a, stack_b, count_all, psw);
	else
		first_five(stack_a, stack_b, count_all);
	if (psw.count_a > 5)
		sort_few(stack_a, psw);
	else
		sort_five(stack_a, stack_b);
	if (count_all == psw.count_a)
		return ;
	psw.count_a = counter(stack_a);
	count = counter(stack_b);
	while (count > 0)
	{
		psw = move_counter(stack_a, stack_b, psw);
		moving_ba(stack_a, stack_b, psw);
		count--;
	}
	rotate_for_sorted(stack_a, count_all);
}
