/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_continue.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:10:55 by sglossu           #+#    #+#             */
/*   Updated: 2021/08/20 00:00:13 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int	if_ordered(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp && tmp->next)
	{
		if (tmp->next->field > tmp->field)
			tmp = tmp->next;
		else
			return (-1);
	}
	return (1);
}

static	int	add_command(t_list_c **com, char **line)
{
	t_list_c	*tmp;
	t_list_c	*count;

	tmp = *com;
	count = *com;
	tmp = (t_list_c *)malloc(sizeof(t_list_c));
	if (tmp == NULL)
	{
		error(-5);
		return (-1);
	}
	tmp->next = NULL;
	tmp->field = *line;
	if (*com == NULL)
	{
		*com = tmp;
		return (1);
	}
	while (count->next)
		count = count->next;
	count->next = tmp;
	return (1);
}

static	int	valid_com(char **line)
{
	int	flag;

	flag = -1;
	if (ft_strcmp(*line, "sa") == 0)
		flag = 1;
	else if (ft_strcmp(*line, "sb") == 0)
		flag = 1;
	else if (ft_strcmp(*line, "pa") == 0)
		flag = 1;
	else if (ft_strcmp(*line, "pb") == 0)
		flag = 1;
	else if (ft_strcmp(*line, "ra") == 0)
		flag = 1;
	else if (ft_strcmp(*line, "rb") == 0)
		flag = 1;
	else if (ft_strcmp(*line, "rr") == 0)
		flag = 1;
	else if (ft_strcmp(*line, "rra") == 0)
		flag = 1;
	else if (ft_strcmp(*line, "rrb") == 0)
		flag = 1;
	else if (ft_strcmp(*line, "rrr") == 0)
		flag = 1;
	return (flag);
}

static	int	check_gnl(t_list_c **com)
{
	int		i;
	char	*line;

	line = NULL;
	i = get_next_line(0, &line);
	while (i)
	{
		if (valid_com(&line) > 0)
			add_command(com, &line);
		else
			error(-6);
		i = get_next_line(0, &line);
	}
	free(line);
	return (1);
}

void	checker_cont(t_list **stack_a, t_list **stack_b)
{
	t_list_c	*com;

	com = NULL;
	if (check_gnl(&com) < 0)
		error(-1);
	push_swap_check(stack_a, stack_b, &com);
	if (if_ordered(stack_a) < 0 || *stack_b != NULL)
		error(-11);
}
