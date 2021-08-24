/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:17:15 by sglossu           #+#    #+#             */
/*   Updated: 2021/08/23 22:18:36 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	if_numbers(char **argv, int i)
{
	int	j;

	while (argv[i])
	{
		j = 0;
		if (argv[i][0] == '-' && ft_isdigit(argv[i][1]) == 1 \
		&& argv[i][1] != '0')
			j++;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int	max_ordered_utils(t_list **tmp, int k)
{
	while ((*tmp)->next && ((*tmp)->index + 1 == (*tmp)->next->index))
	{
		*tmp = (*tmp)->next;
		k++;
	}
	return (k);
}

t_struct	max_ordered(t_list **stack_a, t_struct psw)
{
	t_list	*tmp;
	int		k;
	int		max_k;
	int		min_k;

	max_k = 1;
	min_k = 1;
	tmp = *stack_a;
	while (tmp->next)
	{
		k = 1;
		min_k = tmp->index;
		k = max_ordered_utils(&tmp, k);
		if (k > max_k)
		{
			max_k = k;
			psw.min_ord = min_k;
		}
		if (tmp->next)
			tmp = tmp->next;
	}
	psw.max_ord = psw.min_ord + max_k - 1;
	return (psw);
}

void	error(int err)
{
	if (err == -1)
		ft_putstr_fd("Not enough arguments. Error.\n", 1);
	if (err == -2)
		ft_putstr_fd("Not only numbers. Error.\n", 1);
	if (err == -3)
		ft_putstr_fd("Repeat values. Error.\n", 1);
	if (err == -4)
		ft_putstr_fd("Not int values. Error.\n", 1);
	if (err == -5)
		ft_putstr_fd("Memory is not allocated. Error.\n", 1);
		while(1);
	exit(err);
}
