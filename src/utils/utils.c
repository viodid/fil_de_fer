/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:00:48 by dyunta            #+#    #+#             */
/*   Updated: 2024/07/28 18:30:01 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

/**
 * Iterates over 3-dimensional array pointed by map->arr and sets its
 * maximum and minimum z values to the corresponding variable in the struct t_map.
 * @param map The pointer to the struct that holds the 3-dimensional array
 */
void	set_max_min_z(t_map* map)
{
	char***	arr;
	char**	tmp;
	int 	x;
	int 	y;

	arr = map->arr;
	tmp = ft_split(arr[0][0], ',');
	map->z_max = ft_atoi(tmp[0]);
	map->z_min = map->z_max;
	free_split(tmp);
	y = 0;
	while(arr[y])
	{
		x = 0;
		while(arr[y][x])
		{
			tmp = ft_split(arr[y][x], ',');
			if (ft_atoi(tmp[0]) > map->z_max)
				map->z_max = ft_atoi(tmp[0]);
			else if (ft_atoi(tmp[0]) < map->z_min)
				map->z_min = ft_atoi(tmp[0]);
			free_split(tmp);
			x++;
		}
		y++;
	}
}

int	get_min_value(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
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