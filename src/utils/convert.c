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
/*   convert.c                                cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/05/31 19:54:28  /  2021/05/31 19:54:44 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	has_duplicate(int *d, int size)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (a < size)
	{
		while (b < size)
		{
			if (b != a && d[a] == d[b])
				return (1);
			b++;
		}
		a++;
		b = 0;
	}
	return (0);
}

int	not_integer(const char *str)
{
	int	len;
	int	min;

	len = 0;
	min = 0;
	if ((str[len] == '-' && ++min) || str[len] == '+')
		str++;
	while (str[len] >= '0' && str[len] <= '9' && len <= 8)
		len++;
	if ((min == 0 && len == 9 && str[len] >= '0' && str[len] <= '7')
		|| (min == 1 && len == 9 && str[len] >= '0' && str[len] <= '8'))
		len++;
	if (str[len] != '\0')
		return (1);
	return (0);
}

int	get_smallest_index(int **d, int *s, int c)
{
	int	index;
	int	ptr;
	int	smallest;

	smallest = 2147483647;
	ptr = 0;
	index = 0;
	while (ptr < c)
	{
		if (smallest > d[0][ptr] && *s < d[0][ptr])
		{
			index = ptr;
			smallest = d[0][ptr];
		}
		ptr++;
	}
	*s = d[0][index];
	return (index);
}

void	index_array(int **d, unsigned int **i, int c)
{
	int	index;
	int	s;

	index = 0;
	s = -2147483648;
	while (index < c)
	{
		i[0][get_smallest_index(d, &s, c)] = index;
		index++;
	}
}

void	convert_and_index(int c, char *v[], int **d, unsigned int **i)
{
	int	ptr;

	d[0] = (int *)malloc(sizeof(int) * c);
	i[0] = (unsigned int *)malloc(sizeof(int) * c);
	if (!d[0] || !i[0])
		exit_error();
	ptr = 0;
	while (ptr < c)
	{
		if (not_integer(v[ptr]))
			exit_error();
		i[0][ptr] = 0;
		d[0][ptr] = ft_atoi(v[ptr]);
		ptr++;
	}
	index_array(d, i, c);
	if (has_duplicate(d[0], c - 1))
		exit_error();
}
