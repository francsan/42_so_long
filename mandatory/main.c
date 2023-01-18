/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:27:47 by francisco         #+#    #+#             */
/*   Updated: 2023/01/14 18:45:20 by francisco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_map	*map;

	(void) argc;
	fd = open(argv[1], O_RDONLY);
	map = ft_calloc(1, sizeof(t_map));
	read_map(map, fd);
	close(fd);
	check_map(map);
	free(map);
}
