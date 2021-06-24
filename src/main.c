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
/*   Created/Updated: 2021/06/24 05:49:43  /  2021/06/24 05:50:37 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sorting(t_sort *sort, int *d, unsigned int *i, int c)
{
	create_sort(sort, d, i, c);
	if (sort->l >= 6 && sort->l < 750)
	{
		whl_sort(sort, ++sort->opr);
		whl_sort(create_sort(sort, d, i, c), ++sort->opr);
		whl_sort(create_sort(sort, d, i, c), ++sort->opr);
		whl_sort(create_sort(sort, d, i, c), ++sort->opr);
		sort->vi = 1;
		if (sort->op[0] <= sort->op[1] && sort->op[0] <= sort->op[2]
			&& sort->op[0] <= sort->op[3])
			whl_sort(create_sort(sort, d, i, c), 0);
		else if (sort->op[1] <= sort->op[0] && sort->op[1] <= sort->op[2]
			&& sort->op[1] <= sort->op[3])
			whl_sort(create_sort(sort, d, i, c), 1);
		else if (sort->op[2] <= sort->op[0] && sort->op[2] <= sort->op[1]
			&& sort->op[1] <= sort->op[3])
			whl_sort(create_sort(sort, d, i, c), 2);
		else
			whl_sort(create_sort(sort, d, i, c), 3);
	}
	else if (++sort->vi && sort->l >= 750)
		whl_sort(sort, 1);
	else
		sw1_sort(sort);
	clear_sort(sort);
}

void	sort_ready(t_sort *sort)
{
	sort->a = NULL;
	sort->b = NULL;
	sort->op[0] = 0;
	sort->op[1] = 0;
	sort->op[2] = 0;
	sort->op[3] = 0;
	sort->opr = -1;
	sort->vi = 0;
}

char	**remake_me(char *str, int c)
{
	char	**v;
	int		ptr;

	ptr = 0;
	v = (char **)malloc(sizeof(char *) * c);
	if (!v)
		exit_error();
	while (*str)
	{
		if (*str == '-' || (*str >= '0' && *str <= '9'))
		{
			v[ptr++] = str;
			while (*str == '-' || (*str >= '0' && *str <= '9'))
				str++;
		}
		else if (*str == ' ')
		{
			*str = '\0';
			str++;
		}
		else
			exit_error();
	}
	return (v);
}

int	count_me(char *str)
{
	int	c;

	c = 0;
	while (*str)
	{
		if ((*str == '-' && str[1] >= '0' && str[1] <= '9')
			|| (*str >= '0' && *str <= '9'))
		{
			c++;
			while (*str == '-' || (*str >= '0' && *str <= '9'))
				str++;
		}
		else if (*str == ' ')
			str++;
		else
			exit_error();
	}
	return (c);
}

int	main(int c, char *v[])
{
	t_sort				sort;
	unsigned int		*i;
	int					*d;
	int					ptr;

	sort_ready(&sort);
	ptr = 0;
	if (--c == 0)
		return (0);
	while (c != 0)
	{
		if (v[1][ptr] == 0 && --c)
			v[1][ptr] = ' ';
		ptr++;
	}
	c = count_me(v[1]);
	v = remake_me(v[1], c);
	if (c && not_integer(v[0]))
		exit_error();
	if (c <= 1)
		return (0);
	convert_and_index(c, v, &d, &i);
	sorting(&sort, d, i, c);
	free(v);
	return (0);
}
