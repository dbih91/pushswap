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
/*   Created/Updated: 2021/06/24 00:21:59  /  2021/06/24 00:54:07 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

unsigned int	get_smallest(t_elem *stack)
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

unsigned int	get_biggest(t_elem *stack)
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

void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

t_elem	*ft_newelem(int nbr, unsigned int index)
{
	t_elem	*ptr;

	ptr = malloc(sizeof(t_elem));
	if (!ptr)
		exit_error();
	ptr->n = NULL;
	ptr->d = nbr;
	ptr->i = index;
	ptr->w = 0;
	return (ptr);
}

void	exit_if_sorted(t_sort *sort)
{
	t_elem	*ptr;

	ptr = sort->a;
	if (!ptr || !ptr->n)
		exit(0);
	while (ptr->n)
	{
		if (ptr->i > ptr->n->i)
			return ;
		ptr = ptr->n;
	}
	exit(0);
}
