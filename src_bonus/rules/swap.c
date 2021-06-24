/* ************************************************************************** */
/*                                                                            */
/*       ::::::    ::::::   :::  ::::::::  ::::::::   :::  ::::::    :::::::  */
/*     :+:   :+: :+:   :+: :+: :+:   :+:  :+:    :+: :+: :+:   :+: :+:    :+: */
/*    +:+       +:+       +:+ +:+   +:+  +:+    +:+     +:+       +:+    +:+  */
/*   +#+       +:+       +#+ +:+   +#+  +:+    +#+ +:+ +#+       +#+:+:+#+:   */
/*  +#+       +#+       +#+   +#+#+#+# #+#+#+#+   +#+ +#+       +#+           */
/* #+#   #+# #+#   #+# #+#            #+#    #+# #+# #+#   #+# #+#    #+#     */
/*  ######    ######  ############## ###    ### ###   ######    #######       */
/*                                                                            */
/* ************************************************************************** */
/*                                                                            */
/*   swap.c                                   cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/06/24 00:52:08  /  2021/06/24 02:31:37 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

// sa: swap a - swap the first 2 elements at the top of stack a. 
// sb: swap b - swap the first 2 elements at the top of stack b.
// ss: sa and sb at the same time.
//                              (Do nothing if there is only one or no elements)

void	swap_a(t_sort *sort)
{
	t_elem	*frst;

	if (sort->a && sort->a->n && !sort->a->n->n)
		sort->al = sort->a;
	if (sort->a && sort->a->n)
	{
		frst = sort->a;
		sort->a = sort->a->n;
		frst->n = sort->a->n;
		sort->a->n = frst;
	}
}

void	swap_b(t_sort *sort)
{
	t_elem	*frst;

	if (sort->b && sort->b->n && !sort->b->n->n)
		sort->bl = sort->b;
	if (sort->b && sort->b->n)
	{
		frst = sort->b;
		sort->b = sort->b->n;
		frst->n = sort->b->n;
		sort->b->n = frst;
	}
}

void	swap_s(t_sort *sort)
{
	t_elem	*frst;

	if (sort->a && sort->a->n && !sort->a->n->n)
		sort->al = sort->a;
	if (sort->b && sort->b->n && !sort->b->n->n)
		sort->bl = sort->b;
	if (sort->b && sort->b->n)
	{
		frst = sort->b;
		sort->b = sort->b->n;
		frst->n = sort->b->n;
		sort->b->n = frst;
	}
	if (sort->a && sort->a->n)
	{
		frst = sort->a;
		sort->a = sort->a->n;
		frst->n = sort->a->n;
		sort->a->n = frst;
	}
}
