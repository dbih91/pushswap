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
/*   checker.h                                cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/06/24 03:34:34  /  2021/06/24 03:34:36 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>

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

// Sueta
t_elem			*create_list(int *d, unsigned int *i, int c, unsigned int *l);
void			clear_sort(t_sort *sort);
t_sort			*create_sort(t_sort *sort, int *d, unsigned int *i, int c);
int				has_duplicate(int *d, int size);
int				not_integer(const char *str);
int				get_smallest_index(int **d, int *s, int c);
void			index_array(int **d, unsigned int **i, int c);
void			convert_and_index(int c, char *v[], int **d, unsigned int **i);
int				ft_atoi(const char *str);
void			ft_putchar(const char c);
void			ft_putint(int i);
unsigned int	ft_strlen(const char *str);
unsigned int	get_smallest(t_elem *stack);
unsigned int	get_biggest(t_elem *stack);
t_elem			*ft_newelem(int nbr, unsigned int index);
void			exit_error(void);
void			ok_if_sorted(t_sort *sort);

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