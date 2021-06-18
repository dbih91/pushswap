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
/*   sw2_sort_old.c                           cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/06/10 21:08:27  /  2021/06/10 21:37:32 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

//
// A 8 7 6 5 4 3 2 1
// B
//
// A 8 7 6 5
// B 4 3 2 1
//
// A 4 3 8 7 6 5
// B 2 1
//
// A 8 7 6 5
// B 4 3 2 1
//
// A 8 7
// B 6 5 4 3 2 1
//
// A 5 6 7 8
// B 3 4 2 1
//
// A 1 2 3 4 5 6 7 8
// B 
//

void try_sort(t_sort *sort)
{
	if ((sort->a && sort->a->n && sort->a->i > sort->a->n->i)
	 && (!(sort->a->i == get_biggest(sort->a)))
	 && (sort->b && sort->b->n && sort->b->i < sort->b->n->i)
	 && (!(sort->b->i == get_smallest(sort->b))))
		swap_s(sort);
	else if ((sort->a && sort->a->n && sort->a->i > sort->a->n->i)
	 && (!(sort->a->i == get_biggest(sort->a))))
		swap_a(sort);
	else if ((sort->b && sort->b->n && sort->b->i < sort->b->n->i)
	 && (!(sort->b->i == get_smallest(sort->b))))
		swap_b(sort);
}

int	a_bigger(t_sort *sort, unsigned int h)
{
	t_elem *ptr;

	ptr = sort->a;
	while (ptr)
	{
		if (ptr->i > h)
			return (1);
		ptr = ptr->n;
	}
	return (0);
}

int	b_bigger(t_sort *sort, unsigned int h)
{
	t_elem *ptr;

	ptr = sort->b;
	while (ptr)
	{
		if (ptr->i > h)
			return (1);
		ptr = ptr->n;
	}
	return (0);
}

int	a_smaller(t_sort *sort, unsigned int h)
{
	t_elem *ptr;

	ptr = sort->a;
	while (ptr)
	{
		if (ptr->i <= h)
			return (1);
		ptr = ptr->n;
	}
	return (0);
}

int	b_smaller(t_sort *sort, unsigned int h)
{
	t_elem *ptr;

	ptr = sort->b;
	while (ptr)
	{
		if (ptr->i <= h)
			return (1);
		ptr = ptr->n;
	}
	return (0);
}

void sw2_sort(t_sort *sort)
{
	unsigned int	h;

	h = sort->l / 2 - 1; // [0 1|2 3 4]      l = 5     5 / 2 = 0
	while (a_smaller(sort, h))
	{
		try_sort(sort);
		if (sort->a->i <= h)
			push_b(sort);
		else
			rota_r(sort);
	}
	h = h + (h / 2 + 1);
	while (a_smaller(sort, h))
	{
		try_sort(sort);
		if (sort->a->i <= h)
			push_b(sort);
		else
			rota_r(sort);
	}
	h = sort->l / 2 - 1;
	while (b_bigger(sort, h))
	{
		try_sort(sort);
		if (sort->b->i > h)
			push_a(sort);
		else
			rota_r(sort);
	}
	h = sort->l / 4;
	while (b_bigger(sort, h))
	{
		try_sort(sort);
		if (sort->b->i > h)
			push_a(sort);
		else
			rota_b(sort);
	}
	h = sort->l / 2 - 1;
	while (a_smaller(sort, h) && not_sorted(sort->a))
	{
		try_sort(sort);
		if (sort->a->i <= h)
			push_b(sort);
		else
			rota_a(sort);
	}
	while (not_sorted(sort->a) && not_resorted(sort->b))
	{
		if ((sort->a && sort->a->n && sort->a->i > sort->a->n->i)
		 && (!(sort->a->i == get_biggest(sort->a)))
		 && (sort->b && sort->b->n && sort->b->i < sort->b->n->i)
		 && (!(sort->b->i == get_smallest(sort->b))))
			swap_s(sort);
		//else if (((sort->a && sprt->a->n && sort->a->i < sort->a->n->i)
		// || (sort->a->i == get_biggest(sort->a)))
		// && ((sort->b && sprt->b->n && sort->b->i < sort->b->n->i)
		// || (sort->b->i == get_biggest(sort->b))))
		else if ((sort->a && sprt->a->n && sort->a->i < sort->a->n->i)
		 || (sort->a->i == get_biggest(sort->a)))
			rota_a(sort);
		else if ((sort->b && sprt->b->n && sort->b->i < sort->b->n->i)
		 || (sort->b->i == get_smallest(sort->b)))
			rota_b(sort);
	}
	while (not_sorted(sort->a) || not_resorted(sort->b))
	{
		try_sort(sort);
		rota_r(sort);
	}
	while ((sort->a->i != get_smallest(sort->a) && sort->b->i != get_biggest(sort->b)))
		rota_r(sort);
	while (sort->a->i != get_smallest(sort->a))
		rota_a(sort);
	while (sort->b->i != get_biggest(sort->b))
		rota_b(sort);
	while (sort->b)
		push_a(sort);
}
