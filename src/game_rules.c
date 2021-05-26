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
/*   Created/Updated: 2021/05/27 00:15:22  /  2021/05/27 00:22:42 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// sa: swap a - swap the first 2 elements at the top of stack a. 
// sb: swap b - swap the first 2 elements at the top of stack b.
// ss: sa and sb at the same time.
//                              (Do nothing if there is only one or no elements)

void	swap_a(t_sort *sort)
{
	t_elem *frst;

	if (sort->a && sort->a->n)
	{
		frst = sort->a;
		sort->a = sort->a->n;
		frst->n = sort->a->n;
		sort->a->n = frst;
	}
	write(1, "sa\n", 3);
	visual(sort);
}

void	swap_b(t_sort *sort)
{
	t_elem *frst;

	if (sort->b && sort->b->n)
	{
		frst = sort->b;
		sort->b = sort->b->n;
		frst->n = sort->b->n;
		sort->b->n = frst;
	}
	write(1, "sb\n", 3);
	visual(sort);
}

void	swap_s(t_sort *sort)
{
	t_elem *frst;
	
	if (sort->b && sort->b->n)
	{
		frst = sort->b;
		sort->b = sort->b->n;
		frst->n = sort->b->n;
		sort->b->n = frst;
	}
	if (sort->a && sort->a->n)
	{
		frst = sort->a;
		sort->a = sort->a->n;
		frst->n = sort->a->n;
		sort->a->n = frst;
	}
	write(1, "ss\n", 3);
	visual(sort);
}

// pa: push a - take first element at the top of b and put it at the top of a.
// pb: push b - take first element at the top of a and put it at the top of b.
//                                               (Do nothing if b or a is empty)

void	push_a(t_sort *sort)
{
	t_elem *ptr;

	if (sort->b)
	{
		sort->cb--;
		sort->ca++;
	}
	if (sort->b && !sort->a) // if a is not
	{
		sort->a = sort->b;
		sort->b = sort->b->n;
		sort->a->n = NULL;
	}
	else if (sort->b)
	{
		ptr = sort->a;
		sort->a = sort->b;
		sort->b = sort->b->n;
		sort->a->n = ptr;
	}
	write(1, "pa\n", 3);
	visual(sort);
}

void	push_b(t_sort *sort)
{
	t_elem *ptr;

	if (sort->a)
	{
		sort->cb++;
		sort->ca--;
	}
	if (sort->a && !sort->b) // if b is not
	{
		sort->b = sort->a;
		sort->a = sort->a->n;
		sort->b->n = NULL;
	}
	else if (sort->a)
	{
		ptr = sort->b;
		sort->b = sort->a;
		sort->a = sort->a->n;
		sort->b->n = ptr;
	}
	write(1, "pb\n", 3);
	visual(sort);
}

// ra : rotate a - shift up all elements of stack a by 1.
// rb : rotate b - shift up all elements of stack b by 1.
// rr : ra and rb at the same time.
//                                      (The first element becomes the last one)

void	rota_a(t_sort *sort)
{
	t_elem *frst;
	t_elem *last;

	if (sort->a && sort->a->n)
	{
		frst = sort->a;
		sort->a = sort->a->n;
		last = sort->a->n;
		while (last->n)
			last = last->n;
		last->n = frst;
		frst->n = NULL;
	}
	write(1, "ra\n", 3);
	visual(sort);
}

void	rota_b(t_sort *sort)
{
	t_elem *frst;
	t_elem *last;

	if (sort->b && sort->b->n)
	{
		frst = sort->b;
		sort->b = sort->b->n;
		last = sort->b->n;
		while (last->n)
			last = last->n;
		last->n = frst;
		frst->n = NULL;
	}
	write(1, "rb\n", 3);
	visual(sort);
}

void	rota_r(t_sort *sort)
{
	t_elem *frst;
	t_elem *last;

	if (sort->a && sort->a->n)
	{
		frst = sort->a;
		frst->n = NULL;
		sort->a = sort->a->n;
		last = sort->a->n;
		while (last->n)
			last = last->n;
		last->n = frst;
	}
	if (sort->b && sort->b->n)
	{
		frst = sort->b;
		frst->n = NULL;
		sort->b = sort->b->n;
		last = sort->b->n;
		while (last->n)
			last = last->n;
		last->n = frst;
	}
	write(1, "rr\n", 3);
	visual(sort);
}

// rra : reverse rotate a - shift down all elements of stack a by 1.
// rrb : reverse rotate b - shift down all elements of stack b by 1.
// rrr : rra and rrb at the same time.
//                                      (The last element becomes the first one)

void	rrta_a(t_sort *sort)
{
	t_elem *last;
	t_elem *prel;

	if (sort->a && sort->a->n)
	{
		prel = sort->a;
		while (prel->n->n)
			prel = prel->n;
		last = prel->n;
		last->n = sort->a;
		prel->n = NULL;
		sort->a = last;
	}
	write(1, "rra\n", 4);
	visual(sort);
}

void	rrta_b(t_sort *sort)
{
	t_elem *last;
	t_elem *prel;

	if (sort->b && sort->b->n)
	{
		prel = sort->b;
		while (prel->n->n)
			prel = prel->n;
		last = prel->n;
		last->n = sort->b;
		prel->n = NULL;
		sort->b = last;
	}
	write(1, "rrb\n", 4);
	visual(sort);
}

void	rrta_r(t_sort *sort)
{
	t_elem *last;
	t_elem *prel;

	if (sort->b && sort->b->n)
	{
		prel = sort->b;
		while (prel->n->n)
			prel = prel->n;
		last = prel->n;
		last->n = sort->b;
		prel->n = NULL;
		sort->b = last;
	}
	if (sort->a && sort->a->n)
	{
		prel = sort->a;
		while (prel->n->n)
			prel = prel->n;
		last = prel->n;
		last->n = sort->a;
		prel->n = NULL;
		sort->a = last;
	}
	write(1, "rrr\n", 4);
	visual(sort);
}
