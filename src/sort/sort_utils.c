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
/*   sort_utils.c                             cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/06/04 21:46:34  /  2021/06/04 21:51:23 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int a_not_sorted(t_sort *sort)
{
	t_elem *ptr;

	ptr = sort->a;
	while (ptr->n)
	{
		if (ptr->i > ptr->n->i && !(ptr->i == sort->l - 1 && ptr->n->i == 0))
			return (1);
		ptr = ptr->n;
	}
	return (0);
}

unsigned int	index_location(t_sort *sort, unsigned int index)
{
	t_elem			*ptr;
	unsigned int	i;

	i = 0;
	ptr = sort->a;
	while (ptr)
	{
		if (ptr->i == index)
			return (i);
		i++;
		ptr = ptr->n;
	}
	return (i);
}

unsigned int	index_distance(t_sort *sort, unsigned int index)
{
	t_elem			*ptr;
	unsigned int	i;

	i = 0;
	ptr = sort->a;
	while (ptr)
	{
		if (ptr->i == index)
		{
			if (sort->l / 2 > i)
				return (i);
			else
				return (sort->l - i);
		}
		i++;
		ptr = ptr->n;
	}
	return (i);
}