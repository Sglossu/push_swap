/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:17:18 by sglossu           #+#    #+#             */
/*   Updated: 2021/08/19 18:30:33 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	void	rotate(t_list **lst)
{
	t_list	*tmp;
	t_list	*count;

	if ((*lst)->next)
	{
		tmp = (*lst);
		(*lst) = (*lst)->next;
		tmp->next = NULL;
		count = (*lst);
		while (count->next)
			count = count->next;
		count->next = tmp;
	}
}

void	ra(t_list **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_list **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
