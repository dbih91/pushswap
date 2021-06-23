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
/*   Created/Updated: 2021/06/18 16:28:37  /  2021/06/18 16:28:51 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

// pa: push a - take first element at the top of b and put it at the top of a.
// pb: push b - take first element at the top of a and put it at the top of b.
//                                               (Do nothing if b or a is empty)

void	push_a(t_sort *sort)
{
	t_elem *ptr;

	if (sort->b && ++sort->la)
		sort->lb--;
	if (sort->b && !sort->a) // if a is not
	{
		sort->a = sort->b;
		sort->b = sort->b->n;
		sort->a->n = NULL;
		sort->al = sort->a;
	}
	else if (sort->b)
	{
		ptr = sort->a;
		sort->a = sort->b;
		sort->b = sort->b->n;
		sort->a->n = ptr;
	}
	if (!sort->b)
		sort->bl = NULL;
	visual(sort, "pa\n");
}

void	push_b(t_sort *sort)
{
	t_elem *ptr;

	if (sort->a && ++sort->lb)
		sort->la--;
	if (sort->a && !sort->b) // if b is not
	{
		sort->b = sort->a;
		sort->a = sort->a->n;
		sort->b->n = NULL;
		sort->bl = sort->b;
	}
	else if (sort->a)
	{
		ptr = sort->b;
		sort->b = sort->a;
		sort->a = sort->a->n;
		sort->b->n = ptr;
	}
	if (!sort->a)
		sort->al = NULL;
	visual(sort, "pb\n");
}
