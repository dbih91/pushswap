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
/*   Created/Updated: 2021/06/04 22:12:16  /  2021/06/04 22:12:17 @cclarice   */
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
	}
	visual(sort, "rr\n");
}
