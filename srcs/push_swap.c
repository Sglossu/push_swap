/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:10:39 by sglossu           #+#    #+#             */
/*   Updated: 2021/08/23 22:20:22 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	int	element_field(t_list **lst, t_list **tmp, int number)
{
	t_list	*count;

	count = *lst;
	while (count->next)
	{
		if ((count->field == number) || (count->next->field == number))
			error(-3);
		count = count->next;
	}
	count->next = *tmp;
	if ((*lst)->field == (*lst)->next->field)
		error(-3);
	return (1);
}

static	int	add_element(t_list **lst, int number)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (tmp == NULL)
		error(-5);
	tmp->next = NULL;
	tmp->field = number;
	tmp->index = 0;
	tmp->index_scd = 0;
	if (*lst == NULL)
	{
		*lst = tmp;
		return (1);
	}
	if (element_field(lst, &tmp, number) < 0)
		return (-1);
	else
		return (1);
}

static	int	valid_and_add(char **argv, t_list **stack_a, int i)
{
	if (if_numbers(argv, i) < 0)
		error(-2);
	while (argv[i])
	{
		if ((ft_atoi_long(argv[i]) <= 2147483647) \
		&& (ft_atoi_long(argv[i]) >= -2147483648))
		{
			if (add_element(stack_a, ft_atoi_long(argv[i])) < 0)
				error(-3);
		}
		else
			error(-4);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*stack_a;
	t_list	*stack_b;

	i = 1;
	if (argc == 1)
		error(-1);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		i = 0;
		if (argv[0] == NULL)
			error(-1);
	}
	if (valid_and_add(argv, &stack_a, i) < 0)
		return (-1);
	sorted(&stack_a, &stack_b);
	exit(1);
}
