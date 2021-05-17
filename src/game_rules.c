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
/*   game_rules.c                             cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/05/17 23:49:04  /  2021/05/17 23:49:57 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// sa: swap a - swap the first 2 elements at the top of stack a. 
// sb: swap b - swap the first 2 elements at the top of stack b.
// ss: sa and sb at the same time.
//                              (Do nothing if there is only one or no elements)

void	swap_a(t_sort *sort)
{
	int temp;


	if (!sort->a || !sort->a->n)
		return ;
	temp = sort->a->n->i;
	sort->a->n->i = sort->a->i;
	sort->a->i = temp;
}

void	swap_b(t_sort *sort)
{
	int temp;

	if (!sort->b || !sort->b->n)
		return ;
	temp = sort->b->n->i;
	sort->b->n->i = sort->b->i;
	sort->b->i = temp;
}

void	swap_s(t_sort *sort)
{
	swap_a(sort);
	swap_b(sort);
}

// pa: push a - take first element at the top of b and put it at the top of a.
// pb: push b - take first element at the top of a and put it at the top of b.
//                                               (Do nothing if b or a is empty)

void	push_a(t_sort *sort)
{
	sort->a = NULL;
}

void	push_b(t_sort *sort)
{
	sort->b = NULL;
}

// ra : rotate a - shift up all elements of stack a by 1.
// rb : rotate b - shift up all elements of stack b by 1.
// rr : ra and rb at the same time.
//                                      (The first element becomes the last one)

void	rota_a(t_sort *sort)
{
	sort->b = NULL;
}

void	rota_b(t_sort *sort)
{
	sort->b = NULL;
}

void	rota_r(t_sort *sort)
{
	sort->b = NULL;
}

// rra : reverse rotate a - shift down all elements of stack a by 1.
// rrb : reverse rotate b - shift down all elements of stack b by 1.
// rrr : rra and rrb at the same time.
//                                      (The last element becomes the first one)

void	rrta_a(t_sort *sort)
{
	sort->b = NULL;
}

void	rrta_b(t_sort *sort)
{
	sort->b = NULL;
}

void	rrta_r(t_sort *sort)
{
	sort->b = NULL;
}
