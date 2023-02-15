/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francsan <francsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:50:56 by francisco         #+#    #+#             */
/*   Updated: 2023/02/15 17:37:21 by francsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// for open
# include <fcntl.h>
// for malloc and free
# include <stdlib.h>
// for read and write
# include <unistd.h>
// for minilibx
# include <mlx.h>
// FOR TESTING
# include <stdio.h>

// BUFFER_SIZE for get_next_line
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

/* errors */

# define ERR_FILE "Error: arguments aren't valid\n"
# define ERR_FILE1 "Error: map file isn't valid\n"
# define ERR_FILE2 "Error: map file provided is a directory\n"
# define ERR_CHAR "Error: map character isn't valid\n"
# define ERR_BOUND "Error: map isn't square\n"
# define ERR_BOUND1 "Error: map isn't walled correctly\n"
# define ERR_SE "Error: starting position and/or exit ammount isn't valid\n"
# define ERR_COL "Error: number of collectibles isn't valid\n"
# define ERR_PATH "Error: there isn't a valid path to the exit\n"
# define ERR_MEM "Error: couldn't allocate memory\n"

/* keycodes */

// keycodes for linux
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

// keycodes for macos
// # define KEY_ESC 53
// # define KEY_W 13
// # define KEY_A 0
// # define KEY_S 1
// # define KEY_D 2

/* structs */

typedef struct t_game {
	void	**terrain;
	void	**fence;
	void	**player;
	void	*mlx;
	void	*win;
	char	**grid;
	char	up;
	char	down;
	char	right;
	char	left;
	char	c;
	int		max_x;
	int		max_y;
	int		player_x;
	int		player_y;
	int		moves;
	int		collectibles;
	int		i;
}	t_game;

typedef struct t_d1 {
	int		x;
	int		y;
	int		exit;
	int		player;
	int		collect;
	char	c;
}	t_d1;

/* mandatory */

// errors.c
void	error_msg_free(t_game **game, char *error);
void	error_msg(char *error);

// game_utils.c
void	position_init(t_game *game, int x, int y);
int		check_around_1(t_game *game, int x, int y);
int		check_around_2(t_game *game, int x, int y);
int		check_around_3(t_game *game, int x, int y);
int		check_arround(t_game *game, int x, int y);

// game.c
int		check_possible(t_game *game, int keycode);
void	key_hook_check(int keycode, t_game *game);
int		key_hook(int keycode, t_game **game);
int		close_game(t_game **game);
void	build_map(t_game *game);

// get_images.c
void	get_terrain(t_game *game);
void	get_fence(t_game *game);
void	get_player(t_game *game);

// images.c
void	selector_1(t_game *game, int x, int y);
void	selector_2(t_game *game, int x, int y);
void	put_move_counter(t_game *game);
void	put_map_image(t_game *game);
void	put_player_image(t_game *game, int keycode);

// map_utils.c
void	check_map_chars(t_game *game, t_d1 *d);
int		search_map_coordinate(int x, int y, char **grid, t_d1 *d);
int		search_map(int x, int y, char **grid, t_d1 *d);
int		check_map_valid(t_game *game, t_d1 *d);

// map.c
int		open_map_file(char *file);
void	read_map_lines(char **read, char **temp, int fd);
void	read_map(t_game *game, int fd);
void	check_map(t_game *game);

/* functions */

// ft_calloc.c
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);

// ft_itoa.c
char	*rev_num(char *num);
void	put_num(int n, char *num);
char	*ft_itoa(int n);

// ft_strarr_free.c
void	ft_strarr_free(char **strs);

// ft_strarr_copy.c
char	**ft_strarr_copy(char **arr);

// ft_split.c
int		mem_size(char const *s, char c);
int		word_size(const char *s, char c);
char	**fill_strs(char **strs, const char *s, char c);
char	**ft_split(char const *s, char c);

// ft_strchr.c
char	*ft_strchr(const char *s, int c);

// ft_strdup.c
char	*ft_strdup(const char *s1);

// ft_strjoin.c
char	*ft_strjoin(char const *s1, char const *s2);

// ft_strlcat.c
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

// ft_strlen.c
size_t	ft_strlen(const char *s);

// ft_strncmp.c
int		ft_strncmp(const char *s1, const char *s2, size_t n);

// get_next_line.c
char	*ft_free(char *buffer, char *buf);
char	*ft_next(char *buffer);
char	*ft_line(char *buffer);
char	*read_file(int fd, char *res);
char	*get_next_line(int fd);

#endif
