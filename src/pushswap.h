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
/*   Created/Updated: 2021/05/16 18:27:22  /  2021/05/16 18:27:36 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>

// includes:
//     unistd: read() write()
//     stdlib: malloc() free()
//     exit()         

typedef struct s_elem
{
	int					i;
	struct s_elem		*n;
}				t_elem;

typedef struct s_sort
{
	t_elem *a;
	t_elem *b;
}				t_sort;

unsigned int			ft_strlen(const char *str);
int						ft_atoi(const char *str);
void					ft_putint(int i);

#endif
