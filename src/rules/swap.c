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
/*   Created/Updated: 2021/05/28 18:22:32  /  2021/05/28 18:24:32 @cclarice   */
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

	if (sort->a && sort->a->n)
	{
		frst = sort->a;
		sort->a = sort->a->n;
		frst->n = sort->a->n;
		sort->a->n = frst;
	}
	write(1, "sa\n", 3);
	visual(sort);
}

void	swap_b(t_sort *sort)
{
	t_elem *frst;

	if (sort->b && sort->b->n)
	{
		frst = sort->b;
		sort->b = sort->b->n;
		frst->n = sort->b->n;
		sort->b->n = frst;
	}
	write(1, "sb\n", 3);
	visual(sort);
}

void	swap_s(t_sort *sort)
{
	t_elem *frst;
	
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
	write(1, "ss\n", 3);
	visual(sort);
}
