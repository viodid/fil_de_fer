/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:00:48 by dyunta            #+#    #+#             */
/*   Updated: 2024/08/05 18:10:45 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

/**
 * Iterates over 2-dimensional array of t_points * and sets its
 * maximum and minimum z values to the corresponding variable in the
 * struct t_map. These values are used to set a premise from which to create
 * the color gradient.
 * @param map The pointer to the struct that holds the 2-dimensional array.
 */
void	set_max_min_z(t_map *map)
{
	int	x;
	int	y;
	int	curr;

	map->z_max = map->map_points[0][0].z;
	map->z_min = map->z_max;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			curr = map->map_points[y][x].z;
			if (curr > map->z_max)
				map->z_max = curr;
			else if (curr < map->z_min)
				map->z_min = curr;
			x++;
		}
		y++;
	}
}

double	get_min_value(double a, double b)
{
	if (a <= b)
		return (a);
	return (b);
}

double	get_max_value(double a, double b)
{
	if (a >= b)
		return (a);
	return (b);
}

/*
 * Returns the total number of elements that exist in the first row
 * of a 2-dimensional array.
 */
int	get_map_width(const char *file_path)
{
	int		len;
	int		fd;
	char	*line;
	char	**split;

	fd = open_file(file_path);
	line = get_next_line(fd);
	split = ft_split(line, ' ');
	len = get_map_width_line(split);
	free_split(split);
	free(line);
	return (len);
}

/*
 * NOTE: this function does NOT free the allocated memory.
 */
int	get_map_width_line(char **str_arr)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str_arr[i])
	{
		if (str_arr[i][0] != '\n')
			len++;
		i++;
	}
	return (len);
}

/*
 * Returns the height (y-axis) of the input map_points file.
*/
int	get_map_height(const char *file_path)
{
	int		y;
	int		fd;
	char	*line;

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
