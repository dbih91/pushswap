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
/*   Created/Updated: 2021/06/01 20:45:17  /  2021/06/01 20:45:20 @cclarice   */
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

int		ft_numlen(int i)
{
	int ret;

	ret = 1;
	if (i <= -1)
		ret = 2;
	while (i / 10)
	{
		i /= 10;
		ret++;
	}
	return (ret);
}

int		ft_numwidht(t_sort *sort)
{
	static int		ret = 0;
	int				cur;
	t_elem			*ptr;

	if (ret != 0)
		return (ret);
	ptr = sort->a;
	while (ptr)
	{
		cur = ft_numlen(ptr->d);
		ptr = ptr->n;
		if (ret < cur)
			ret = cur;
		printf("visl.nw = %d\n", cur);
	}
	ptr = sort->b;
	while (ptr)
	{
		cur = ft_numlen(ptr->d);
		ptr = ptr->n;
		if (ret < cur)
			ret = cur;
	}
	return (ret);
}

void	fill_spaces(char *str)
{
	int c;

	c = 0;
	while (c < TW)
	{
		str[c] = ' ';
		c++;
	}
	str[c] = '\n';
	str[c + 1] = '\0';
}

void	put_frst(t_sort *sort, const char *cmd, t_visl visl, char *str)
{
	int p;

	p = 7;
	str[0] = '/';
	str[2] = cmd[0];
	str[3] = cmd[1];
	if (cmd[2])
		str[4] = cmd[2];
	while (p < TW)
	{
		str[p] = '|';
		p += visl.nw;
	}
	str[TW - 1] = '\\';
	sort->l = 0;
	write(1, str, ft_strlen(str));
}

void	put_scnd(t_sort *sort, const char *cmd, t_visl visl, char *str)
{
	int p;

	p = 7;
	str[0] = '|';
	str[2] = ' ';
	str[3] = ' ';
	str[4] = ' ';
	while (p < TW)
	{
		str[p] = '|';
		p += visl.nw;
	}
	str[TW - 1] = '\\';
	sort->l = 0;
	write(1, str, ft_strlen(str));
}

void	put_sort(t_sort *sort, const char *cmd, t_visl visl)
{
	static char *str = NULL;

	if (str == NULL)
		str = (char *)malloc(sizeof(char) * TW + 2);
	fill_spaces(str);
	put_frst(sort, cmd, visl, str);
	put_scnd(sort, cmd, visl, str);
}

void	visual(t_sort *sort, const char *cmd)
{
	t_visl visl;

	if (TIME)
		usleep(TIME);
	if (sort->vi <= -1)
	{
		visl.tw = TW;
		visl.ctw = 0;
		visl.nw = ft_numwidht(sort) + 1;
		put_sort(sort, cmd, visl);
	}
	else if (sort->vi == 0)
		write(1, cmd, ft_strlen(cmd));
}