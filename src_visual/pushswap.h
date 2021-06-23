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
/*   Created/Updated: 2021/06/22 16:02:36  /  2021/06/22 16:02:39 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>

#include <stdio.h>
#include <time.h>

#define TW 190

// includes:
//     unistd: read() write()
//     stdlib: malloc() free()
//     exit()

//	Struct Element
//	
//	d - (Digit) integer
//	i - (Index) index of number
//	a - (rotate)
//	b - (rotate)
//	n - (Next) next element

typedef struct s_elem
{
	int					d;
	unsigned int		i;
	int					a;
	int					b;
	unsigned int		l;
	struct s_elem		*n;
	unsigned int		w;
}				t_elem;

//	struct Sort
//
//	*a - start of a stack
//	*b - start of b stack
//	l  - len all
//	la - len a
//	lb - len b
//	sa - smallest index of a
//	sb - smallest index of b
//	ba - biggest index of a
//	bb - biggest index of b
//	op - Operations of 
//	vi - Visual:  0 - just return amount of opertaions.
//                1 - put output.
//	             -1 - put advanced output for p2b_sort method
//	             -2 - put advanced output for 1sw_sort method
//	             -3 - put advanced output for 2sw_sort method

typedef struct s_sort
{
	t_elem			*a;
	t_elem			*b;
	t_elem			*al;
	t_elem			*bl;
	unsigned int	l;
	unsigned int	la;
	unsigned int	lb;
	int				sf;
	int				ss;
	int				fr;
	int				sr;
	unsigned int	opr;
	unsigned int	op[4];
	int				vi;
	int				trash;
}				t_sort;

typedef struct s_visl
{
	unsigned short	nw;
	unsigned short	lw;
	unsigned short	tw;
	unsigned short	ctw;
	int				per_color;
}				t_visl;

// Utils

void			exit_error(void);
void			convert_and_index(int c, char *v[], int **d, unsigned int **i);
unsigned int	ft_strlen(const char *str);
void			init_sort(t_sort *sort);
void			ft_putint(int i);
int				ft_atoi(const char *str);

void			put_digit(int d, int w, unsigned int i, int c);
void			visual(t_sort *sort, const char *str);

// Sorting Algoritms

void			sw1_sort(t_sort *sort);
void			sw2_sort(t_sort *sort);
void			p2b_sort(t_sort *sort);
void			qck_sort(t_sort *sort);
void			whl_sort_0(t_sort *sort);
void			whl_sort_1(t_sort *sort);
void			whl_sort_2(t_sort *sort);
void			whl_sort_3(t_sort *sort);

// Sorting Utils

unsigned int	get_smallest(t_elem *stack);
unsigned int	get_biggest(t_elem *stack);
int 			not_sorted(t_elem *stack);
int 			not_resorted(t_elem *stack);
unsigned int	index_location(t_sort *sort, unsigned int index);
unsigned int	index_distance(t_sort *sort, unsigned int index);

// game rules

void			swap_a(t_sort *sort);
void			swap_b(t_sort *sort);
void			swap_s(t_sort *sort);
void			push_a(t_sort *sort);
void			push_b(t_sort *sort);
void			rota_a(t_sort *sort);
void			rota_b(t_sort *sort);
void			rota_r(t_sort *sort);
void			rrta_a(t_sort *sort);
void			rrta_b(t_sort *sort);
void			rrta_r(t_sort *sort);

#endif
