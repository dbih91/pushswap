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
/*   qck_sort.c                               cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/06/06 23:48:52  /  2021/06/06 23:49:12 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	a_has_bigger(t_sort *sort, unsigned int h)
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

int	b_has_bigger(t_sort *sort, unsigned int h)
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

void	qck_sort(t_sort *sort)
{
	unsigned int	h;
	unsigned int	t;

	h = sort->l / 2;
	t = sort->l - h;
	while (t <= sort->l - 4)
	{
		while (a_has_bigger(sort, t))
		{
			if (sort->a->i <= t)
				push_b(sort);
			if (a_has_bigger(sort, t))
				rrta_a(sort);
		}
		h = h / 2;
		t += h;
	}
	//while (sort->a)
		push_b(sort);
}