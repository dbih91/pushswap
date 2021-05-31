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
/*   main.c                                   cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/05/31 19:52:53  /  2021/05/31 19:52:55 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	exit_error(void)
{
	write(1, "Error\n", 6);
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
	return (ptr);
}

t_elem	*create_list(int *d, unsigned int *i, int c)
{
	t_elem	*ptr;
	t_elem	*ret;
	int		ip;

	ip = 0;
	ret = ft_newelem(d[ip], i[ip]);
	ip++;
	ptr = ret;
	while (ip < c)
	{
		ptr->n = ft_newelem(d[ip], i[ip]);
		ip++;
		ptr = ptr->n;
	}
	ptr->n = NULL;
	return (ret);
}

void	sorting(t_sort *sort, int *d, unsigned int *i, int c)
{
	sort->a = create_list(d, i, c - 1);
}

int	main(int c, char *v[])
{
	t_sort				sort;
	unsigned int		*i;
	int					*d;

	sort.b = NULL;
	(v++ && c--);
	if (c <= 1)
		return (0);
	if (v[0][0] && v[0][1] &&
		v[0][0] == '-' && v[0][1] == 'v' && v[0][2] >= '0' && v[0][2] <= '9')
		(v++ && c--);
	convert_and_index(c, v, &d, &i);
	sorting(&sort, d, i, c);
	return (0);
}
