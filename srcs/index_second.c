/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_second.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:30:56 by sglossu           #+#    #+#             */
/*   Updated: 2021/08/19 18:30:57 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	int	minimum(t_list *lst)
{
	int		min;
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->index_scd == 0)
		{
			min = tmp->field;
			break ;
		}
		tmp = tmp->next;
	}
	while (tmp)
	{
		if (tmp->field < min && tmp->index_scd == 0)
			min = tmp->field;
		tmp = tmp->next;
	}
	return (min);
}

static	void	zero(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		tmp->index_scd = 0;
		tmp = tmp->next;
	}
}

void	ft_index_second(t_list **stack_a)
{
	t_list	*tmp;
	int		min;
	int		index_scd;
	int		count;

	zero(stack_a);
	index_scd = 1;
	tmp = *stack_a;
	count = counter(stack_a);
	while (count > 0)
	{
		tmp = *stack_a;
		min = minimum(tmp);
		tmp = *stack_a;
		while (tmp)
		{
			if (tmp->field == min)
				tmp->index_scd = index_scd;
			tmp = tmp->next;
		}
		index_scd++;
		count--;
	}
}
