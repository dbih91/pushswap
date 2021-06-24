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
/*   Created/Updated: 2021/06/24 03:56:38  /  2021/06/24 04:12:08 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	null_cc(char str[5000000])
{
	int	ptr;

	ptr = 0;
	while (ptr != 5000000)
	{
		str[ptr] = 0;
		ptr++;
	}
}

/*
sa
sb
ss
pa
pb
ra
rb
rr
rra
rrb
rrr
*/

void	check_parce(t_sort *sort, char s[5000000])
{
	if (s[0] == 's' && s[1] == 'a' && s[2] == '\n')
		swap_a(sort);
	else if (s[0] == 's' && s[1] == 'b' && s[2] == '\n')
		swap_b(sort);
	else if (s[0] == 's' && s[1] == 's' && s[2] == '\n')
		swap_s(sort);
	else if (s[0] == 'p' && s[1] == 'a' && s[2] == '\n')
		push_a(sort);
	else if (s[0] == 'p' && s[1] == 'b' && s[2] == '\n')
		push_b(sort);
	else if (s[0] == 'r' && s[1] == 'a' && s[2] == '\n')
		rota_a(sort);
	else if (s[0] == 'r' && s[1] == 'b' && s[2] == '\n')
		rota_b(sort);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == '\n')
		rota_r(sort);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'a' && s[3] == '\n')
		rrta_a(sort);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'b' && s[3] == '\n')
		rrta_b(sort);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'r' && s[3] == '\n')
		rrta_r(sort);
	else
		exit_error();
}

void	checker(t_sort *sort, char s[5000000], int p)
{
	while (s[p] != '\0')
	{
		check_parce(sort, &s[p]);
		if (s[p + 2] == '\n')
			p += 3;
		else
			p += 4;
	}
}

void	checking(t_sort *sort, int *d, unsigned int *i, int c)
{
	char	str[5000000];
	int		ptr;

	ptr = 0;
	null_cc(str);
	create_sort(sort, d, i, c);
	while (read(0, &str[ptr], 1))
		ptr = ft_strlen(str);
	checker(sort, str, 0);
	ok_if_sorted(sort);
	clear_sort(sort);
}

int	main(int c, char *v[])
{
	t_sort				sort;
	unsigned int		*i;
	int					*d;

	sort.a = NULL;
	sort.b = NULL;
	sort.op[0] = 0;
	sort.op[1] = 0;
	sort.op[2] = 0;
	sort.op[3] = 0;
	sort.opr = -1;
	(v++ && c--);
	if (c && not_integer(v[0]))
		exit_error();
	sort.vi = 0;
	if (c == 0)
		return (0);
	convert_and_index(c, v, &d, &i);
	checking(&sort, d, i, c);
	return (0);
}
