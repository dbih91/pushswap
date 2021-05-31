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
/*   visual.c                                 cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/05/31 20:14:53  /  2021/05/31 20:15:25 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

#define TIME 1

void	writesort(t_sort sort)
{
	t_elem *ptr;
	static int it = 0;

	it++;
	ptr = sort.a;
	//printf("| cc %4d | ca %4d | cb %4d | it %4d | sf %4d | ss %4d |", sort.cc, sort.ca, sort.cb, it, sort.sf, sort.ss);
	printf("\n\033[1;32mA[");
	while (ptr)
	{
		printf("%d", ptr->i);
		if (ptr->n)
			printf(", ");
		ptr = ptr->n;
	}
	printf("]\033[0m\n");
	ptr = sort.b;
	printf("\033[1;92mB[");
	while (ptr)
	{
		printf("%d", ptr->i);
		if (ptr->n)
			printf(", ");
		ptr = ptr->n;
	}
	printf("]\033[0m\n+--------=+=-------=+=--------+\n");
}

void	visual(t_sort *sort, char *str)
{
	if (TIME)
		usleep(TIME);
	if (sort->vi != 1 && sort->vi != 0)
	{

	}
	else if (sort->vi == 0)
		write(1, &str, ft_strlen(str));
}