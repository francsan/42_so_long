/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francsan <francsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 00:36:07 by francsan          #+#    #+#             */
/*   Updated: 2023/01/27 01:34:52 by francsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_fence(t_game *game)
{
	int	w;
	int	h;

	game->fence = ft_calloc(17, sizeof(void *));
	game->grass = mlx_xpm_file_to_image(game->mlx, "imgs/0.xpm", &w, &h);
	game->fence[0] = mlx_xpm_file_to_image(game->mlx, "imgs/1.xpm", &w, &h);
	game->fence[1] = mlx_xpm_file_to_image(game->mlx, "imgs/2.xpm", &w, &h);
	game->fence[2] = mlx_xpm_file_to_image(game->mlx, "imgs/3.xpm", &w, &h);
	game->fence[3] = mlx_xpm_file_to_image(game->mlx, "imgs/4.xpm", &w, &h);
	game->fence[4] = mlx_xpm_file_to_image(game->mlx, "imgs/5.xpm", &w, &h);
	game->fence[5] = mlx_xpm_file_to_image(game->mlx, "imgs/6.xpm", &w, &h);
	game->fence[6] = mlx_xpm_file_to_image(game->mlx, "imgs/7.xpm", &w, &h);
	game->fence[7] = mlx_xpm_file_to_image(game->mlx, "imgs/8.xpm", &w, &h);
	game->fence[8] = mlx_xpm_file_to_image(game->mlx, "imgs/9.xpm", &w, &h);
	game->fence[9] = mlx_xpm_file_to_image(game->mlx, "imgs/10.xpm", &w, &h);
	game->fence[10] = mlx_xpm_file_to_image(game->mlx, "imgs/11.xpm", &w, &h);
	game->fence[11] = mlx_xpm_file_to_image(game->mlx, "imgs/12.xpm", &w, &h);
	game->fence[12] = mlx_xpm_file_to_image(game->mlx, "imgs/13.xpm", &w, &h);
	game->fence[13] = mlx_xpm_file_to_image(game->mlx, "imgs/14.xpm", &w, &h);
	game->fence[14] = mlx_xpm_file_to_image(game->mlx, "imgs/15.xpm", &w, &h);
	game->fence[15] = mlx_xpm_file_to_image(game->mlx, "imgs/16.xpm", &w, &h);
}

void	get_player(t_game *game)
{
	int	w;
	int	h;

	game->player = ft_calloc(4, sizeof(void *));
	game->player[0] = mlx_xpm_file_to_image(game->mlx, \
	"imgs/player_up.xpm", &w, &h);
	game->player[1] = mlx_xpm_file_to_image(game->mlx, \
	"imgs/player_right.xpm", &w, &h);
	game->player[2] = mlx_xpm_file_to_image(game->mlx, \
	"imgs/player_down.xpm", &w, &h);
	game->player[3] = mlx_xpm_file_to_image(game->mlx, \
	"imgs/player_left.xpm", &w, &h);
}

void	put_map_image_selector(t_game *game, int x, int y)
{
	game->c = game->grid[y][x];
	if (game->c == '1')
	{
		game->i = check_arround(game, x, y);
		mlx_put_image_to_window(game->mlx, game->win, \
		game->fence[game->i - 1], (x * 64), (y * 64));
	}
	if (game->c == '0' || game->c == 'C' || game->c == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->grass, \
		(x * 64), (y * 64));
	if (game->c == 'P')
	{
		put_player_image(game, 42);
		game->grid[y][x] = '0';
	}
}

void	put_map_image(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->grid[++y])
	{
		x = -1;
		while (game->grid[y][++x])
			put_map_image_selector(game, x, y);
	}
}

void	put_player_image(t_game *game, int keycode)
{
	if (keycode == KEY_W)
		mlx_put_image_to_window(game->mlx, game->win, game->player[0], \
		(game->player_x * 64), (game->player_y * 64));
	else if (keycode == KEY_A)
		mlx_put_image_to_window(game->mlx, game->win, game->player[3], \
		(game->player_x * 64), (game->player_y * 64));
	else if (keycode == KEY_S)
		mlx_put_image_to_window(game->mlx, game->win, game->player[2], \
		(game->player_x * 64), (game->player_y * 64));
	else if (keycode == KEY_D)
		mlx_put_image_to_window(game->mlx, game->win, game->player[1], \
		(game->player_x * 64), (game->player_y * 64));
	else
		mlx_put_image_to_window(game->mlx, game->win, game->player[2], \
		(game->player_x * 64), (game->player_y * 64));
}
