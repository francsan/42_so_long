/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:50:56 by francisco         #+#    #+#             */
/*   Updated: 2023/01/10 12:49:06 by francisco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// for malloc and free
# include <stdlib.h>
// for minilibx
# include <mlx.h>
// foir get_next_line
# include "../functions/get_next_line/get_next_line.h"
// for testing
# include <stdio.h>

/* keycodes */

# define KEY_ESC 53

/* structs */

typedef struct t_pointers {
	void	*mlx;
	void	*window;
	void	*image;
}	t_pointers;

/* mandatory */

// window.c
int		close1(int keycode, t_pointers *p);
int		close2(t_pointers *p);

/* functions */

// ft_calloc.c
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);

#endif