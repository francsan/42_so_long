/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francsan <francsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 00:12:58 by francsan          #+#    #+#             */
/*   Updated: 2023/01/24 23:00:43 by francsan         ###   ########.fr       */
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

int	check_around_1(t_map *map, int x, int y)
{
	char	up;
	char	down;
	char	right;
	char	left;

	up = 0;
	down = 0;
	right = 0;
	left = 0;
	if (y - 1 >= 0)
		up = map->grid[y - 1][x];
	if (y + 1 <= map->max_y)
		down = map->grid[y + 1][x];
	if (x + 1 <= map->max_x)
		right = map->grid[y][x + 1];
	if (x - 1 >= 0)
		left = map->grid[y][x - 1];
	if (up == '1') // Bottom Vertical
		return (2);
	else if (right == '1') // Left Horizontal
		return (3);
	else if (down == '1') // Top Vertical
		return (4);
	else if (left == '1') // Right Horizontal
		return (5);
	return (0);
}

int	check_around_2(t_map *map, int x, int y)
{
	char	up;
	char	down;
	char	right;
	char	left;

	up = 0;
	down = 0;
	right = 0;
	left = 0;
	if (y - 1 >= 0)
		up = map->grid[y - 1][x];
	if (y + 1 <= map->max_y)
		down = map->grid[y + 1][x];
	if (x + 1 <= map->max_x)
		right = map->grid[y][x + 1];
	if (x - 1 >= 0)
		left = map->grid[y][x - 1];
	if (left == '1' && right == '1') // Mid Horizontal
		return (6);
	else if (up == '1' && down == '1') // Mid Vertical
		return (7);
	else if (down == '1' && right == '1') // Corner Top Left
		return (8);
	else if (down == '1' && left == '1') // Corner Top Right
		return (9);
	else if (up == '1' && right == '1') // Corner Bottom Left
		return (10);
	else if (up == '1' && left == '1') // Corner Bottom Right
		return (11);
	return (0);
}

int	check_around_3(t_map *map, int x, int y)
{
	char	up;
	char	down;
	char	right;
	char	left;

	up = 0;
	down = 0;
	right = 0;
	left = 0;
	if (y - 1 >= 0)
		up = map->grid[y - 1][x];
	if (y + 1 <= map->max_y)
		down = map->grid[y + 1][x];
	if (x + 1 <= map->max_x)
		right = map->grid[y][x + 1];
	if (x - 1 >= 0)
		left = map->grid[y][x - 1];
	if (left == '1' && right == '1' && down == '1') // Mid Horizontal + Bottom
		return (12);
	if (left == '1' && right == '1' && up == '1') // Mid Horizontal + Top
		return (13);
	if (up == '1' && down == '1' && right == '1') // Mid Vertical + Right
		return (14);
	if (up == '1' && down == '1' && left == '1') // Mid Vertical + Left
		return (15);
	return (0);
}

int	check_arround(t_map *map, int x, int y)
{
	int		i;

	i = 0;
	if (y - 1 >= 0 && map->grid[y - 1][x] == '1')
		i++;
	if (x + 1 <= map->max_x && map->grid[y][x + 1] == '1')
		i++;
	if (y + 1 <= map->max_y && map->grid[y + 1][x] == '1')
		i++;
	if (x - 1 >= 0 && map->grid[y][x - 1] == '1')
		i++;
	if (i == 0) // Single
		return (1);
	if (i == 4) // Mid + All
		return (16);
	if (i == 1)
		return (check_around_1(map, x, y));
	if (i == 2)
		return (check_around_2(map, x, y));
	if (i == 3)
		return (check_around_3(map, x, y));
	return (0);
}

void	**get_fence(t_img *img)
{
	void	**fence;
	int		w;
	int		h;

	fence = ft_calloc(17, sizeof(void*));
	fence[0] = mlx_xpm_file_to_image(img->mlx, "imgs/1.xpm", &w, &h);
	fence[1] = mlx_xpm_file_to_image(img->mlx, "imgs/2.xpm", &w, &h);
	fence[2] = mlx_xpm_file_to_image(img->mlx, "imgs/3.xpm", &w, &h);
	fence[3] = mlx_xpm_file_to_image(img->mlx, "imgs/4.xpm", &w, &h);
	fence[4] = mlx_xpm_file_to_image(img->mlx, "imgs/5.xpm", &w, &h);
	fence[5] = mlx_xpm_file_to_image(img->mlx, "imgs/6.xpm", &w, &h);
	fence[6] = mlx_xpm_file_to_image(img->mlx, "imgs/7.xpm", &w, &h);
	fence[7] = mlx_xpm_file_to_image(img->mlx, "imgs/8.xpm", &w, &h);
	fence[8] = mlx_xpm_file_to_image(img->mlx, "imgs/9.xpm", &w, &h);
	fence[9] = mlx_xpm_file_to_image(img->mlx, "imgs/10.xpm", &w, &h);
	fence[10] = mlx_xpm_file_to_image(img->mlx, "imgs/11.xpm", &w, &h);
	fence[11] = mlx_xpm_file_to_image(img->mlx, "imgs/12.xpm", &w, &h);
	fence[12] = mlx_xpm_file_to_image(img->mlx, "imgs/13.xpm", &w, &h);
	fence[13] = mlx_xpm_file_to_image(img->mlx, "imgs/14.xpm", &w, &h);
	fence[14] = mlx_xpm_file_to_image(img->mlx, "imgs/15.xpm", &w, &h);
	fence[15] = mlx_xpm_file_to_image(img->mlx, "imgs/16.xpm", &w, &h);
	return (fence);
}

void	build_map(t_map *map)
{
	t_img	*img;
	void	**fence;
	void	*grass;
	int		i;
	int		w;
	int		h;

	img = ft_calloc(1, sizeof(t_img));
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, (map->max_x + 1) * 64, (map->max_y + 1) * 64, "so_long");
	fence = get_fence(img);
	grass = mlx_xpm_file_to_image(img->mlx, "imgs/0.xpm", &w, &h);
	img->y = -1;
	while (map->grid[++img->y])
	{
		img->x = -1;
		while (map->grid[img->y][++img->x])
		{
			img->c = map->grid[img->y][img->x];
			if (img->c == '1')
			{
				i = check_arround(map, img->x, img->y);
				mlx_put_image_to_window(img->mlx, img->win, fence[i - 1], (img->x * 64), (img->y * 64));
			}
			else if (img->c == '0' || img->c == 'P' || img->c == 'C' || img->c == 'E')
				mlx_put_image_to_window(img->mlx, img->win, grass, (img->x * 64), (img->y * 64));
		}
	}
	mlx_key_hook(img->win, keyhook, &img);
	mlx_hook(img->win, 17, 0L, close_game, &img);
	mlx_loop(img->mlx);
}
