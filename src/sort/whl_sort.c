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
/*   whl_sort.c                               cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/06/19 04:28:14  /  2021/06/19 04:29:52 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

unsigned int	mdl(int i)
{
	if (i < 0)
		i *= -1;
	return ((unsigned int)i);
}

void	find_distances(t_sort *sort, t_elem *ptrb, t_elem *ptra)
{
	int	i;

	i = 0;
	if (sort->b->i > ptra->i && ptra->i > sort->bl->i && sort->bl->i != 0)
	{
		ptra->b = 0;
		ptra->l = mdl(ptra->a);
		return ;
	}
	while (ptrb && ptrb->n)
	{
		if (ptrb->i > ptra->i && ptra->i > ptrb->n->i && ptrb->n->i != 0)
			break ;
		i++;
		if (i == sort->lb / 2 + sort->lb % 2)
		{
			if (sort->lb % 2)
				i--;
			i *= -1;
		}
		ptrb = ptrb->n;
	}
	ptra->b = i;
	ptra->l = mdl(ptra->a) + mdl(i);
}

t_elem	*add_distances(t_sort *sort)
{
	t_elem *ptr;
	t_elem *ret;

	ptr = sort->a;
	ret = ptr;
	while (ptr)
	{
		find_distances(sort, sort->b, ptr);
		printf("[I:%-3i A:%-3d B:%-3d L:%-3u]\n", ptr->i, ptr->a, ptr->b, ptr->l);
		if (ret->l > ptr->l)
			ret = ptr;
		ptr = ptr->n;
	}
	return (ret);
}

t_elem	*get_distances(t_sort *sort)
{
	t_elem			*ptr;
	int	i;

	i = 0;
	ptr = sort->a;
	while (ptr)
	{
		ptr->a = i;
		i++;
		if (i == sort->la / 2 + sort->la % 2)
		{
			if (sort->la % 2)
				i--;
			i *= -1;
		}
		ptr = ptr->n;
	}
	return (add_distances(sort));
}

int		get_distance_index(t_elem *ptr, unsigned int l, unsigned int i)
{
	int ret;

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

void	push_min_max(t_sort *sort)
{
	int		d;

	if (mdl(get_distance_index(sort->a, sort->la, sort->l - 1)) <=
		mdl(get_distance_index(sort->a, sort->la, 0)))
		d = get_distance_index(sort->a, sort->la, sort->l - 1);
	else
		d = get_distance_index(sort->a, sort->la, 0);
	while (d != 0)
	{
		if (d > 0 && d--)
			rota_a(sort);
		else if (d++)
			rrta_a(sort);
	}
	push_b(sort);
	if (sort->b->i == 0)
		d = get_distance_index(sort->a, sort->la, sort->l - 1);
	else
		d = get_distance_index(sort->a, sort->la, 0);
	while (d != 0)
	{
		if (d > 0 && d--)
			rota_a(sort);
		else if (d++)
			rrta_a(sort);
	}
	push_b(sort);
	if (sort->b->i < sort->b->n->i)
		swap_b(sort);
}

void	whl_sort(t_sort *sort)
{
	t_elem *ptr;

	push_min_max(sort);
	while (sort->a && sort->a->n)
	{
		ptr = get_distances(sort);
		while (ptr->a)
		{
			if (ptr->a > 0 && ptr->a--)
				rota_a(sort);
			else if (ptr->a++)
				rrta_a(sort);
		}
		while (ptr->b)
		{
			if (ptr->b > 0 && ptr->b--)
				rrta_b(sort);
			else if (ptr->b++)
				rota_b(sort);
		}
		push_b(sort);
	}
}