/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francsan <francsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:27:47 by francisco         #+#    #+#             */
/*   Updated: 2023/01/23 23:41:14 by francsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_map	*map;

	if (argc != 2)
		error_msg(ERR_FILE);
	fd = open(argv[1], O_RDONLY);
	map = ft_calloc(1, sizeof(t_map));
	read_map(map, fd);
	close(fd);
	check_map(map);
	build_map(map);
	ft_strarr_free(map->grid);
	free(map);
	return (0);
}
