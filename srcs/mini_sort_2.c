/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:17:31 by sglossu           #+#    #+#             */
/*   Updated: 2021/08/19 18:17:32 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	void	the_first_position(t_list **lst, int count)
{
	int	count2;
	int	all;
	int	i;

	all = counter(lst);
	i = (all + 2) / 2;
	if (count <= i)
	{
		while (count-- > 1)
			ra(lst);
	}
	else
	{
		count2 = all - count + 1;
		while (count2-- > 0)
			rra(lst);
	}
}

static	void	the_first_number(t_list **lst)
{
	t_list	*tmp;
	int		count;

	count = 1;
	tmp = *lst;
	while (tmp)
	{
		if (tmp->index_scd == 1)
			break ;
		tmp = tmp->next;
		count++;
	}
	the_first_position(lst, count);
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	ft_index_second(stack_a);
	the_first_number(stack_a);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	ft_index_second(stack_a);
	the_first_number(stack_a);
	pb(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	pa(stack_a, stack_b);
}
