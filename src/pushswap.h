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
/*   Created/Updated: 2021/06/24 04:50:52  /  2021/06/24 04:50:56 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# define TW 190

# include <stdlib.h>
# include <unistd.h>

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

// Utils
void			exit_error(void);
int				not_integer(const char *str);
void			convert_and_index(int c, char *v[], int **d, unsigned int **i);
unsigned int	ft_strlen(const char *str);
void			init_sort(t_sort *sort);
void			ft_putint(int i);
int				ft_atoi(const char *str);

void			put_digit(int d, int w, unsigned int i, int c);
void			visual(t_sort *sort, const char *str);

// Sorting Algoritms
void			sw1_sort(t_sort *sort);
void			whl_sort(t_sort *sort, unsigned int m);

// Sorting Utils
unsigned int	push_mn(t_sort *sort, int d, unsigned int m);
void			push_min_max(t_sort *sort);
int				a_has_w(t_elem *ptr);
unsigned int	mdl(int i);
t_elem			*get_distances(t_sort *sort);
int				get_dist_i(t_elem *ptr, unsigned int l, unsigned int i);
unsigned int	get_smallest(t_elem *stack);
unsigned int	get_biggest(t_elem *stack);
t_elem			*ft_newelem(int nbr, unsigned int index);
void			exit_if_sorted(t_sort *sort);
t_elem			*create_list(int *d, unsigned int *i, int c, unsigned int *l);
void			clear_sort(t_sort *sort);
t_sort			*create_sort(t_sort *sort, int *d, unsigned int *i, int c);

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
