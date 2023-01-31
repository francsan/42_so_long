/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francsan <francsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:27:47 by francisco         #+#    #+#             */
/*   Updated: 2023/01/31 16:12:39 by francsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_game	*game;

	if (argc != 2)
		error_msg(ERR_FILE);
	fd = open(argv[1], O_RDONLY);
	game = ft_calloc(1, sizeof(t_game));
	read_map(game, fd);
	close(fd);
	check_map(game);
	game->moves = 0;
	build_map(game);
	ft_strarr_free(game->grid);
	free(game);
	return (0);
}
