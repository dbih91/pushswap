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
/*   Created/Updated: 2021/06/04 22:22:09  /  2021/06/04 22:22:14 @cclarice   */
/*                                                                            */
/* ************************************************************************** */
/*                                                                            */
/*   Push to B sorted list                                                    */
/*                                                                            */
/*   Push to B closest numbers                                                */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

unsigned int get_smallest(t_sort *sort)
{
	unsigned int	ret;
	t_elem			*ptr;

	ret = 0;
	ptr = sort->a;
	while (ptr)
	{

	}
}

unsigned int get_biggest(t_sort *sort)
{
	unsigned int	ret;
	t_elem			*ptr;

	
	ptr = sort->a;
	while (ptr)
	{
		
	}

	ret = sort->l;
}

void	p2b_sort(t_sort *sort)
{
	unsigned int b;
	unsigned int s;

	s = 0;
	b = sort->l - 1;
	while (a_not_sorted(sort))
	{
		if (index_distance(sort, s) > index_distance(sort, b))
		{
			if (index_location(sort, b) <= sort->l / 2)
				while (sort->a->i != b && sort->a->i != b - 1)
					rota_a(sort);
			else
				while (sort->a->i != b && sort->a->i != b - 1)
					rrta_a(sort);
			push_b(sort);
			if (sort->b == b)
				b = get_biggest(sort);
		}
		else
		{
			if (index_location(sort, s) <= sort->l / 2)
				while (sort->a->i != s && sort->a->i != s + 1)
					rota_a(sort);
			else
				while (sort->a->i != s && sort->a->i != s + 1)
					rrta_a(sort);
			push_b(sort);
			if (sort->b == s)
				s = get_smallest(sort);
			if (sort->b && sort->b->n && sort->b->i < sort->b->n->i)
				rota_b(sort);
		}
	}
}