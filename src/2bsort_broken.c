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
/*   2bsort_broken.c                          cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/05/28 12:42:26  /  2021/05/28 12:42:27 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// swap_a
// swap_b
// swap_s
// push_a
// push_b
// rota_a
// rota_b
// rota_r
// rrta_a
// rrta_b
// rrta_r

//
// -> B Sort
//

void	get_sf_ss(t_sort *sort)
{
	t_elem *ptr;

	sort->sf = 2147483647;
	sort->ss = 2147483647;
	ptr = sort->a;
	while (ptr)
	{
		if (ptr->i < sort->sf)
			sort->sf = ptr->i;
		ptr = ptr->n;
	}
	if (sort->b)
		printf("!!! %d | %d\n", sort->ss, sort->b->i);
	if (!sort->b || (sort->b && sort->ss != sort->b->i))
	{
		ptr = sort->a;
		while (ptr && sort->ca >= 3)
		{
			if (ptr->i < sort->ss && ptr->i != sort->sf)
				sort->ss = ptr->i;
			ptr = ptr->n;
		}
	}
}

unsigned int		get_len(t_sort *sort)
{
	t_elem			*ptr;
	unsigned int	i;

	i = 0;
	ptr = sort->a;
	while (ptr->i != sort->sf && (ptr->i != sort->ss || sort->swap))
	{
		i++;
		ptr = ptr->n;
	}
	return (i);
}

int		a_not_sorted(t_sort *sort)
{
	t_elem *ptr;

	ptr = sort->a;
	while (ptr->n)
	{
		if (ptr->i > ptr->n->i)
			return (1);
		ptr = ptr->n;
	}
	return (0);
}

void	self_sort(t_sort *sort)
{
	t_elem *ptr;

	visual(sort);
	while (sort->ca != 2)// && a_not_sorted(sort))
	{
		ptr = sort->a;
		get_sf_ss(sort);
		while (sort->a->i != sort->sf && (ptr->i != sort->ss || sort->swap))
		{
			if (get_len(sort) >= sort->ca / 2)
				rrta_a(sort);
			else
				rota_a(sort);
		}
		push_b(sort);
		if (sort->b && sort->b->n && sort->b->i < sort->b->n->i)
		{
			if (sort->a && sort->a->n && sort->a->i > sort->a->n->i)
				swap_s(sort);
			else
				swap_b(sort);
		}
	}
	if (sort->a && sort->a->n && sort->a->i > sort->a->n->i)
		swap_a(sort);
	while (sort->ca != sort->cc)
		push_a(sort);
}

void	init_sort(t_sort *sort)
{
	t_elem	*ptr;

	sort->cc = 1;
	sort->cb = 0;
	ptr = sort->a;
	while (ptr->n && ++sort->cc)
		ptr = ptr->n;
	sort->ca = sort->cc;
	self_sort(sort);
}
