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
/*   Created/Updated: 2021/06/18 16:33:16  /  2021/06/18 16:33:21 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

// sa: swap a - swap the first 2 elements at the top of stack a. 
// sb: swap b - swap the first 2 elements at the top of stack b.
// ss: sa and sb at the same time.
//                              (Do nothing if there is only one or no elements)

void	swap_a(t_sort *sort)
{
	t_elem *frst;

	if (sort->a && sort->a->n && !sort->a->n->n)
		sort->al = sort->a;
	if (sort->a && sort->a->n)
	{
		frst = sort->a;
		sort->a = sort->a->n;
		frst->n = sort->a->n;
		sort->a->n = frst;
	}
	visual(sort, "sa\n");
}

void	swap_b(t_sort *sort)
{
	t_elem *frst;

	if (sort->b && sort->b->n && !sort->b->n->n)
		sort->bl = sort->b;
	if (sort->b && sort->b->n)
	{
		frst = sort->b;
		sort->b = sort->b->n;
		frst->n = sort->b->n;
		sort->b->n = frst;
	}
	visual(sort, "sb\n");
}

void	swap_s(t_sort *sort)
{
	t_elem *frst;
	
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
	visual(sort, "ss\n");
}
