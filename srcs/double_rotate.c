/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:26:34 by sglossu           #+#    #+#             */
/*   Updated: 2021/08/19 18:26:57 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_struct	double_rotate(t_list **stack_a, t_list **stack_b, t_struct psw)
{
	while (psw.mode == RARB && psw.ra > 0 && psw.rb > 0)
	{
		rr(stack_a, stack_b);
		psw.ra--;
		psw.rb--;
	}
	while (psw.mode == RRARRB && psw.rra > 0 && psw.rrb > 0)
	{
		rrr(stack_a, stack_b);
		psw.rra--;
		psw.rrb--;
	}
	return (psw);
}
