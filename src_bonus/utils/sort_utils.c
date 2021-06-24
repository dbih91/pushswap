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
/*   Created/Updated: 2021/06/24 03:25:04  /  2021/06/24 03:36:48 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

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

void	ok_if_sorted(t_sort *sort)
{
	t_elem	*ptr;

	ptr = sort->a;
	if (!ptr || !ptr->n)
	{
		write(1, "OK\n", 3);
		return ;
	}
	while (ptr->n)
	{
		if (ptr->i > ptr->n->i)
		{
			write(1, "KO\n", 3);
			return ;
		}
		ptr = ptr->n;
	}
	write(1, "OK\n", 3);
}
