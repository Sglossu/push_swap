/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:17:36 by sglossu           #+#    #+#             */
/*   Updated: 2021/08/19 18:27:59 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	counter(t_list **stack_a)
{
	t_list	*tmp;
	int		count;

	count = 1;
	tmp = *stack_a;
	while (tmp->next)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}

static	int	minimum(t_list *lst)
{
	int		min;
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->index == 0)
		{
			min = tmp->field;
			break ;
		}
		tmp = tmp->next;
	}
	while (tmp)
	{
		if (tmp->field < min && tmp->index == 0)
			min = tmp->field;
		tmp = tmp->next;
	}
	return (min);
}

void	ft_index(t_list **stack_a)
{
	t_list	*tmp;
	int		min;
	int		index;
	int		count;

	index = 1;
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
				tmp->index = index;
			tmp = tmp->next;
		}
		index++;
		count--;
	}
}
