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
/*   whl_sort_u.c                             cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/06/23 23:07:16  /  2021/06/23 23:11:16 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	push_b_m(t_sort *sort, unsigned int *m)
{
	*m = sort->a->i;
	push_b(sort);
}

unsigned int	push_mn(t_sort *sort, int d, unsigned int m)
{
	while (d != 0)
	{
		if (d > 0 && d--)
		{
			if (sort->a->i > m && sort->a->n->i > sort->a->i)
				push_b_m(sort, &m);
			else if (sort->b && sort->b->n && sort->b->i > sort->a->i
				&& sort->a->i > sort->b->n->i)
			{
				push_b(sort);
				swap_b(sort);
			}
			else
				rota_a(sort);
		}
		else if (d != 0)
		{
			if (sort->a->i > m && sort->al->i > sort->a->i)
				push_b_m(sort, &m);
			else if (d++)
				rrta_a(sort);
		}
	}
	push_b(sort);
	return (m);
}

void	push_min_max(t_sort *sort)
{
	int				d;
	unsigned int	m;

	m = 0;
	if (mdl(get_dist_i(sort->a, sort->la, sort->l - 1))
		                       <= mdl(get_dist_i(sort->a, sort->la, 0)))
		d = get_dist_i(sort->a, sort->la, sort->l - 1);
	else
		d = get_dist_i(sort->a, sort->la, 0);
	m = push_mn(sort, d, m);
	if (sort->b->i == 0)
		d = get_dist_i(sort->a, sort->la, sort->l - 1);
	else
		d = get_dist_i(sort->a, sort->la, 0);
	rota_b(sort);
	push_mn(sort, d, m);
	if (sort->b->i == 0)
	{
		rrta_b(sort);
		swap_b(sort);
		rota_b(sort);
	}
}

int	a_has_w(t_elem *ptr)
{
	while (ptr)
	{
		if (!ptr->w)
			return (1);
		ptr = ptr->n;
	}
	return (0);
}

int	get_dist_i(t_elem *ptr, unsigned int l, unsigned int i)
{
	int	ret;

	ret = 0;
	while (ptr->i != i)
	{
		ret++;
		if (ret == l / 2 + l % 2)
		{
			if (l % 2)
				ret--;
			ret *= -1;
		}
		ptr = ptr->n;
	}
	return (ret);
}
