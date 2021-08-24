/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:11:04 by sglossu           #+#    #+#             */
/*   Updated: 2021/08/23 22:37:12 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

static	void	swap(t_list **lst)
{
	t_list	*tmp;
	
	tmp = *lst;
	if (tmp && tmp->next)
	{
		tmp = (*lst)->next;
		(*lst)->next = (*lst)->next->next;
		tmp->next = *lst;
		*lst = tmp;
	}
}

void	sa(t_list **lst)
{
	swap(lst);
}

void	sb(t_list **lst)
{
	swap(lst);
}

void	ss(t_list **lst_a, t_list **lst_b)
{
	swap(lst_a);
	swap(lst_b);
}
