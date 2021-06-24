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
/*   Created/Updated: 2021/06/24 00:00:36  /  2021/06/24 00:00:40 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

//void	i_hate_norminette_0(t_sort *sort, t_elem *ptr, unsigned int *i)
//{
//
//}

void	i_hate_norminette_1(t_sort *sort, t_elem *ptr)
{
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
}

void	i_hate_norminette_2(t_sort *sort)
{	
	if (sort->a)
	{
		while (get_dist_i(sort->a, sort->la, get_smallest(sort->a)) != 0)
		{
			if (get_dist_i(sort->a, sort->la, get_smallest(sort->a)) > 0
				&& get_dist_i(sort->b, sort->lb, get_biggest(sort->b)) > 0)
				rota_r(sort);
			else if (get_dist_i(sort->a, sort->la, get_smallest(sort->a)) < 0
				&& get_dist_i(sort->b, sort->lb, get_biggest(sort->b)) < 0)
				rrta_r(sort);
			else if (get_dist_i(sort->a, sort->la, get_smallest(sort->a)) > 0)
				rota_a(sort);
			else
				rrta_a(sort);
		}
	}
}

void	i_hate_norminette_3(t_sort *sort, unsigned int *i)
{
	while (get_dist_i(sort->b, sort->lb, get_biggest(sort->b)) != 0)
	{
		if (get_dist_i(sort->b, sort->lb, get_biggest(sort->b)) > 0)
			rota_b(sort);
		else
			rrta_b(sort);
	}
	i[0] = sort->l - 1;
	while (sort->b)
	{
		while (sort->b && sort->b->i == i[0])
		{
			i[0]--;
			push_a(sort);
		}
		if (sort->al->i == i[0])
		{
			i[0]--;
			rrta_a(sort);
		}
	}
}

void	whl_sort(t_sort *sort, unsigned int m)
{
	t_elem			*ptr;
	unsigned int	i;

	i = 1;
	push_min_max(sort);
	while (a_has_w(sort->a))
	{
		if (m == 0)
			ptr = get_distances(sort);
		if (i && ((m == 0 && sort->lb > sort->l / 2 && ptr->l > sort->l / 20)
				|| (m == 1 && sort->lb > sort->l / 2)
				|| (m == 2 && sort->lb >= sort->l / 2 - sort->l / 20)
				|| (m == 3 && sort->lb >= sort->l / 2 - sort->l / 10)) && i--)
		{
			while (sort->lb != 2 && ++sort->b->w)
			{
				while (sort->b->i == 0 || sort->b->i == sort->l - 1)
					rota_b(sort);
				push_a(sort);
			}
		}
		i_hate_norminette_1(sort, ptr);
	}
	i_hate_norminette_2(sort);
	i_hate_norminette_3(sort, &i);
}
