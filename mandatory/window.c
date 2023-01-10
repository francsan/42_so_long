/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:33:02 by francisco         #+#    #+#             */
/*   Updated: 2023/01/10 12:49:01 by francisco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close1(int keycode, t_pointers *p)
{
	(void) p;
	if (keycode == KEY_ESC)
		exit (EXIT_SUCCESS);
	return (0);
}

int	close2(t_pointers *p)
{
	(void) p;
	exit(EXIT_SUCCESS);
	return (0);
}