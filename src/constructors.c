/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 18:25:56 by dyunta            #+#    #+#             */
/*   Updated: 2024/08/04 14:46:16 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static t_point**	map_constructor(const char *file_path);
static t_point	*construct_points(char **row_map, t_point *row_points, int y, const char *file_path);

void	projection_init(t_projection *projection, t_map *map)
{
	projection->alpha = 0.8 / 2;
	projection->beta = 0.8;
	projection->x_rotate = 0;
	projection->y_rotate = 0;
	projection->z_rotate = 0;
	projection->x_offset = WIDTH / 2;
	projection->y_offset = HEIGHT / 2;
	projection->zoom = 1;
	projection->z_scale = 4;
	projection->high = INT_MIN;
	projection->low = INT_MAX;
	projection->interval = get_min_value(WIDTH / map->width,
			HEIGHT / map->height) / 2;
	projection->interval = get_max_value(2, (int)projection->interval);
}

void	map_init(const char *file_path, t_map *map)
{
	map->map_points = map_constructor(file_path);
	map->height = get_map_height(file_path);
	map->width = get_map_width(file_path);
	set_max_min_z(map);
}

void	fdf_init(t_map *map, t_projection *projection, t_fdf *fdf)
{
	fdf->map = map;
	fdf->mlx = mlx_init(WIDTH, HEIGHT, "FdF", true);
	if (!fdf->mlx)
	{
		ft_putstr_fd((char *)mlx_strerror(mlx_errno), 2);
		exit(EXIT_FAILURE);
	}
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!fdf->img || (mlx_image_to_window(fdf->mlx, fdf->img, 0, 0) < 0))
	{
		ft_putstr_fd((char *)mlx_strerror(mlx_errno), 2);
		exit(EXIT_FAILURE);
	}
	fdf->projection = projection;
}

/*
 * TODO: write docstrings
*/
static t_point**	map_constructor(const char *file_path)
{
	int		fd;
	int		y;
	char	*line;
	char 	**split;
	t_point	**map;

	map = (t_point **)malloc(sizeof(t_point *) * (get_map_height(file_path)));
	if (map == NULL)
		exit(EXIT_FAILURE);
	fd = open_file(file_path);
	line = get_next_line(fd);
	y = 0;
	while (line)
	{
		split = ft_split(line, ' ');
		map[y] = construct_points(split, map[y], y, file_path);
		free(line);
		line = get_next_line(fd);
		y++;
	}
	return (map);
}

static t_point	*construct_points(char **row_map, t_point *row_points, int y, const char *file_path)
{
	char	**split;
	int		x;

	row_points = (t_point *) malloc(sizeof(t_point) * get_map_width(file_path));
	if (row_points == NULL)
		exit(EXIT_FAILURE);
	x = 0;
	while (row_map[x])
	{
		split = ft_split(row_map[x], ',');
		row_points[x].x = x;
		row_points[x].y = y;
		row_points[x].z = ft_atoi(split[0]);
		if (split[1] != NULL)
			row_points[x].color = (ft_atoi_hex(split[1]) << 8) + 0xFF;
		else
			row_points[x].color = 0xFFFFFFFF;
		free_split(split);
		x++;
	}
	return (row_points);
}
