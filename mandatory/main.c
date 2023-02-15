/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francsan <francsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:27:47 by francisco         #+#    #+#             */
/*   Updated: 2023/02/15 17:28:08 by francsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_game	*game;

	if (argc != 2)
		error_msg(ERR_FILE);
	fd = open_map_file(argv[1]);
	game = ft_calloc(1, sizeof(t_game));
	read_map(game, fd);
	close(fd);
	check_map(game);
	game->moves = 0;
	build_map(game);
	return (0);
}
