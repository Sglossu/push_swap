/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:17:08 by sglossu           #+#    #+#             */
/*   Updated: 2021/08/19 18:17:09 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	void	swap(t_list **lst)
{
	t_list	*tmp;

	tmp = (*lst)->next;
	(*lst)->next = (*lst)->next->next;
	tmp->next = *lst;
	*lst = tmp;
}

void	sa(t_list **lst)
{
	swap(lst);
	write(1, "sa\n", 3);
}

void	sb(t_list **lst)
{
	swap(lst);
	write(1, "sb\n", 3);
}

void	ss(t_list **lst_a, t_list **lst_b)
{
	swap(lst_a);
	swap(lst_b);
	write(1, "ss\n", 3);
}
