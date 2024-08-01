/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 18:25:56 by dyunta            #+#    #+#             */
/*   Updated: 2024/08/01 23:09:25 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static char***	map_constructor(const char* file_path);

void	projection_init(t_projection* projection, t_map* map)
{
	projection->alpha = 0.46373398 / 2;
	projection->beta = 0.46373398;
	projection->x_rotate = 0;
	projection->y_rotate = 0;
	projection->z_rotate = 0;
	projection->x_offset =  WIDTH / 2;
	projection->y_offset = HEIGHT / 2;
	projection->zoom = 1;
	projection->z_scale = 1;
	projection->high = INT_MIN;
	projection->low = INT_MAX;
	projection->interval = get_min_value(WIDTH / map->width, HEIGHT / map->height) / 2;
	projection->interval = get_max_value(2, (int)projection->interval);
}

void	map_init(const char *file_path, t_map* map)
{
	map->arr = map_constructor(file_path);
	map->height = get_map_height(file_path);
	map->width = get_map_width(map->arr);
	set_max_min_z(map);
}

void	fdf_init(t_map* map, t_projection* projection, t_fdf* fdf)
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
static char***	map_constructor(const char* file_path)
{
	int		fd;
	int		i;
	char*	line;
	char***	map;

	map = (char ***)malloc(sizeof(char **) * (get_map_height(file_path) + 1));
	if (map == NULL)
		exit(EXIT_FAILURE);
	fd = open_file(file_path);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		map[i++] = ft_split(line, ' ');
		free(line);
		line = get_next_line(fd);
	}
	map[i] = NULL;
	return (map);
}
