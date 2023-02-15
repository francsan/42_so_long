/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francsan <francsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 00:12:58 by francsan          #+#    #+#             */
/*   Updated: 2023/02/15 17:14:41 by francsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_possible(t_game *game, int keycode)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (keycode == KEY_W)
		if (game->grid[y - 1][x] != '1')
			return (1);
	if (keycode == KEY_A)
		if (game->grid[y][x - 1] != '1')
			return (1);
	if (keycode == KEY_S)
		if (game->grid[y + 1][x] != '1')
			return (1);
	if (keycode == KEY_D)
		if (game->grid[y][x + 1] != '1')
			return (1);
	return (0);
}

void	key_hook_check(int keycode, t_game *game)
{
	if (keycode == KEY_W && game->player_y - 1 >= 0 && \
	check_possible(game, KEY_W) == 1)
	{
		game->player_y -= 1;
		game->moves++;
	}
	else if (keycode == KEY_A && game->player_x - 1 >= 0 && \
	check_possible(game, KEY_A) == 1)
	{
		game->player_x -= 1;
		game->moves++;
	}
	else if (keycode == KEY_S && game->player_y + 1 <= game->max_y && \
	check_possible(game, KEY_S) == 1)
	{
		game->player_y += 1;
		game->moves++;
	}
	else if (keycode == KEY_D && game->player_x + 1 <= game->max_x && \
	check_possible(game, KEY_D) == 1)
	{
		game->player_x += 1;
		game->moves++;
	}
}

int	key_hook(int keycode, t_game **game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	key_hook_check(keycode, *game);
	put_map_image(*game);
	put_player_image(*game, keycode);
	if ((*game)->grid[(*game)->player_y][(*game)->player_x] == 'E'
		&& (*game)->collectibles == 0)
		close_game(game);
	return (0);
}

int	close_game(t_game **game)
{
	int	i;

	i = 4;
	while (--i >= 0)
		mlx_destroy_image((*game)->mlx, (*game)->terrain[i]);
	free((*game)->terrain);
	i = 16;
	while (--i >= 0)
		mlx_destroy_image((*game)->mlx, (*game)->fence[i]);
	free((*game)->fence);
	i = 4;
	while (--i >= 0)
		mlx_destroy_image((*game)->mlx, (*game)->player[i]);
	free((*game)->player);
	mlx_destroy_window((*game)->mlx, (*game)->win);
	ft_strarr_free((*game)->grid);
	free(*game);
	exit(EXIT_SUCCESS);
	return (0);
}

void	build_map(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, (game->max_x + 1) * 64, \
	(game->max_y + 1) * 64, "so_long");
	get_terrain(game);
	get_fence(game);
	get_player(game);
	put_map_image(game);
	mlx_key_hook(game->win, key_hook, &game);
	mlx_hook(game->win, 17, 0L, close_game, &game);
	mlx_loop(game->mlx);
}
