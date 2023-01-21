/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:20:52 by francisco         #+#    #+#             */
/*   Updated: 2023/01/21 16:02:14 by francisco        ###   ########.fr       */
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
	if (!check_map_valid(map, d))
		error_msg(ERR_PATH);
	free(d);
}
