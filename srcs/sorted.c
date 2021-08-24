/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:51:13 by sglossu           #+#    #+#             */
/*   Updated: 2021/08/19 18:51:14 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	if_ordered(t_list **stack_a)
{
	t_list	*tmp;
	int		count;

	tmp = *stack_a;
	count = 1;
	while (tmp->next)
	{
		if (tmp->next->field > tmp->field)
			tmp = tmp->next;
		else
			return (count);
		count++;
	}
	return (count);
}

void	sorted(t_list **stack_a, t_list **stack_b)
{
	int		count;

	count = counter(stack_a);
	if (if_ordered(stack_a) == count)
		return ;
	ft_index(stack_a);
	if (count == 2)
		sort_two(stack_a);
	else if (count == 3)
		sort_three(stack_a);
	else if (count == 4)
		sort_four(stack_a, stack_b);
	else if (count == 5)
		sort_five(stack_a, stack_b);
	else
		big_sort(stack_a, stack_b, count);
}
