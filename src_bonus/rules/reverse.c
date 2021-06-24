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
/*   Created/Updated: 2021/06/24 00:47:57  /  2021/06/24 00:52:07 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

// rra : reverse rotate a - shift down all elements of stack a by 1.
// rrb : reverse rotate b - shift down all elements of stack b by 1.
// rrr : rra and rrb at the same time.
//                                      (The last element becomes the first one)

void	rrta_a(t_sort *sort)
{
	t_elem	*last;
	t_elem	*prel;

	if (sort->a && sort->a->n)
	{
		prel = sort->a;
		while (prel->n && prel->n->n)
			prel = prel->n;
		last = prel->n;
		last->n = sort->a;
		prel->n = NULL;
		sort->al = prel;
		sort->a = last;
	}
}

void	rrta_b(t_sort *sort)
{
	t_elem	*last;
	t_elem	*prel;

	if (sort->b && sort->b->n)
	{
		prel = sort->b;
		while (prel->n && prel->n->n)
			prel = prel->n;
		last = prel->n;
		last->n = sort->b;
		prel->n = NULL;
		sort->bl = prel;
		sort->b = last;
	}
}

void	syeta(t_sort *sort)
{
	t_elem	*last;
	t_elem	*prel;

	if (sort->a && sort->a->n)
	{
		prel = sort->a;
		while (prel->n && prel->n->n)
			prel = prel->n;
		last = prel->n;
		last->n = sort->a;
		prel->n = NULL;
		sort->al = prel;
		sort->a = last;
	}
}

void	rrta_r(t_sort *sort)
{
	t_elem	*last;
	t_elem	*prel;

	if (sort->b && sort->b->n)
	{
		prel = sort->b;
		while (prel->n && prel->n->n)
			prel = prel->n;
		last = prel->n;
		last->n = sort->b;
		prel->n = NULL;
		sort->bl = prel;
		sort->b = last;
	}
	syeta(sort);
}
