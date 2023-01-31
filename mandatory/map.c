/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francsan <francsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:20:52 by francisco         #+#    #+#             */
/*   Updated: 2023/01/31 19:40:51 by francsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	read_map(t_game *game, int fd)
{
	char	*read;
	char	*temp1;
	char	*temp2;

	read = get_next_line(fd);
	temp2 = ft_strdup("");
	game->max_y = -1;
	while (read != NULL)
	{
		game->max_y++;
		temp1 = ft_strjoin(temp2, read);
		free(temp2);
		temp2 = ft_strdup(temp1);
		free(temp1);
		free(read);
		read = get_next_line(fd);
	}
	game->grid = ft_split(temp2, '\n');
	game->max_x = ft_strlen(game->grid[0]) - 1;
	free(temp2);
	free(read);
}

void	check_map(t_game *game)
{
	t_d1	*d;

	d = ft_calloc(1, sizeof(t_d1));
	if (!d)
		error_msg(ERR_MEM);
	d->y = 0;
	d->exit = 0;
	d->player = 0;
	d->collect = 0;
	while (game->grid[d->y])
	{
		check_map_chars(game, d);
		d->y++;
	}
	if (d->exit != 1 || d->player != 1)
		error_msg(ERR_SE);
	if (d->collect < 1)
		error_msg(ERR_COL);
	game->collectibles = d->collect;
	if (!check_map_valid(game, d))
		error_msg(ERR_PATH);
	free(d);
}
