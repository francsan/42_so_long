/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:27:47 by francisco         #+#    #+#             */
/*   Updated: 2023/01/10 12:51:11 by francisco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(void)
{
	t_pointers	*p;

	// opening the window
	p = ft_calloc(sizeof(t_pointers), 1);
	p->mlx = mlx_init();
	p->window = mlx_new_window(p->mlx, 1280, 720, "so_long");

	// putting image
	int	img_width;
	int	img_height;
	p->image = mlx_xpm_file_to_image(p->mlx, "sample.xpm", &img_width, &img_height);
	mlx_put_image_to_window(p->mlx, p->window, p->image, 0, 0);
	mlx_put_image_to_window(p->mlx, p->window, p->image, 640, 360);
	mlx_put_image_to_window(p->mlx, p->window, p->image, 320, 180);
	
	// closing the window
	mlx_key_hook(p->window, close1, &p);
	mlx_hook(p->window, 17, 0L, close2, &p);

	mlx_loop(p->mlx);
	free(p);
}