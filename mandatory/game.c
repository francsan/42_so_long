/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francsan <francsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 00:12:58 by francsan          #+#    #+#             */
/*   Updated: 2023/01/24 00:34:26 by francsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	keyhook(int keycode, t_img *img)
{
	(void) img;
	if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	return (0);
}

int	close_game(t_img *img)
{
	(void) img;
	exit(EXIT_SUCCESS);
	return (0);
}

void	build_map(t_map *map)
{
	t_img	*img;

	img = ft_calloc(1, sizeof(t_img));
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, map->max_x * 64, map->max_y * 64, "so_long");

	mlx_key_hook(img->win, keyhook, &img);
	mlx_hook(img->win, 17, 0L, close_game, &img);

	mlx_loop(img->mlx);
}
