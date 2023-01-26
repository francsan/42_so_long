/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 00:12:58 by francsan          #+#    #+#             */
/*   Updated: 2023/01/26 21:42:29 by francisco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_possible(t_map *map, int keycode)
{
	if (keycode == KEY_W)
		if (map->grid[map->player_y - 1][map->player_x] != '1')
			return (1);
	if (keycode == KEY_A)
		if (map->grid[map->player_y][map->player_x - 1] != '1')
			return (1);
	if (keycode == KEY_S)
		if (map->grid[map->player_y + 1][map->player_x] != '1')
			return (1);
	if (keycode == KEY_D)
		if (map->grid[map->player_y][map->player_x + 1] != '1')
			return (1);
	return (0);
}

void	put_player_image(t_map *map, t_img *img, int keycode, void **player)
{
	if (keycode == KEY_W)
		mlx_put_image_to_window(img->mlx, img->win, player[0], map->player_x * 64, map->player_y * 64);
	if (keycode == KEY_A)
		mlx_put_image_to_window(img->mlx, img->win, player[1], map->player_x * 64, map->player_y * 64);
	if (keycode == KEY_S)
		mlx_put_image_to_window(img->mlx, img->win, player[2], map->player_x * 64, map->player_y * 64);
	if (keycode == KEY_D)
		mlx_put_image_to_window(img->mlx, img->win, player[3], map->player_x * 64, map->player_y * 64);
	else
		mlx_put_image_to_window(img->mlx, img->win, player[2], map->player_x * 64, map->player_y * 64);
}

int	keyhook(int keycode, t_map *map, t_img *img, void **player)
{
	if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	if (keycode == KEY_W && map->player_y - 1 >= 0 && \
	check_possible(map, KEY_W))
		map->player_y--;
	if (keycode == KEY_A && map->player_x - 1 >= 0 && \
	check_possible(map, KEY_A))
		map->player_x--;
	if (keycode == KEY_S && map->player_y + 1 <= map->max_y && \
	check_possible(map, KEY_S))
		map->player_y++;
	if (keycode == KEY_D && map->player_x + 1 <= map->max_x && \
	check_possible(map, KEY_D))
		map->player_x--;
	put_player_image(map, img, keycode, player);
	return (0);
}

int	close_game(t_img *img)
{
	(void) img;
	exit(EXIT_SUCCESS);
	return (0);
}

void	**get_fence(t_img *img)
{
	void	**fence;
	int		w;
	int		h;

	fence = ft_calloc(17, sizeof(void *));
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

void	put_map_image_basic(t_map *map, t_img *img, void **fence, void *grass)
{
	int	i;

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
				mlx_put_image_to_window(img->mlx, img->win, fence[i - 1], \
				(img->x * 64), (img->y * 64));
			}
			else if (img->c == '0' || img->c == 'P'
				|| img->c == 'C' || img->c == 'E')
				mlx_put_image_to_window(img->mlx, img->win, grass, \
				(img->x * 64), (img->y * 64));
		}
	}
}

void	**get_player(t_img *img)
{
	void	**player;
	int		w;
	int		h;

	player = ft_calloc(4, sizeof(void *));
	player[0] = mlx_xpm_file_to_image(img->mlx, "imgs/player_up.xpm", &w, &h);
	player[1] = mlx_xpm_file_to_image(img->mlx, "imgs/player_right.xpm", &w, &h);
	player[2] = mlx_xpm_file_to_image(img->mlx, "imgs/player_down.xpm", &w, &h);
	player[3] = mlx_xpm_file_to_image(img->mlx, "imgs/player_left.xpm", &w, &h);
	return (player);
}

void	build_map(t_map *map)
{
	t_img	*img;
	void	**fence;
	void	**player;
	void	*grass;

	img = ft_calloc(1, sizeof(t_img));
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, (map->max_x + 1) * 64, \
	(map->max_y + 1) * 64, "so_long");
	fence = get_fence(img);
	player = get_player(img);
	grass = mlx_xpm_file_to_image(img->mlx, "imgs/0.xpm", &img->w, &img->h);
	put_map_image_basic(map, img, fence, grass);
	put_player_image(map, img, 0, player);
	mlx_key_hook(img->win, keyhook, "&map, &img, player");
	mlx_hook(img->win, 17, 0L, close_game, &img);
	mlx_loop(img->mlx);
}
