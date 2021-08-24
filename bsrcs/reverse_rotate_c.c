/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_c.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:11:00 by sglossu           #+#    #+#             */
/*   Updated: 2021/08/23 22:34:11 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

static	void	reverse_rotate(t_list **lst)
{
	t_list	*tmp;
	t_list	*count;
	t_list	*tmp2;

	count = *lst;
	if (count && count->next)
	{
		while (count->next->next)
			count = count->next;
		tmp = count->next;
		count->next = NULL;
		tmp2 = *lst;
		*lst = tmp;
		(*lst)->next = tmp2;
	}
}

void	rra(t_list **stack_a)
{
	reverse_rotate(stack_a);
}

void	rrb(t_list **stack_b)
{
	reverse_rotate(stack_b);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
