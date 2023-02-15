/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francsan <francsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 00:36:07 by francsan          #+#    #+#             */
/*   Updated: 2023/02/15 16:20:53 by francsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	selector_1(t_game *game, int x, int y)
{
	if (game->c == '1')
	{
		game->i = check_arround(game, x, y);
		mlx_put_image_to_window(game->mlx, game->win, \
		game->fence[game->i - 1], (x * 64), (y * 64));
	}
	else if (game->c == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->terrain[0], \
		(x * 64), (y * 64));
	else if (game->c == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->terrain[1], \
		(x * 64), (y * 64));
		if (game->player_y == y && game->player_x == x)
		{
			game->grid[y][x] = '0';
			game->collectibles--;
			put_map_image(game);
		}
	}
}

void	selector_2(t_game *game, int x, int y)
{
	if (game->c == 'P')
	{
		put_player_image(game, 42);
		game->grid[y][x] = '0';
	}
	else if (game->c == 'E')
	{
		if (game->collectibles > 0)
			mlx_put_image_to_window(game->mlx, game->win, game->terrain[2], \
			(x * 64), (y * 64));
		else if (game->collectibles == 0)
			mlx_put_image_to_window(game->mlx, game->win, game->terrain[3], \
			(x * 64), (y * 64));
	}
}

void	put_move_counter(t_game *game)
{
	char	*num;
	char	*str;
	int		x;
	int		y;

	y = 4;
	while (y <= 20)
	{
		x = 4;
		while (x <= 84)
		{
			mlx_pixel_put(game->mlx, game->win, x, y, 0x00000000);
			x++;
		}
		y++;
	}
	num = ft_itoa(game->moves);
	str = ft_strjoin("Moves = ", num);
	free(num);
	mlx_string_put(game->mlx, game->win, 16, 16, 0x99999999, str);
	free(str);
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
		{
			game->c = game->grid[y][x];
			selector_1(game, x, y);
			selector_2(game, x, y);
		}
	}
	put_move_counter(game);
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
