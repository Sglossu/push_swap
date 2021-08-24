/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <sglossu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:17:34 by sglossu           #+#    #+#             */
/*   Updated: 2021/08/19 19:02:49 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_struct	init_struct(t_struct psw)
{
	psw.count_a = 0;
	psw.count_b = 0;
	psw.push_a = 0;
	psw.push_b = 0;
	psw.i_a = 0;
	psw.i_b = 0;
	psw.index_b = 0;
	psw.a_perv = 0;
	psw.b_perv = 0;
	psw.min_ord = 1;
	psw.max_ord = 1;
	psw.mode = 0;
	psw.ra = 0;
	psw.rra = 0;
	psw.rb = 0;
	psw.rrb = 0;
	psw.mode = 0;
	return (psw);
}
