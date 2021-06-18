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
/*   p2b_sort.c                               cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/06/08 00:34:34  /  2021/06/08 00:34:39 @cclarice   */
/*                                                                            */
/* ************************************************************************** */
/*                                                                            */
/*   Push to B sorted list                                                    */
/*                                                                            */
/*   Push to B closest numbers                                                */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	p2b_b(t_sort *sort, unsigned int *b)
{
	if (index_location(sort, *b) <= sort->l / 2)
		while (sort->a->i != *b && sort->a->i != *b - 1)
			rota_a(sort);
	else
		while (sort->a->i != *b && sort->a->i != *b - 1)
			rrta_a(sort);
	push_b(sort);
	if (sort->b->i == *b)
		*b = get_biggest(sort->a);
}

void	p2b_s(t_sort *sort, unsigned int *s)
{
	if (index_location(sort, *s) <= sort->l / 2)
		while (sort->a->i != *s && sort->a->i != *s + 1)
			rota_a(sort);
	else
		while (sort->a->i != *s && sort->a->i != *s + 1)
			rrta_a(sort);
	push_b(sort);
	if (sort->b->i == *s)
		*s = get_smallest(sort->a);
	if (sort->b && sort->b->n && sort->b->i < sort->b->n->i)
		rota_b(sort);
}

void	p2b_sort(t_sort *sort)
{
	unsigned int b;
	unsigned int s;

	s = 0;
	b = sort->l - 1;
	while (not_sorted(sort->a))
	{
		if (index_distance(sort, s) > index_distance(sort, b))
			p2b_b(sort, &b);
		else
			p2b_b(sort, &s);
	}
}