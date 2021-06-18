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
/*   rotate.c                                 cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/06/18 16:31:39  /  2021/06/18 16:31:42 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

// ra : rotate a - shift up all elements of stack a by 1.
// rb : rotate b - shift up all elements of stack b by 1.
// rr : ra and rb at the same time.
//                                      (The first element becomes the last one)

void	rota_a(t_sort *sort)
{
	t_elem *frst;
	t_elem *last;

	if (sort->a && sort->a->n)
	{
		frst = sort->a;
		sort->a = sort->a->n;
		last = sort->a;
		while (last->n)
			last = last->n;
		last->n = frst;
		frst->n = NULL;
		sort->al = frst;
	}
	visual(sort, "ra\n");
}

void	rota_b(t_sort *sort)
{
	t_elem *frst;
	t_elem *last;

	if (sort->b && sort->b->n)
	{
		frst = sort->b;
		sort->b = sort->b->n;
		last = sort->b;
		while (last->n)
			last = last->n;
		last->n = frst;
		frst->n = NULL;
		sort->bl = frst;
	}
	visual(sort, "rb\n");
}

void	rota_r(t_sort *sort)
{
	t_elem *frst;
	t_elem *last;

	if (sort->a && sort->a->n)
	{
		frst = sort->a;
		sort->a = sort->a->n;
		last = sort->a;
		while (last->n)
			last = last->n;
		last->n = frst;
		frst->n = NULL;
		sort->al = frst;
	}
	if (sort->b && sort->b->n)
	{
		frst = sort->b;
		sort->b = sort->b->n;
		last = sort->b;
		while (last->n)
			last = last->n;
		last->n = frst;
		frst->n = NULL;
		sort->bl = frst;
	}
	visual(sort, "rr\n");
}
