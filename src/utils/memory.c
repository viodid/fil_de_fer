/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:18:28 by dyunta            #+#    #+#             */
/*   Updated: 2024/08/03 19:56:33 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	free_map(t_map *map)
{
	t_point	**map_points;
	int	y;
	int	x;

	map_points = map->map;
	y = 0;
	x = 0;
	while (y < map->height)
	{
		free(map_points[y]);
		y++;
	}
	free(map->map);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}
