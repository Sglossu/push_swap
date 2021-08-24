/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:10:35 by sglossu           #+#    #+#             */
/*   Updated: 2021/08/23 22:37:44 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

static	void	push(t_list **dst, t_list **src)
{
	t_list	*tmp;

	tmp = (*src);
	if (tmp && tmp->next)
	{
		*src = (*src)->next;
		tmp->next = (*dst);
		(*dst) = tmp;
	}
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
}
