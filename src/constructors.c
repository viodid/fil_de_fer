/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 18:25:56 by dyunta            #+#    #+#             */
/*   Updated: 2024/07/28 18:32:08 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static char***	map_constructor(const char* file_path);

void	projection_init(t_projection* projection, t_fdf* fdf)
{
	projection->zoom = get_min_value(WIDTH / fdf->map->width / 2,
									 HEIGHT / fdf->map->height / 2);
	projection->x_angle = -0.615472907;
	projection->y_angle = -0.523599;
	projection->z_angle = 0.615472907;
	projection->z_height = 1;
	projection->x_offset = 0;
	projection->y_offset = 0;
	projection->isometric = 1;
}

void	map_init(const char *file_path, t_map* map)
{
	map->arr = map_constructor(file_path);
	map->height = get_map_height(file_path);
	map->width = get_map_width(map->arr);
	set_max_min_z(map);
}

void	fdf_init(t_map* map, t_fdf* fdf)
{
	fdf->map = map;
	fdf->mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
	if (!fdf->mlx)
	{
		fprintf(stderr, "%s", mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!fdf->img || (mlx_image_to_window(fdf->mlx, fdf->img, 0, 0) < 0))
	{
		fprintf(stderr, "%s", mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
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
