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
/*   Created/Updated: 2021/06/19 14:39:55  /  2021/06/19 14:40:04 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

#define TIME 100000

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

void	put_frst(t_sort *sort, const char *cmd, t_visl visl)
{
	write(1, "/ ", 2);
	write(1, cmd, ft_strlen(cmd) - 1);
	if (ft_strlen(cmd) == 3)
		write(1 , "  ", 1);
	write(1, "  |", 3);
	visl.ctw = 10;
	if (cmd[0] == 'p' && cmd[1] == 'b')
	{
		visl.ctw += visl.nw;
		write(1, "\033[32mv\033[0m          ", visl.nw - 1 + 10);
		write(1, ".", 1);
	}
	if (cmd[0] == 'p' && cmd[1] == 'a')
	{
		visl.ctw += visl.nw;
		write(1, "^          ", visl.nw - 1);
		write(1, ".", 1);
	}
	if (cmd[0] == 's' && cmd[1] != 'b')
	{
		visl.ctw += visl.nw * 2;
		write(1, "v          ", visl.nw - 1);
		write(1, ".", 1);
		write(1, "v          ", visl.nw - 1);
		write(1, ".", 1);
	}
	while (visl.ctw < TW)
	{
		write(1, "           ", visl.nw - 1);
		visl.ctw += visl.nw;
		if (visl.ctw >= TW)
			write(1, "\\", 1);
		else
			write(1, ".", 1);
	}
	write(1, "\n", 1);
	sort->trash = 0;
}

void	put_scnd(t_sort *sort, t_visl visl)
{
	t_elem *ptr;

	ptr = sort->a;
	write(1, "|", 1);
	put_digit(sort->la, 5, 100000, 100000);
	write(1, "A|", 2);
	visl.ctw = 10;
	while (ptr || visl.ctw == 10)
	{
		while (visl.ctw < TW)
		{
			if (ptr)
			{
				put_digit(ptr->d, visl.nw, ptr->i, visl.per_color);
				ptr = ptr->n;
			}
			else
			{
				write(1, "           ", visl.nw - 1);
				if (visl.ctw == TW - 1)
					write(1, "\\", 1);
				else
					write(1, "|", 1);
			}
			visl.ctw += visl.nw;
		}
		write(1, "\n", 1);
		if (ptr)
			write(1, "|      |", 8);
		visl.ctw = 11;
	}
	sort->trash = 0;
}

void	put_trht(t_sort *sort, t_visl visl)
{
	t_elem *ptr;

	ptr = sort->b;
	write(1, "|", 1);
	put_digit(sort->lb, 5, 100000, 100000);
	write(1, "B|", 2);
	visl.ctw = 10;
	while (ptr || visl.ctw == 10)
	{
		while (visl.ctw < TW)
		{
			if (ptr)
			{
				put_digit(ptr->d, visl.nw, ptr->i, visl.per_color);
				ptr = ptr->n;
			}
			else
			{
				write(1, "           ", visl.nw - 1);
				if (visl.ctw == TW - 1)
					write(1, "\\", 1);
				else
					write(1, "|", 1);
			}
			visl.ctw += visl.nw;
		}
		write(1, "\n", 1);
		if (ptr)
			write(1, "|      |", 8);
		visl.ctw = 11;
	}
	sort->trash = 0;
}

void	put_end(t_sort *sort, const char *cmd, t_visl visl)
{
	write(1, "\\ ", 2);
	put_digit(sort->op[0], 6, 100000, 100000);
	visl.ctw = 10;
	if (cmd[0] == 'p' && cmd[1] == 'b')
	{
		visl.ctw += visl.nw;
		write(1, "v          ", visl.nw - 1);
		write(1, "'", 1);
	}
	if (cmd[0] == 'p' && cmd[1] == 'a')
	{
		visl.ctw += visl.nw;
		write(1, "^          ", visl.nw - 1);
		write(1, "'", 1);
	}
	if (cmd[0] == 's' && cmd[1] != 'a')
	{
		visl.ctw += visl.nw * 2;
		write(1, "^          ", visl.nw - 1);
		write(1, "'", 1);
		write(1, "^          ", visl.nw - 1);
		write(1, "'", 1);
	}
	while (visl.ctw < TW)
	{
		write(1, "           ", visl.nw - 1);
		visl.ctw += visl.nw;
		if (visl.ctw >= TW)
			write(1, "/", 1);
		else
			write(1, "'", 1);
	}
	write(1, "\n", 1);
	sort->trash = cmd[0];
}

void	put_sort(t_sort *sort, const char *cmd, t_visl visl)
{
	put_frst(sort, cmd, visl);
	put_scnd(sort, visl);
	put_trht(sort, visl);
	put_end(sort, cmd, visl);
}

void	visual(t_sort *sort, const char *cmd)
{
	t_visl visl;

	if (TIME)
		usleep(TIME);
	if (sort->vi <= -1)
	{
		sort->op[0]++;
		write(1, "\n", 1);
		visl.tw = TW;
		visl.ctw = 0;
		visl.nw = ft_numwidht(sort) + 1;
		visl.per_color = 223 / sort->l;
		if (visl.per_color == 0)
			visl.per_color = (sort->l / 223) * -1;
		put_sort(sort, cmd, visl);
	}
	else if (sort->vi == 0)
		write(1, cmd, ft_strlen(cmd));
}

//void	fill_spaces(char *str)
//{
//	int c;
//
//	c = 0;
//	while (c < TW)
//	{
//		str[c] = ' ';
//		c++;
//	}
//	str[c] = '\n';
//	str[c + 1] = '\0';
//}
//
//void	itoa(int i, char *str, int p)
//{
//
//}
//
//void	put_frst(t_sort *sort, const char *cmd, t_visl visl, char *str)
//{
//	int p;
//	t_elem *ptr;
//
//	p = 7;
//	str[0] = '/';
//	str[2] = cmd[0];
//	str[3] = cmd[1];
//	if (cmd[2])
//		str[4] = cmd[2];
//	while (p < TW)
//	{
//		str[p] = '|';
//		p += visl.nw;
//	}
//	str[TW - 1] = '\\';
//	sort->l = 0;
//	write(1, str, ft_strlen(str));
//}
//
//void	put_scnd(t_sort *sort, t_visl visl, char *str)
//{
//	int p;
//
//	p = 7;
//	str[0] = '|';
//	str[2] = ' ';
//	str[3] = ' ';
//	str[4] = ' ';
//	str[6] = 'A';
//	while (p < TW)
//	{
//		str[p] = '|';
//		p += visl.nw;
//	}
//	str[TW - 1] = '\\';
//	sort->l = 0;
//	write(1, str, ft_strlen(str));
//}

//  void	writesort(t_sort sort)
//  {
//  	t_elem *ptr;
//  	static int it = 0;
//  
//  	it++;
//  	ptr = sort.a;
//  	//printf("| cc %4d | ca %4d | cb %4d | it %4d | sf %4d | ss %4d |", sort.cc, sort.ca, sort.cb, it, sort.sf, sort.ss);
//  	printf("\n\033[1;32mA[");
//  	while (ptr)
//  	{
//  		printf("%d", ptr->i);
//  		if (ptr->n)
//  			printf(", ");
//  		ptr = ptr->n;
//  	}
//  	printf("]\033[0m\n");
//  	ptr = sort.b;
//  	printf("\033[1;92mB[");
//  	while (ptr)
//  	{
//  		printf("%d", ptr->i);
//  		if (ptr->n)
//  			printf(", ");
//  		ptr = ptr->n;
//  	}
//  	printf("]\033[0m\n+--------=+=-------=+=--------+\n");
//  }