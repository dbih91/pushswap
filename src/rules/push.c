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
/*   push.c                                   cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/05/31 20:08:00  /  2021/05/31 20:08:12 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

// pa: push a - take first element at the top of b and put it at the top of a.
// pb: push b - take first element at the top of a and put it at the top of b.
//                                               (Do nothing if b or a is empty)

void	push_a(t_sort *sort)
{
	t_elem *ptr;

	if (sort->b)
	{
		sort->lb--;
		sort->la++;
	}
	if (sort->b && !sort->a) // if a is not
	{
		sort->a = sort->b;
		sort->b = sort->b->n;
		sort->a->n = NULL;
	}
	else if (sort->b)
	{
		ptr = sort->a;
		sort->a = sort->b;
		sort->b = sort->b->n;
		sort->a->n = ptr;
	}
	visual(sort, "pa\n");
}

void	push_b(t_sort *sort)
{
	t_elem *ptr;

	if (sort->a)
	{
		sort->lb++;
		sort->la--;
	}
	if (sort->a && !sort->b) // if b is not
	{
		sort->b = sort->a;
		sort->a = sort->a->n;
		sort->b->n = NULL;
	}
	else if (sort->a)
	{
		ptr = sort->b;
		sort->b = sort->a;
		sort->a = sort->a->n;
		sort->b->n = ptr;
	}
	visual(sort, "pb\n");
}
