/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francsan <francsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:41:46 by francsan          #+#    #+#             */
/*   Updated: 2023/02/15 17:17:13 by francsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_terrain(t_game *game)
{
	int	w;
	int	h;

	if (!game->terrain)
	{
		game->terrain = ft_calloc(4, sizeof(void *));
		if (!game->terrain)
			error_msg(ERR_MEM);
		game->terrain[0] = mlx_xpm_file_to_image(game->mlx, "imgs/0.xpm", &w, &h);
		game->terrain[1] = mlx_xpm_file_to_image(game->mlx, "imgs/17.xpm", &w, &h);
		game->terrain[2] = mlx_xpm_file_to_image(game->mlx, "imgs/18.xpm", &w, &h);
		game->terrain[3] = mlx_xpm_file_to_image(game->mlx, "imgs/19.xpm", &w, &h);
	}
}

void	get_fence(t_game *game)
{
	int	w;
	int	h;

	if (!game->fence)
	{
		game->fence = ft_calloc(17, sizeof(void *));
		if (!game->fence)
			error_msg(ERR_MEM);
		game->fence[0] = mlx_xpm_file_to_image(game->mlx, "imgs/1.xpm", &w, &h);
		game->fence[1] = mlx_xpm_file_to_image(game->mlx, "imgs/2.xpm", &w, &h);
		game->fence[2] = mlx_xpm_file_to_image(game->mlx, "imgs/3.xpm", &w, &h);
		game->fence[3] = mlx_xpm_file_to_image(game->mlx, "imgs/4.xpm", &w, &h);
		game->fence[4] = mlx_xpm_file_to_image(game->mlx, "imgs/5.xpm", &w, &h);
		game->fence[5] = mlx_xpm_file_to_image(game->mlx, "imgs/6.xpm", &w, &h);
		game->fence[6] = mlx_xpm_file_to_image(game->mlx, "imgs/7.xpm", &w, &h);
		game->fence[7] = mlx_xpm_file_to_image(game->mlx, "imgs/8.xpm", &w, &h);
		game->fence[8] = mlx_xpm_file_to_image(game->mlx, "imgs/9.xpm", &w, &h);
		game->fence[9] = mlx_xpm_file_to_image(game->mlx, "imgs/10.xpm", &w, &h);
		game->fence[10] = mlx_xpm_file_to_image(game->mlx, "imgs/11.xpm", &w, &h);
		game->fence[11] = mlx_xpm_file_to_image(game->mlx, "imgs/12.xpm", &w, &h);
		game->fence[12] = mlx_xpm_file_to_image(game->mlx, "imgs/13.xpm", &w, &h);
		game->fence[13] = mlx_xpm_file_to_image(game->mlx, "imgs/14.xpm", &w, &h);
		game->fence[14] = mlx_xpm_file_to_image(game->mlx, "imgs/15.xpm", &w, &h);
		game->fence[15] = mlx_xpm_file_to_image(game->mlx, "imgs/16.xpm", &w, &h);
	}
}

void	get_player(t_game *game)
{
	int	w;
	int	h;

	if (!game->player)
	{
		game->player = ft_calloc(4, sizeof(void *));
		if (!game->player)
			error_msg(ERR_MEM);
		game->player[0] = mlx_xpm_file_to_image(game->mlx, \
		"imgs/player_up.xpm", &w, &h);
		game->player[1] = mlx_xpm_file_to_image(game->mlx, \
		"imgs/player_right.xpm", &w, &h);
		game->player[2] = mlx_xpm_file_to_image(game->mlx, \
		"imgs/player_down.xpm", &w, &h);
		game->player[3] = mlx_xpm_file_to_image(game->mlx, \
		"imgs/player_left.xpm", &w, &h);
	}
}
