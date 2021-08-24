/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:11:02 by sglossu           #+#    #+#             */
/*   Updated: 2021/08/23 22:38:29 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

static	void	rotate(t_list **lst)
{
	t_list	*tmp;
	t_list	*count;

	if (*lst && (*lst)->next)
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
}

void	rb(t_list **stack_b)
{
	rotate(stack_b);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
