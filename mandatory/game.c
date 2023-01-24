/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 00:12:58 by francsan          #+#    #+#             */
/*   Updated: 2023/01/24 05:22:31 by francisco        ###   ########.fr       */
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
// MASSIVE cleanup needed | just testing for image, need to make more functions and organize everything
void	build_map(t_map *map)
{
	t_img	*img;
	int		width;
	int		height;
	int		x;
	int		y;

	img = ft_calloc(1, sizeof(t_img));
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, (map->max_x + 1) * 64, (map->max_y + 1) * 64, "so_long");

	img->floor = mlx_xpm_file_to_image(img->mlx, "imgs/grass.xpm", &width, &height);
	img->mid_horizontal = mlx_xpm_file_to_image(img->mlx, "imgs/mid_horizontal.xpm", &width, &height);
	img->mid_vertical = mlx_xpm_file_to_image(img->mlx, "imgs/mid_vertical.xpm", &width, &height);
	img->top_left = mlx_xpm_file_to_image(img->mlx, "imgs/corner_top_left.xpm", &width, &height);
	img->top_right = mlx_xpm_file_to_image(img->mlx, "imgs/corner_top_right.xpm", &width, &height);
	img->bottom_left = mlx_xpm_file_to_image(img->mlx, "imgs/corner_bottom_left.xpm", &width, &height);
	img->bottom_right = mlx_xpm_file_to_image(img->mlx, "imgs/corner_bottom_right.xpm", &width, &height);
	y = -1;
	while (map->grid[++y])
	{
		x = -1;
		while (map->grid[y][++x])
		{
			if (map->grid[y][x] == '1' && y == 0 && x == 0)
				mlx_put_image_to_window(img->mlx, img->win, img->top_left, (x * 64), (y * 64));
			else if (map->grid[y][x] == '1' && y == 0 && x == map->max_x)
				mlx_put_image_to_window(img->mlx, img->win, img->top_right, (x * 64), (y * 64));
			else if (map->grid[y][x] == '1' && y == map->max_y && x == 0)
				mlx_put_image_to_window(img->mlx, img->win, img->bottom_left, (x * 64), (y * 64));
			else if (map->grid[y][x] == '1' && y == map->max_y && x == map->max_x)
				mlx_put_image_to_window(img->mlx, img->win, img->bottom_right, (x * 64), (y * 64));
			else if (map->grid[y][x] == '1' && ((x == 0 || x == map->max_x) && (y != 0 && y != map->max_y)))
				mlx_put_image_to_window(img->mlx, img->win, img->mid_vertical, (x * 64), (y * 64));
			else if (map->grid[y][x] == '1')
				mlx_put_image_to_window(img->mlx, img->win, img->mid_horizontal, (x * 64), (y * 64));
			else if (map->grid[y][x] == '0' || map->grid[y][x] == 'P' || map->grid[y][x] == 'C' || map->grid[y][x] == 'E')
				mlx_put_image_to_window(img->mlx, img->win, img->floor, (x * 64), (y * 64));
		}
	}

	mlx_key_hook(img->win, keyhook, &img);
	mlx_hook(img->win, 17, 0L, close_game, &img);

	mlx_loop(img->mlx);
}
