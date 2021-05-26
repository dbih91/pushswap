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
/*   pushswap.h                               cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/05/26 22:49:16  /  2021/05/26 23:06:33 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>

#include <stdio.h>
#include <time.h>

// includes:
//     unistd: read() write()
//     stdlib: malloc() free()
//     exit()

typedef struct s_elem
{
	int					i;
	struct s_elem		*n;
}				t_elem;

//	struct Sort
//
//	*a - start of a stack
//	*b - start of b stack
//	cc - count all
//	ca - count a
//	cb - count b
//	sf - smallest first
//	ss - smallest second
//	fr - sf rotate  if +1 is rota_a
//	sr - ss rotate  if -1 is rrta_a

typedef struct s_sort
{
	t_elem			*a;
	t_elem			*b;
	unsigned int	cc;
	unsigned int	ca;
	unsigned int	cb;
	int				sf;
	int				ss;
	int				fr;
	int				sr;
}				t_sort;

// utils

unsigned int			ft_strlen(const char *str);
int						ft_atoi(const char *str);
void					ft_putint(int i);
void					visual(t_sort *sort);

// sort

void	init_sort(t_sort *sort);

// game rules

void	swap_a(t_sort *sort);
void	swap_b(t_sort *sort);
void	swap_s(t_sort *sort);
void	push_a(t_sort *sort);
void	push_b(t_sort *sort);
void	rota_a(t_sort *sort);
void	rota_b(t_sort *sort);
void	rota_r(t_sort *sort);
void	rrta_a(t_sort *sort);
void	rrta_b(t_sort *sort);

#endif
