/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:00:48 by dyunta            #+#    #+#             */
/*   Updated: 2024/07/27 14:54:50 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_constructor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:27:22 by dyunta            #+#    #+#             */
/*   Updated: 2024/07/27 14:19:25 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static char***	map_constructor(const char* file_path);

void	map_init(const char *file_path, t_map* map)
{
	map->arr = map_constructor(file_path);
	map->height = get_map_height(file_path);
	map->width = get_map_width(map->arr);
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

/*
 * Returns the total number of elements that exist in the first row
 * of a 2-dimensional array.
 */
int	get_map_width(char*** map)
{
	int	i;
	int len;

	i = 0;
	len = 0;
	while (map[0][i])
	{
		if (map[0][i][0] != '\n')
			len++;
		i++;
	}
	return (len);
}

/*
 * Returns the height (y-axis) of the input map file.
*/
int	get_map_height(const char* file_path)
{
	int		y;
	int		fd;
	char*	line;

	fd = open_file(file_path);
	line = get_next_line(fd);
	y = 0;
	while (line)
	{
		if (line[0])
			y++;
		free(line);
		line = get_next_line(fd);
	}
	close_file(fd);
	return (y);
}
