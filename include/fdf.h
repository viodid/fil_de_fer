/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:12:30 by dyunta            #+#    #+#             */
/*   Updated: 2024/07/28 18:32:57 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#define WIDTH 2048
#define HEIGHT 1024
#ifndef ZOOM
#define ZOOM 20
#endif

#include "../MLX42/include/MLX42/MLX42.h"
#include "../lib/libft/libft.h"
#include "../lib/GNL/get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <math.h>

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
} t_point;

typedef struct s_projection
{
	int		zoom;
	double 	x_angle;
	double 	y_angle;
	double 	z_angle;
	float 	z_height;
	int 	x_offset;
	int 	y_offset;
	int 	isometric;
}	t_projection;

typedef struct s_map
{
	int				width;
	int				height;
	int				z_max;
	int				z_min;
	char***			arr;
	t_projection*	projection;
}	t_map;

typedef struct s_fdf
{
	void*	mlx;
	void*	img;
	t_map*	map;
}	t_fdf;

/*
 * Map utils.
 */
void	projection_init(t_projection* projection, t_fdf* fdf);
void	map_init(const char *file_path, t_map* map);
void	fdf_init(t_map* map, t_fdf* fdf);
int		get_map_height(const char* file_path);
int		get_map_width(char*** map);
void	free_map(char*** map);
void	set_max_min_z(t_map* map);

/*
 * Other utils.
 */
void	args_sanitizer(int argc, char *argv[]);
int		open_file(const char *file_pat);
void    close_file(int fd);
void	free_split(char** split);
int		get_min_value(int a, int b);

/*
 * Bresenham's .
 */
void	draw_map(t_fdf *fdf);

/*
 * Isometric projection transformations.
 */
t_point apply_transformations(int x, int y, t_fdf *fdf);


#endif