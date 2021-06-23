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
/*   sw2_sort.c                               cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/06/17 14:40:24  /  2021/06/17 14:40:36 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

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

unsigned int get_half(unsigned int half)
{
	unsigned int bit;

	bit = 0x80000000;
	while (bit && (bit & half) == 0)
		bit = bit >> 1;
	return (bit);
}

void sw2_sort(t_sort *sort)
{
	unsigned int half;
	unsigned int rem;

	half = get_half(sort->l);
	rem = sort->l - half;
}
