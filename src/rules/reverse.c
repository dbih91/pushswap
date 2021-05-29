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
/*   reverse.c                                cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/05/28 18:24:39  /  2021/05/28 18:42:05 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

// rra : reverse rotate a - shift down all elements of stack a by 1.
// rrb : reverse rotate b - shift down all elements of stack b by 1.
// rrr : rra and rrb at the same time.
//                                      (The last element becomes the first one)

void	rrta_a(t_sort *sort)
{
	t_elem *last;
	t_elem *prel;

	if (sort->a && sort->a->n)
	{
		prel = sort->a;
		while (prel->n->n)
			prel = prel->n;
		last = prel->n;
		last->n = sort->a;
		prel->n = NULL;
		sort->a = last;
	}
	write(1, "rra\n", 4);
	visual(sort);
}

void	rrta_b(t_sort *sort)
{
	t_elem *last;
	t_elem *prel;

	if (sort->b && sort->b->n)
	{
		prel = sort->b;
		while (prel->n->n)
			prel = prel->n;
		last = prel->n;
		last->n = sort->b;
		prel->n = NULL;
		sort->b = last;
	}
	write(1, "rrb\n", 4);
	visual(sort);
}

void	rrta_r(t_sort *sort)
{
	t_elem *last;
	t_elem *prel;

	if (sort->b && sort->b->n)
	{
		prel = sort->b;
		while (prel->n->n)
			prel = prel->n;
		last = prel->n;
		last->n = sort->b;
		prel->n = NULL;
		sort->b = last;
	}
	if (sort->a && sort->a->n)
	{
		prel = sort->a;
		while (prel->n->n)
			prel = prel->n;
		last = prel->n;
		last->n = sort->a;
		prel->n = NULL;
		sort->a = last;
	}
	write(1, "rrr\n", 4);
	visual(sort);
}
