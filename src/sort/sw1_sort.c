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
/*   sw1_sort.c                               cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/06/24 06:36:17  /  2021/06/24 06:36:17 @cclarice   */
/*                                                                            */
/* ************************************************************************** */
/*                                                                            */
/*   One stack swap sort                                                      */
/*                                                                            */
/*   Using only stack a for sorting                                           */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	sw1_sort4(t_sort *sort)
{
	while (sort->lb <= 1)
	{
		if (sort->a->i <= 1)
			push_b(sort);
		else
			rota_a(sort);
	}
	if ((sort->b->i < sort->b->n->i) && (sort->a->i > sort->a->n->i))
		swap_s(sort);
	else if (sort->a->i > sort->a->n->i)
		swap_a(sort);
	else if (sort->b->i < sort->b->n->i)
		swap_b(sort);
	push_a(sort);
	push_a(sort);
}

void	sw1_sort5a(t_sort *sort)
{
	if (sort->a->i == 2 && sort->a->n->i == 4 && sort->a->n->n->i == 3)
	{
		swap_a(sort);
		rota_a(sort);
	}
	else if (sort->a->i == 3 && sort->a->n->i == 2 && sort->a->n->n->i == 4)
		swap_a(sort);
	else if (sort->a->i == 3 && sort->a->n->i == 4 && sort->a->n->n->i == 2)
		rrta_a(sort);
	else if (sort->a->i == 4 && sort->a->n->i == 2 && sort->a->n->n->i == 3)
		rota_a(sort);
	else if (sort->a->i == 4 && sort->a->n->i == 3 && sort->a->n->n->i == 2)
	{
		swap_a(sort);
		rrta_a(sort);
	}
}

void	sw1_sort5b(t_sort *sort)
{
	if (sort->a->i == 2 && sort->a->n->i == 4 && sort->a->n->n->i == 3)
	{
		swap_s(sort);
		rota_a(sort);
	}
	else if (sort->a->i == 3 && sort->a->n->i == 2 && sort->a->n->n->i == 4)
		swap_s(sort);
	else if (sort->a->i == 3 && sort->a->n->i == 4 && sort->a->n->n->i == 2)
		rrta_r(sort);
	else if (sort->a->i == 4 && sort->a->n->i == 2 && sort->a->n->n->i == 3)
		rota_r(sort);
	else if (sort->a->i == 4 && sort->a->n->i == 3 && sort->a->n->n->i == 2)
	{
		swap_s(sort);
		rrta_a(sort);
	}
	else
		swap_b(sort);
}

void	sw1_sort5(t_sort *sort)
{
	while (sort->lb <= 1)
	{
		if (sort->a->i <= 1)
			push_b(sort);
		else if (sort->al->i <= 1)
			rrta_a(sort);
		else
			rota_a(sort);
	}
	if (sort->b->i < sort->b->n->i)
		sw1_sort5b(sort);
	else
		sw1_sort5a(sort);
	while (sort->b)
		push_a(sort);
}

void	sw1_sort(t_sort *sort)
{
	if (sort->l <= 2 && sort->a->i == 1)
		swap_a(sort);
	else if (sort->l == 4)
		sw1_sort4(sort);
	else if (sort->l == 5)
		sw1_sort5(sort);
	else if (sort->a->i == 0 && sort->a->n->i == 2 && sort->a->n->n->i == 1)
	{
		swap_a(sort);
		rota_a(sort);
	}
	else if (sort->a->i == 1 && sort->a->n->i == 0 && sort->a->n->n->i == 2)
		swap_a(sort);
	else if (sort->a->i == 1 && sort->a->n->i == 2 && sort->a->n->n->i == 0)
		rrta_a(sort);
	else if (sort->a->i == 2 && sort->a->n->i == 0 && sort->a->n->n->i == 1)
		rota_a(sort);
	else if (sort->a->i == 2 && sort->a->n->i == 1 && sort->a->n->n->i == 0)
	{
		swap_a(sort);
		rrta_a(sort);
	}
}
