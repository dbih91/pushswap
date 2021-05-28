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
/*   Created/Updated: 2021/05/27 11:43:25  /  2021/05/27 11:50:28 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void exit_error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

int has_duplicate(int *i, int size)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (a < size)
	{
		while (b < size)
		{
			if (b != a && i[a] == i[b])
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

void	valid(int c, char *v[], int **i)
{
	int p;

	i[0] = (int *)malloc(sizeof(int) * c);
	if (!i[0])
		exit_error();
	p = 1;
	while (p < c)
	{
		if (not_integer(v[p]))
			exit_error();
		i[0][p - 1] = ft_atoi(v[p]);
		//printf("ATOI: %d\n", i[0][p - 1]);
		p++;
	}
	if (has_duplicate(i[0], c - 1))
		exit_error();
}

t_elem	*ft_newelem(int nbr)
{
	t_elem *ptr;

	ptr = malloc(sizeof(t_elem));
	if (!ptr)
		exit_error();
	ptr->n = NULL;
	ptr->i = nbr;
	return (ptr);
}

t_elem	*create_list(int *i, int c)
{
	t_elem	*ptr;
	t_elem	*ret;
	int		ip;

	ip = 0;
	ret = ft_newelem(i[ip++]);
	ptr = ret;
	while (ip < c)
	{
		ptr->n = ft_newelem(i[ip++]);
		ptr = ptr->n;
	}
	ptr->n = NULL;
	return (ret);
}

int	main(int c, char *v[])
{
	int		*i;
	t_sort	sort;

	sort.b = NULL;
	valid(c, v, &i);
	if (c >= 3)
	{
		sort.a = create_list(i, c - 1);
		init_sort(&sort);
	}
	return (0);
}

//	int	main(int c, char *v[])
//	{
//		int	*i;
//		int	p;
//	
//		i = (int *)malloc(sizeof(int) * c);
//		p = 0;
//		if (c == 1)
//			write(1, "Error\n", 14);
//		else if (c-- == 2)
//			write(1, "Error\n", 14);
//		else
//		{
//			while (p++ < c)
//				i[p] = ft_atoi(v[p]);
//			if (!numcheck(i, p))
//			{
//				p = 0;
//				while (p++ < c)
//				{
//					ft_putint(p);
//					write(1, ": ", 2);
//					ft_putint(i[p]);
//					write(1, "\n", 1);
//				}
//			}
//			else
//			{
//				write(1, "Duplicates!!!\n", 14);
//				return (1);
//			}
//		}
//		return (2);
//	}
