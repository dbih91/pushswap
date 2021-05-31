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
/*   Created/Updated: 2021/05/31 19:13:59  /  2021/05/31 19:14:00 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void exit_error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

int has_duplicate(int *d, int size)
{
	int a;
	int b;

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

int not_integer(const char *str)
{
	int len;
	int min;

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

int get_smallest_index(int **d, int *s, int c)
{
	int index;
	int ptr;
	int smallest;

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

void index_array(int **d, unsigned int **i, int c)
{
	int index;
	int s;

	index = 0;
	s = -2147483648;
	while (index < c)
	{
		i[0][get_smallest_index(d, &s, c)] = index;
		index++;
	}
}

void	valid(int c, char *v[], int **d, unsigned int **i)
{
	int ptr;

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

t_elem	*ft_newelem(int nbr, unsigned int index)
{
	t_elem *ptr;

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

void	temp(int **d, unsigned int **i, int c)
{
	int a;

	a = 0;
	while (a < c)
	{
		printf("%d %d\n", d[0][a], i[0][a]);
		a++;
	}
}

int	main(int c, char *v[])
{
	int		*d;
	unsigned int		*i;
	t_sort	sort;

	sort.b = NULL;
	c--;
	v++;
	if (v[0][0] == '-' && v[0][1] == 'v' && v[0][2] >= '0' && v[0][2] <= '9')
	{
		c--;
		v++;
	}
	valid(c, v, &d, &i);
	temp(&d, &i, c);
	if (c >= 2)
		sorting(&sort, d, i, c);
	return (0);
}
