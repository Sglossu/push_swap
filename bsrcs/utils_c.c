/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:10:26 by sglossu           #+#    #+#             */
/*   Updated: 2021/08/19 18:11:07 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int	if_numbers(char **argv, int i)
{
	int	j;

	while (argv[i])
	{
		j = 0;
		if (argv[i][0] == '-' && ft_isdigit(argv[i][1]) == 1)
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

void	push_swap_check(t_list **stack_a, t_list **stack_b, t_list_c **com)
{
	while (*com)
	{
		if (ft_strcmp((*com)->field, "sa") == 0)
			sa(stack_a);
		else if (ft_strcmp((*com)->field, "sb") == 0)
			sb(stack_b);
		else if (ft_strcmp((*com)->field, "pa") == 0)
			pa(stack_a, stack_b);
		else if (ft_strcmp((*com)->field, "pb") == 0)
			pb(stack_a, stack_b);
		else if (ft_strcmp((*com)->field, "ra") == 0)
			ra(stack_a);
		else if (ft_strcmp((*com)->field, "rb") == 0)
			rb(stack_b);
		else if (ft_strcmp((*com)->field, "rr") == 0)
			rr(stack_a, stack_b);
		else if (ft_strcmp((*com)->field, "rra") == 0)
			rra(stack_a);
		else if (ft_strcmp((*com)->field, "rrb") == 0)
			rrb(stack_b);
		else if (ft_strcmp((*com)->field, "rrr") == 0)
			rrr(stack_a, stack_b);
		*com = (*com)->next;
	}
}

void	error(int err)
{
	if (err < -10)
		ft_putstr_fd("KO\n", 1);
	else if (err == -9)
		ft_putstr_fd("Not arguments\n", 1);
	else
		ft_putstr_fd("Error\n", 1);
	exit(err);
}
