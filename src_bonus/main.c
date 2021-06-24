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
/*   Created/Updated: 2021/06/24 05:27:10  /  2021/06/24 05:27:12 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
		if (*str == '-' || (*str >= '0' && *str <= '9'))
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
	c--;
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
	checking(&sort, d, i, c);
	free(v);
	return (0);
}
