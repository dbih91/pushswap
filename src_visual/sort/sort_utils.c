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
/*   Created/Updated: 2021/06/23 16:42:49  /  2021/06/23 16:42:50 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

unsigned int get_smallest(t_elem *stack)
{
	unsigned int	ret;
	t_elem			*ptr;

	ptr = stack;
	ret = 0xffffffff;
	while (ptr)
	{
		if (ptr->i < ret)
			ret = ptr->i;
		ptr = ptr->n;
	}
	return (ret);
}

unsigned int get_biggest(t_elem *stack)
{
	unsigned int	ret;
	t_elem			*ptr;

	
	ptr = stack;
	ret = 0;
	while (ptr)
	{
		if (ptr->i > ret)
			ret = ptr->i;
		ptr = ptr->n;
	}
	return (ret);
}

int not_sorted(t_elem *stack)
{
	t_elem *ptr;

	ptr = stack;
	while (ptr->n)
	{
		if (ptr->i > ptr->n->i &&
	!(ptr->i == get_biggest(stack) && ptr->n->i == get_smallest(stack)))
			return (1);
		ptr = ptr->n;
	}
	return (0);
}

int not_resorted(t_elem *stack)
{
	t_elem *ptr;

	ptr = stack;
	while (ptr->n)
	{
		if (ptr->i < ptr->n->i &&
	!(ptr->i == get_smallest(stack) && ptr->n->i == get_biggest(stack)))
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