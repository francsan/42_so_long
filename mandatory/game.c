/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francsan <francsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 00:12:58 by francsan          #+#    #+#             */
/*   Updated: 2023/01/25 01:02:40 by francsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	keyhook(int keycode, t_img *img)
{
	(void) img;
	if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	return (0);
}

int	close_game(t_img *img)
{
	(void) img;
	exit(EXIT_SUCCESS);
	return (0);
}

void	**get_fence(t_img *img)
{
	void	**fence;
	int		w;
	int		h;

	fence = ft_calloc(17, sizeof(void *));
	fence[0] = mlx_xpm_file_to_image(img->mlx, "imgs/1.xpm", &w, &h);
	fence[1] = mlx_xpm_file_to_image(img->mlx, "imgs/2.xpm", &w, &h);
	fence[2] = mlx_xpm_file_to_image(img->mlx, "imgs/3.xpm", &w, &h);
	fence[3] = mlx_xpm_file_to_image(img->mlx, "imgs/4.xpm", &w, &h);
	fence[4] = mlx_xpm_file_to_image(img->mlx, "imgs/5.xpm", &w, &h);
	fence[5] = mlx_xpm_file_to_image(img->mlx, "imgs/6.xpm", &w, &h);
	fence[6] = mlx_xpm_file_to_image(img->mlx, "imgs/7.xpm", &w, &h);
	fence[7] = mlx_xpm_file_to_image(img->mlx, "imgs/8.xpm", &w, &h);
	fence[8] = mlx_xpm_file_to_image(img->mlx, "imgs/9.xpm", &w, &h);
	fence[9] = mlx_xpm_file_to_image(img->mlx, "imgs/10.xpm", &w, &h);
	fence[10] = mlx_xpm_file_to_image(img->mlx, "imgs/11.xpm", &w, &h);
	fence[11] = mlx_xpm_file_to_image(img->mlx, "imgs/12.xpm", &w, &h);
	fence[12] = mlx_xpm_file_to_image(img->mlx, "imgs/13.xpm", &w, &h);
	fence[13] = mlx_xpm_file_to_image(img->mlx, "imgs/14.xpm", &w, &h);
	fence[14] = mlx_xpm_file_to_image(img->mlx, "imgs/15.xpm", &w, &h);
	fence[15] = mlx_xpm_file_to_image(img->mlx, "imgs/16.xpm", &w, &h);
	return (fence);
}

void	put_map_image_basic(t_map *map, t_img *img, void **fence, void *grass)
{
	int	i;

	img->y = -1;
	while (map->grid[++img->y])
	{
		img->x = -1;
		while (map->grid[img->y][++img->x])
		{
			img->c = map->grid[img->y][img->x];
			if (img->c == '1')
			{
				i = check_arround(map, img->x, img->y);
				mlx_put_image_to_window(img->mlx, img->win, fence[i - 1], \
				(img->x * 64), (img->y * 64));
			}
			else if (img->c == '0' || img->c == 'P'
				|| img->c == 'C' || img->c == 'E')
				mlx_put_image_to_window(img->mlx, img->win, grass, \
				(img->x * 64), (img->y * 64));
		}
	}
}

void	build_map(t_map *map)
{
	t_img	*img;
	void	**fence;
	void	*grass;

	img = ft_calloc(1, sizeof(t_img));
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, (map->max_x + 1) * 64, \
	(map->max_y + 1) * 64, "so_long");
	fence = get_fence(img);
	grass = mlx_xpm_file_to_image(img->mlx, "imgs/0.xpm", &img->w, &img->h);
	put_map_image_basic(map, img, fence, grass);
	mlx_key_hook(img->win, keyhook, &img);
	mlx_hook(img->win, 17, 0L, close_game, &img);
	mlx_loop(img->mlx);
}
