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
/*   Created/Updated: 2021/05/28 18:24:29  /  2021/05/28 18:24:35 @cclarice   */
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
		last = sort->a->n;
		while (last->n)
			last = last->n;
		last->n = frst;
		frst->n = NULL;
	}
	write(1, "ra\n", 3);
	visual(sort);
}

void	rota_b(t_sort *sort)
{
	t_elem *frst;
	t_elem *last;

	if (sort->b && sort->b->n)
	{
		frst = sort->b;
		sort->b = sort->b->n;
		last = sort->b->n;
		while (last->n)
			last = last->n;
		last->n = frst;
		frst->n = NULL;
	}
	write(1, "rb\n", 3);
	visual(sort);
}

void	rota_r(t_sort *sort)
{
	t_elem *frst;
	t_elem *last;

	if (sort->a && sort->a->n)
	{
		frst = sort->a;
		frst->n = NULL;
		sort->a = sort->a->n;
		last = sort->a->n;
		while (last->n)
			last = last->n;
		last->n = frst;
	}
	if (sort->b && sort->b->n)
	{
		frst = sort->b;
		frst->n = NULL;
		sort->b = sort->b->n;
		last = sort->b->n;
		while (last->n)
			last = last->n;
		last->n = frst;
	}
	write(1, "rr\n", 3);
	visual(sort);
}
