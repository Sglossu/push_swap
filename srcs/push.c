/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:17:22 by sglossu           #+#    #+#             */
/*   Updated: 2021/08/19 18:17:23 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	void	push(t_list **dst, t_list **src)
{
	t_list	*tmp;

	tmp = (*src);
	(*src) = (*src)->next;
	tmp->next = (*dst);
	(*dst) = tmp;
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
	write(1, "pb\n", 3);
}
