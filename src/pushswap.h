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
/*   Created/Updated: 2021/06/04 21:46:08  /  2021/06/04 21:46:08 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>

#include <stdio.h>
#include <time.h>

#define TW 150

// includes:
//     unistd: read() write()
//     stdlib: malloc() free()
//     exit()

//	Struct Element
//	
//	d - (Digit) integer
//	i - (Index) index of number
//	n - (Next) next element

typedef struct s_elem
{
	int					d;
	unsigned int		i;
	struct s_elem		*n;
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
	unsigned int	l;
	unsigned int	la;
	unsigned int	lb;
	int				sf;
	int				ss;
	int				fr;
	int				sr;
	unsigned int	op[3];
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
int				ft_atoi(const char *str);
void			ft_putint(int i);
void			init_sort(t_sort *sort);

void			put_digit(int d, int w, unsigned int i, int c);
void			visual(t_sort *sort, const char *str);

// Sorting Algoritms

void	sw1_sort(t_sort *sort);
void	sw2_sort(t_sort *sort);
void	p2b_sort(t_sort *sort);

int a_not_sorted(t_sort *sort);
unsigned int	index_location(t_sort *sort, unsigned int index);
unsigned int	index_distance(t_sort *sort, unsigned int index);

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
