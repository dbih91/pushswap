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
/*   whl_sort_uu.c                            cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/06/23 22:28:26  /  2021/06/23 22:30:03 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

unsigned int	mdl(int i)
{
	if (i < 0)
		i *= -1;
	return ((unsigned int)i);
}

void	find_distances(t_sort *sort, t_elem *ptrb, t_elem *ptra, t_elem *ret)
{
	int	i;

	i = 0;
	if (mdl(ptra->a) > ret->l)
	{
		ptra->b = 0;
		ptra->l = 0xffffff;
		return ;
	}
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
		find_distances(sort, sort->b, ptr, ret);
		if (ret->w)
			ret->l = 0xffffff;
		if (ret->l > ptr->l && ptr->w == 0)
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
		if (ptr->w)
			ptr->a = 0xfffffff;
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
