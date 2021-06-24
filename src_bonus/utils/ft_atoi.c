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
/*   ft_atoi.c                                cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/06/24 03:50:22  /  2021/06/24 03:50:28 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	ft_atoi(const char *str)
{
	const char	sgn = 1 - (*str == '-') * 2;
	int			ret;

	ret = 0;
	str += (*str == '-' || *str == '+');
	while (*str == '0')
		str++;
	while ((*str >= '0' && *str <= '9' && ret <= 214748363)
		|| (*str >= '0' && *str <= '7' && ret == 214748364))
	{
		ret *= 10;
		ret += *str - '0';
		str++;
	}
	if (*str >= '0' && *str <= '9')
	{
		if (sgn == 1)
			return (2147483647);
		return (-2147483648);
	}
	return (ret * sgn);
}

t_elem	*create_list(int *d, unsigned int *i, int c, unsigned int *l)
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
	*l = ip;
	return (ret);
}

void	clear_sort(t_sort *sort)
{
	t_elem	*ptr;
	t_elem	*nxt;

	ptr = sort->a;
	while (ptr)
	{
		nxt = ptr->n;
		free(ptr);
		ptr = nxt;
	}
	ptr = sort->b;
	while (ptr)
	{
		nxt = ptr->n;
		free(ptr);
		ptr = nxt;
	}
	sort->a = NULL;
	sort->b = NULL;
}

t_sort	*create_sort(t_sort *sort, int *d, unsigned int *i, int c)
{
	t_elem	*last;

	clear_sort(sort);
	sort->a = create_list(d, i, c, &sort->l);
	sort->la = sort->l;
	sort->lb = 0;
	last = sort->a;
	while (last->n)
		last = last->n;
	sort->al = last;
	sort->bl = NULL;
	return (sort);
}
