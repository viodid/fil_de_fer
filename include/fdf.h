/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:12:30 by dyunta            #+#    #+#             */
/*   Updated: 2024/07/27 14:26:21 by dyunta           ###   ########.fr       */
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

typedef struct s_fdf
{
	int		height;
	int		width;
	int 	z_max;
	int 	z_min;
	char***	map;
}	t_fdf;

typedef struct s_map
{
	char***	map;
};

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
} t_point;

/*
 * Map utils.
 */
int		get_map_height(const char* file_path);
int		get_map_width(char*** map);
void	fdf_init(const char *file_path, t_fdf* fdf);
void	free_map(char*** map);

/*
 * Other utils.
 */
void	args_sanitizer(int argc, char *argv[]);
int		open_file(const char *file_pat);
void    close_file(int fd);

/*
 * Bresenham's .
 */
void	draw_map(mlx_image_t* img, t_fdf *fdf);

/*
 * Isometric projection transformations.
 */
t_point apply_transformations(int x, int y, t_fdf *fdf);


#endif