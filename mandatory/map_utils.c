/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francsan <francsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:58:33 by francisco         #+#    #+#             */
/*   Updated: 2023/02/15 19:35:52 by francsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	check_map_chars_1(t_game *game, t_d1 *d)
{
	if (d->c == 'C')
		d->collect++;
	if (d->c == 'E')
		d->exit++;
	if (d->c == 'P')
		d->player++;
	if (d->y == 0 || d->y == game->max_y)
	{
		if (d->c != '1')
		{
			free(d);
			error_msg_free(&game, ERR_BOUND1);
		}
	}
	if (d->x == 0 || d->x == game->max_x)
	{
		if (d->c != '1')
		{
			free(d);
			error_msg_free(&game, ERR_BOUND1);
		}
	}
}

void	check_map_chars(t_game *game, t_d1 *d)
{
	if ((int)ft_strlen(game->grid[d->y]) != game->max_x + 1)
	{
		free(d);
		error_msg_free(&game, ERR_BOUND);
	}
	d->x = 0;
	while (game->grid[d->y][d->x])
	{
		d->c = game->grid[d->y][d->x];
		if (d->c != '0' && d->c != '1')
		{
			if (d->c != 'C' && d->c != 'E' && d->c != 'P')
			{
				free(d);
				error_msg_free(&game, ERR_CHAR);
			}
		}
		check_map_chars_1(game, d);
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

int	check_map_valid(t_game *game, t_d1 *d)
{
	char	**grid;
	int		i;
	int		x;
	int		y;

	grid = ft_strarr_copy(game->grid);
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
	game->player_x = x;
	game->player_y = y;
	i = search_map(x, y, grid, d);
	ft_strarr_free(grid);
	if (i == 1)
		return (1);
	return (0);
}
