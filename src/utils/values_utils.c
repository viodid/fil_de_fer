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
