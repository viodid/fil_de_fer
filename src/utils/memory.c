/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:18:28 by dyunta            #+#    #+#             */
/*   Updated: 2024/08/05 11:44:05 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	free_map(t_map *map)
{
	t_point	**map_points;
	int	y;

	map_points = map->map_points;
	y = 0;
	while (y < map->height)
	{
		free(map_points[y]);
		y++;
	}
	free(map->map_points);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}
