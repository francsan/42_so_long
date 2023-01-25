/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francsan <francsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 23:23:56 by francsan          #+#    #+#             */
/*   Updated: 2023/01/25 00:47:54 by francsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	position_init(t_map *map, int x, int y)
{
	map->up = 0;
	map->down = 0;
	map->right = 0;
	map->left = 0;
	if (y - 1 >= 0)
		map->up = map->grid[y - 1][x];
	if (y + 1 <= map->max_y)
		map->down = map->grid[y + 1][x];
	if (x + 1 <= map->max_x)
		map->right = map->grid[y][x + 1];
	if (x - 1 >= 0)
		map->left = map->grid[y][x - 1];
}

int	check_around_1(t_map *map, int x, int y)
{
	position_init(map, x, y);
	if (map->up == '1')
		return (2);
	else if (map->right == '1')
		return (3);
	else if (map->down == '1')
		return (4);
	else if (map->left == '1')
		return (5);
	return (0);
}

int	check_around_2(t_map *map, int x, int y)
{
	position_init(map, x, y);
	if (map->left == '1' && map->right == '1')
		return (6);
	else if (map->up == '1' && map->down == '1')
		return (7);
	else if (map->down == '1' && map->right == '1')
		return (8);
	else if (map->down == '1' && map->left == '1')
		return (9);
	else if (map->up == '1' && map->right == '1')
		return (10);
	else if (map->up == '1' && map->left == '1')
		return (11);
	return (0);
}

int	check_around_3(t_map *map, int x, int y)
{
	position_init(map, x, y);
	if (map->left == '1' && map->right == '1' && map->down == '1')
		return (12);
	if (map->left == '1' && map->right == '1' && map->up == '1')
		return (13);
	if (map->up == '1' && map->down == '1' && map->right == '1')
		return (14);
	if (map->up == '1' && map->down == '1' && map->left == '1')
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
	if (i == 0)
		return (1);
	if (i == 4)
		return (16);
	if (i == 1)
		return (check_around_1(map, x, y));
	if (i == 2)
		return (check_around_2(map, x, y));
	if (i == 3)
		return (check_around_3(map, x, y));
	return (0);
}
