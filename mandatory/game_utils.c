/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francsan <francsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 23:23:56 by francsan          #+#    #+#             */
/*   Updated: 2023/01/26 23:54:32 by francsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	position_init(t_game *game, int x, int y)
{
	game->up = 0;
	game->down = 0;
	game->right = 0;
	game->left = 0;
	if (y - 1 >= 0)
		game->up = game->grid[y - 1][x];
	if (y + 1 <= game->max_y)
		game->down = game->grid[y + 1][x];
	if (x + 1 <= game->max_x)
		game->right = game->grid[y][x + 1];
	if (x - 1 >= 0)
		game->left = game->grid[y][x - 1];
}

int	check_around_1(t_game *game, int x, int y)
{
	position_init(game, x, y);
	if (game->up == '1')
		return (2);
	else if (game->right == '1')
		return (3);
	else if (game->down == '1')
		return (4);
	else if (game->left == '1')
		return (5);
	return (0);
}

int	check_around_2(t_game *game, int x, int y)
{
	position_init(game, x, y);
	if (game->left == '1' && game->right == '1')
		return (6);
	else if (game->up == '1' && game->down == '1')
		return (7);
	else if (game->down == '1' && game->right == '1')
		return (8);
	else if (game->down == '1' && game->left == '1')
		return (9);
	else if (game->up == '1' && game->right == '1')
		return (10);
	else if (game->up == '1' && game->left == '1')
		return (11);
	return (0);
}

int	check_around_3(t_game *game, int x, int y)
{
	position_init(game, x, y);
	if (game->left == '1' && game->right == '1' && game->down == '1')
		return (12);
	if (game->left == '1' && game->right == '1' && game->up == '1')
		return (13);
	if (game->up == '1' && game->down == '1' && game->right == '1')
		return (14);
	if (game->up == '1' && game->down == '1' && game->left == '1')
		return (15);
	return (0);
}

int	check_arround(t_game *game, int x, int y)
{
	int		i;

	i = 0;
	if (y - 1 >= 0 && game->grid[y - 1][x] == '1')
		i++;
	if (x + 1 <= game->max_x && game->grid[y][x + 1] == '1')
		i++;
	if (y + 1 <= game->max_y && game->grid[y + 1][x] == '1')
		i++;
	if (x - 1 >= 0 && game->grid[y][x - 1] == '1')
		i++;
	if (i == 0)
		return (1);
	if (i == 4)
		return (16);
	if (i == 1)
		return (check_around_1(game, x, y));
	if (i == 2)
		return (check_around_2(game, x, y));
	if (i == 3)
		return (check_around_3(game, x, y));
	return (0);
}
