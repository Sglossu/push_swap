/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_ba.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:17:27 by sglossu           #+#    #+#             */
/*   Updated: 2021/08/19 18:30:04 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	moving_ba(t_list **stack_a, t_list **stack_b, t_struct psw)
{
	if (psw.mode == RARB || psw.mode == RRARRB)
		psw = double_rotate(stack_a, stack_b, psw);
	if (psw.mode == RARB || psw.mode == RARRB)
		while (psw.ra--)
			ra(stack_a);
	if (psw.mode == RARB || psw.mode == RRARB)
		while (psw.rb--)
			rb(stack_b);
	if (psw.mode == RRARRB || psw.mode == RRARB)
		while (psw.rra--)
			rra(stack_a);
	if (psw.mode == RRARRB || psw.mode == RARRB)
		while (psw.rrb--)
			rrb(stack_b);
	pa(stack_a, stack_b);
}
