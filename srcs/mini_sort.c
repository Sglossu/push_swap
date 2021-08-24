/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:17:32 by sglossu           #+#    #+#             */
/*   Updated: 2021/08/19 18:17:33 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_two(t_list **lst)
{
	if (if_ordered(lst) == 1)
		sa(lst);
}

void	sort_three(t_list **lst)
{
	int		count;
	t_list	*tmp;

	count = 2;
	ft_index_second(lst);
	while (count > 0)
	{
		tmp = (*lst);
		if (if_ordered(&tmp) == 3)
			return ;
		if (if_ordered(&tmp) == 2 && tmp->index_scd == 2)
		{
			rra(lst);
			return ;
		}
		tmp = tmp->next;
		if (if_ordered(&tmp) == 2 && tmp->next->index_scd == 2)
		{
			ra(lst);
			return ;
		}
		sa(lst);
		count--;
	}
}
