/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:58:33 by francisco         #+#    #+#             */
/*   Updated: 2023/01/26 03:43:45 by francisco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_map_chars(t_map *map, t_d1 *d)
{
	if ((int)ft_strlen(map->grid[d->y]) != map->max_x + 1)
		error_msg(ERR_BOUND);
	d->x = 0;
	while (map->grid[d->y][d->x])
	{
		d->c = map->grid[d->y][d->x];
		if (d->c != '0' && d->c != '1')
			if (d->c != 'C' && d->c != 'E' && d->c != 'P')
				error_msg(ERR_CHAR);
		if (d->c == 'C')
			d->collect++;
		if (d->c == 'E')
			d->exit++;
		if (d->c == 'P')
			d->player++;
		if (d->y == 0 || d->y == map->max_y)
			if (d->c != '1')
				error_msg(ERR_BOUND1);
		if (d->x == 0 || d->x == map->max_x)
			if (d->c != '1')
				error_msg(ERR_BOUND1);
		d->x++;
	}
}

int	search_map_coordinate(int x, int y, char **grid, t_d1 *d)
{
	int	i;
	int	j;

	if (grid[y][x] == '1' || grid[y][x] == 'X')
		return (0);
	if (grid[y][x] == 'E' && d->collect == 0)
		return (1);
	if (grid[y][x] == 'C')
	{
		d->collect--;
		i = -1;
		while (grid[++i])
		{
			j = -1;
			while (grid[i][++j])
			{
				if (grid[i][j] == 'X')
					grid[i][j] = '0';
			}
		}
	}
	if (grid[y][x] == 'P' || grid[y][x] == '0' || grid[y][x] == 'C')
		grid[y][x] = 'X';
	return (2);
}

int	search_map(int x, int y, char **grid, t_d1 *d)
{
	int	i;

	i = search_map_coordinate(x, y, grid, d);
	if (i < 2)
		return (i);
	if (search_map(x, y - 1, grid, d) == 1)
		return (1);
	if (search_map(x + 1, y, grid, d) == 1)
		return (1);
	if (search_map(x, y + 1, grid, d) == 1)
		return (1);
	if (search_map(x - 1, y, grid, d) == 1)
		return (1);
	return (0);
}

int	check_map_valid(t_map *map, t_d1 *d)
{
	char	**grid;
	int		i;
	int		x;
	int		y;

	grid = ft_strarr_copy(map->grid);
	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x] && grid[y][x] != 'P')
			x++;
		if (grid[y][x] == 'P')
			break ;
		y++;
	}
	map->player_x = x;
	map->player_y = y;
	i = search_map(x, y, grid, d);
	ft_strarr_free(grid);
	if (i == 1)
		return (1);
	return (0);
}
