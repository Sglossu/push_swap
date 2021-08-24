/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:17:21 by sglossu           #+#    #+#             */
/*   Updated: 2021/08/19 18:17:22 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	void	reverse_rotate(t_list **lst)
{
	t_list	*tmp;
	t_list	*count;
	t_list	*tmp2;

	count = *lst;
	if (count->next)
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
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
