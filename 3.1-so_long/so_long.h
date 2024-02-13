/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:01:23 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/13 19:44:14 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/***** INCLUDES *****/
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# include "libft/libft.h"
# include "defines.h"

# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>

/***** TYPEDEFS & STRUCTS *****/
//a byte. 8 bits.
typedef unsigned char	t_byte;

/*
 * line_len
 * `void *`	img_ptr;
 * `char *`	img_pixels_ptr;
 * `int`	bpp; //bits per pixel
 * `int`	endian;
 * `int`	line_len; //necessary due to alignment optimization.
*/
typedef struct s_img
{
	void	*ptr;
	char	*pxls_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}				t_img;

/** 
 * - `void *`	cnx;
 * - `void *`	wdw;
 * - `t_img`	img[SPRITES_NB];
 * - `char **`	map;
 * - `int`		width;
 * - `int`		height;
 * - `int`		coinsleft;
 * - `int`		px;
 * - `int`		py;
 * - `char` 	dir;
*/
typedef struct s_mlx
{
	void	*cnx;
	void	*wdw;
	t_img	img[SPRITES_NB];
	char	**map;
	int		width;
	int		height;
	int		coinsleft;
	int		moves;
	int		px;
	int		py;
	int 	dir;
}			t_mlx;

/**
 * - `int` count_p;
 * - `int` count_e;
 * - `int` count_c;
 * - `char **` visited;
*/
typedef struct s_checks
{
	int		count_p;
	int		count_e;
	int		count_c;
	char	**dfsmap;
}			t_checks;

/***** FUNCTIONS *****/

int		ft_quit(void *data);
//quit.c

int		is_valid_map(char **map, char *fname, t_mlx *data);
//checks.c

int		put_wdw(t_mlx *data, char *title, int width, int height);
void	put_map(t_mlx *data);
//display.c

int		set_textures(t_mlx *data);
int 	is_blocked(t_mlx *data);
void	move_player(t_mlx *data);
int	animate_player(void *data);
//display_utils.c

int		handle_key(int keysym, t_mlx *data);
//input.c

long	get_xy(char **map, char element);
//position.c

int		encode_rgb(t_byte red, t_byte green, t_byte blue);
void	my_pixel_put(t_img *img, int x, int y, int color);
void	color_fill(t_mlx *data, int color, int x, int y);
int		print_img(t_mlx *data, void *imgptr, int x, int y);
//mlx_utils.c

#endif
