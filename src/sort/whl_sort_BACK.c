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
/*   Created/Updated: 2021/06/19 18:03:06  /  2021/06/19 18:03:07 @cclarice   */
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
	if (sort->bl->i > ptra->i && ptra->i > sort->b->i)
	{
		ptra->b = 0;
		ptra->l = mdl(ptra->a);
		return ;
	}
	while (ptrb && ptrb->n)
	{
		i++;
		if (i && i == sort->lb / 2 + sort->lb % 2)
		{
			if (sort->lb % 2)
				i--;
			i *= -1;
		}
		if (ptrb->i > ptra->i && ptra->i > ptrb->n->i)
			break ;
		ptrb = ptrb->n;
	}
	ptra->b = i;
	if (ptra->a > 0 && ptra->b > 0)
	{
		if (mdl(ptra->a) > mdl(ptra->b))
			ptra->l = mdl(ptra->a);
		else
			ptra->l = mdl(ptra->b);
	}
	else
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
		//printf("[I:%-3i A:%-3d B:%-3d L:%-3u W:%d]\n", ptr->i, ptr->a, ptr->b, ptr->l, ptr->w);
		if (ret->w)
			ret->l = 0xffffff;
		if (ret->l > ptr->l && ptr->w == 0)
			ret = ptr;
		ptr = ptr->n;
	}
	//printf("<I:%-3i A:%-3d B:%-3d L:%-3u W:%d> !!!\n", ret->i, ret->a, ret->b, ret->l, ret->w);
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
		if (ptr->w)
			ptr->a = 0xffffff;
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

	d = get_distance_index(sort->a, sort->la, sort->l - 1)
	push_b(sort);
	push_b(sort);
	//if (mdl(get_distance_index(sort->a, sort->la, sort->l - 1)) <=
	//	mdl(get_distance_index(sort->a, sort->la, 0)))
	//	d = get_distance_index(sort->a, sort->la, sort->l - 1);
	//else
	//	d = get_distance_index(sort->a, sort->la, 0);
	//while (d != 0)
	//{
	//	if (d > 0 && d--)
	//		rota_a(sort);
	//	else if (d++)
	//		rrta_a(sort);
	//}
	//push_b(sort);
	//if (sort->b->i == 0)
	//	d = get_distance_index(sort->a, sort->la, sort->l - 1);
	//else
	//	d = get_distance_index(sort->a, sort->la, 0);
	//while (d != 0)
	//{
	//	if (d > 0 && d--)
	//		rota_a(sort);
	//	else if (d++)
	//		rrta_a(sort);
	//}
	//push_b(sort);
	if (sort->b->i < sort->b->n->i)
		swap_b(sort);
}

int		a_has_w(t_elem *ptr)
{
	while (ptr)
	{
		if (!ptr->w)
			return (1);
		ptr = ptr->n;
	}
	return (0);
}

void	whl_sort(t_sort *sort)
{
	t_elem *ptr;
	unsigned int i;

	i = 1;
	push_min_max(sort);
	while (a_has_w(sort->a))
	{
		if (sort->lb > sort->l / 2 + 1 && i && i--)
		{
			while (sort->lb != 2)
			{
				if (sort->b->i != 0 && sort->b->i != sort->l - 1)
				{
					sort->b->w = 1;
					push_a(sort);
				}
				else
					rota_b(sort);
			}
		}
		ptr = get_distances(sort);
		while (ptr->a)
		{
			if (ptr->a > 0 && ptr->b > 0 && ptr->b-- && ptr->a--)
				rota_r(sort);
			else if (ptr->a > 0 && ptr->a--)
				rota_a(sort);
			else if (ptr->b < 0 && ptr->b++ && ptr->a++)
				rrta_r(sort);
			else if (ptr->a++)
				rrta_a(sort);
		}
		while (ptr->b)
		{
			if (ptr->b > 0 && ptr->b--)
				rota_b(sort);
			else if (ptr->b++)
				rrta_b(sort);
		}
		if (!sort->a->w)
		{
			sort->b->w = 1;
			push_b(sort);
		}
		else
		{
			write(1, "Error!\n", 7);
			break ;
		}
	}
	while (get_distance_index(sort->a, sort->la, get_smallest(sort->a)) != 0)
	{
		if (get_distance_index(sort->a, sort->la, get_smallest(sort->a)) > 0
		 && get_distance_index(sort->b, sort->lb, get_biggest(sort->b)) > 0)
			rota_r(sort);
		else if (get_distance_index(sort->a, sort->la, get_smallest(sort->a)) < 0
		 && get_distance_index(sort->b, sort->lb, get_biggest(sort->b)) < 0)
			rrta_r(sort);
		else if (get_distance_index(sort->a, sort->la, get_smallest(sort->a)) > 0)
			rota_a(sort);
		else
			rrta_a(sort);
	}
	while (get_distance_index(sort->b, sort->lb, get_biggest(sort->b)) != 0)
	{
		if (get_distance_index(sort->b, sort->lb, get_biggest(sort->b)) > 0)
			rota_b(sort);
		else
			rrta_b(sort);
	}
	i = sort->l - 1;
	while (sort->b)
	{
		while (sort->b && sort->b->i == i)
		{
			i--;
			push_a(sort);
		}
		if (sort->al->i == i)
		{
			i--;
			rrta_a(sort);
		}
	}
}