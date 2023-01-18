/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:50:56 by francisco         #+#    #+#             */
/*   Updated: 2023/01/18 00:59:22 by francisco        ###   ########.fr       */
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
// for testing
# include <stdio.h>

// BUFFER_SIZE for get_next_line
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

/* errors */

# define ERR_CHAR "Error: map character isn't valid\n"
# define ERR_BOUND "Error: map isn't square\n"
# define ERR_BOUND1 "Error: map isn't walled correctly\n"
# define ERR_SE "Error: starting position and/or exit ammount isn't valid\n"
# define ERR_COL "Error: number of collectibles isn't valid\n"
# define ERR_PATH "Error: there isn't a valid path to the exit\n"

/* keycodes */

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

/* structs */

typedef struct t_map {
	char	**grid;
	int		max_x;
	int		max_y;
} t_map;

typedef struct t_d1 {
	int		x;
	int		y;
	int		exit;
	int		player;
	int		collect;
	char	c;
} t_d1;

/* mandatory */

// errors.c
void	error_msg(char *error);

// map.c
void	read_map(t_map *map, int fd);
void	check_map_chars(t_map *map, t_d1 *d);
int		check_map_valid(t_map *map);
void	check_map(t_map *map);

/* functions */

// ft_calloc.c
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);

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

// get_next_line.c
char	*ft_free(char *buffer, char *buf);
char	*ft_next(char *buffer);
char	*ft_line(char *buffer);
char	*read_file(int fd, char *res);
char	*get_next_line(int fd);

#endif
