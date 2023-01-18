/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:20:52 by francisco         #+#    #+#             */
/*   Updated: 2023/01/18 01:00:19 by francisco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	read_map(t_map *map, int fd)
{
	char	*read;
	char	*temp;

	read = get_next_line(fd);
	temp = ft_strdup("");
	map->max_y = -1;
	while (read != NULL)
	{
		map->max_y++;
		ft_strlcat(temp, read, (ft_strlen(temp) + ft_strlen(read)) + 1);
		free(read);
		read = get_next_line(fd);
	}
	map->grid = ft_split(temp, '\n');
	map->max_x = ft_strlen(map->grid[0]) - 1;
	free(temp);
	free(read);
}

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

int	search_map(int x, int y, char **grid)
{
	char	up;
	char	right;
	char	down;
	char	left;

	up = grid[x][y - 1];
	right = grid[x + 1][y];
	down = grid[x][y + 1];
	left = grid[x - 1][y];
	if (grid[x][y] == 'E')
		return (1);
	if (grid[x][y] == '0' || grid[x][y] == 'P')
		grid[x][y] = 'X';
	if (up == '0' || up == 'C' || up == 'E')
		if (search_map(x, y - 1, grid) == 1)
			return (1);
	if (right == '0' || right == 'C' || right == 'E')
		if (search_map(x + 1, y, grid) == 1)
			return (1);
	if (down == '0' || down == 'C' || down == 'E')
		if (search_map(x, y + 1, grid) == 1)
			return (1);
	if (left == '0' || left == 'C' || left == 'E')
		if (search_map(x - 1, y, grid) == 1)
			return (1);
	return (0);
}

int	check_map_valid(t_map *map)
{
	char	**grid;
	int		i;

	i = -1;
	grid = ft_calloc(1, sizeof(map->grid));
	while (map->grid[++i])
		grid[i] = ft_strdup(map->grid[i]);
	i = search_map(1, map->max_y - 1, grid);
	free(grid);
	if (i == 1)
		return (1);
	return (0);
}

void	check_map(t_map *map)
{
	t_d1	*d;

	d = ft_calloc(1, sizeof(t_d1));
	d->y = 0;
	d->exit = 0;
	d->player = 0;
	d->collect = 0;
	while (map->grid[d->y])
	{
		check_map_chars(map, d);
		d->y++;
	}
	if (d->exit != 1 || d->player != 1)
		error_msg(ERR_SE);
	if (d->collect < 1)
		error_msg(ERR_COL);
	if (!check_map_valid(map))
		error_msg(ERR_PATH);
	free(d);
}
