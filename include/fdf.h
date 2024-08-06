/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:12:30 by dyunta            #+#    #+#             */
/*   Updated: 2024/08/06 12:45:01 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 			1920
# define HEIGHT			1080
# define BACKGROUND		0x222222FF
# define DEFAULT_COLOR	0xFFFFFFFF
# define COLOR_TEN		0xFF0000FF
# define COLOR_NINE		0xD53E4FFF
# define COLOR_EIGHT	0xF46D43FF
# define COLOR_SEVEN	0xFDAE61FF
# define COLOR_SIX		0xFEE08BFF
# define COLOR_FIVE		0xE6F598FF
# define COLOR_FOUR		0XABDDA4FF
# define COLOR_THREE	0x66C2A5FF
# define COLOR_TWO		0x3288BDFF
# define COLOR_ONE		0x5E4FA2FF

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include "../lib/GNL/get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <math.h>

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	unsigned int	color;
}	t_point;

typedef struct s_point_double
{
	double	x;
	double	y;
	double	z;
}	t_point_double;

typedef struct s_projection
{
	double	alpha;
	double	beta;
	double	interval;
	double	x_rotate;
	double	y_rotate;
	double	z_rotate;
	double	z_scale;
	int		x_offset;
	int		y_offset;
	double	zoom;

}	t_projection;

typedef struct s_map
{
	int			width;
	int			height;
	int			z_max;
	int			z_min;
	t_point		**map_points;
}	t_map;

typedef struct s_fdf
{
	void			*mlx;
	void			*img;
	t_map			*map;
	t_projection	*projection;
}	t_fdf;

/*
 * Hooks
 */
void			hooks(void *param);
void			scroll_hook(double _, double delta, void *param);
void			rotation_hooks(void *param);

/*
 * Map utils.
 */
void			projection_init(t_projection *projection, t_map *map);
void			map_init(const char *file_path, t_map *map);
void			fdf_init(t_map *map, t_projection *projection, t_fdf *fdf);
int				get_map_height(const char *file_path);
int				get_map_width(const char *file_path);
int				get_map_width_line(char **str_arr);
void			free_map(t_map *map);
void			set_max_min_z(t_map *map);
double			get_min_value(double a, double b);
double			get_max_value(double a, double b);
void			reset_canvas(mlx_image_t *img);

/*
 * Other utils.
 */
void			args_sanitizer(int argc, char *argv[]);
int				open_file(const char *file_pat);
void			close_file(int fd);
void			free_split(char **split);

/*
 * Color utils.
 */
unsigned int	get_color_gradient(t_point curr, t_point b, int dx);
void			set_custom_colors(t_map *map);
double			percentage(double a, double b, double c);

/*
 * Bresenham's .
 */
void			draw_map(void *param);
int				bresenham_utils(int *coordinate, int e, int dx, int dy);

/*
 * Isometric projection transformations.
 */
t_point			apply_transformations(int x, int y, t_fdf *fdf);
#endif