/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francsan <francsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:20:52 by francisco         #+#    #+#             */
/*   Updated: 2023/02/15 19:31:58 by francsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	open_map_file(char *file)
{
	int	i;
	int	fd;

	i = -1;
	while (file[++i])
		if (file[i] == '.')
			break ;
	if (ft_strncmp(&file[i], ".ber\0", 5) == 0)
	{
		fd = open(file, __O_DIRECTORY);
		if (fd != -1)
		{
			close(fd);
			error_msg(ERR_FILE2);
		}
		fd = open(file, O_RDONLY);
		if (fd < 0)
		{
			close(fd);
			error_msg(ERR_FILE1);
		}
		return (fd);
	}
	error_msg(ERR_FILE1);
	return (-1);
}

void	read_map_lines(char **read, char **temp, int fd)
{
	char	*join;

	join = ft_strjoin(*temp, *read);
	free(*temp);
	*temp = ft_strdup(join);
	free(join);
	free(*read);
	*read = get_next_line(fd);
}

void	read_map(t_game *game, int fd)
{
	char	*read;
	char	*temp;
	int		i;

	read = get_next_line(fd);
	temp = ft_strdup("");
	game->max_y = -1;
	while (read != NULL)
	{
		game->max_y++;
		read_map_lines(&read, &temp, fd);
	}
	i = -1;
	while (temp[++i])
	{
		if (temp[i] == '\n' && temp[i + 1] == '\n')
		{
			free(temp);
			free(game);
			error_msg(ERR_BOUND);
		}
	}
	game->grid = ft_split(temp, '\n');
	game->max_x = ft_strlen(game->grid[0]) - 1;
	free(temp);
}

static void	check_map_1(t_game *game, t_d1 *d)
{
	while (game->grid[d->y])
	{
		check_map_chars(game, d);
		d->y++;
	}
	if (d->exit != 1 || d->player != 1)
	{
		free(d);
		error_msg_free(&game, ERR_SE);
	}
	if (d->collect < 1)
	{
		free(d);
		error_msg_free(&game, ERR_COL);
	}
	game->collectibles = d->collect;
	if (!check_map_valid(game, d))
	{
		free(d);
		error_msg_free(&game, ERR_PATH);
	}
	free(d);
}

void	check_map(t_game *game)
{
	t_d1	*d;

	d = ft_calloc(1, sizeof(t_d1));
	if (!d)
		error_msg_free(&game, ERR_MEM);
	d->y = 0;
	d->exit = 0;
	d->player = 0;
	d->collect = 0;
	check_map_1(game, d);
}
