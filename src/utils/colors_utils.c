/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 21:34:54 by dyunta            #+#    #+#             */
/*   Updated: 2024/08/05 15:03:41 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static unsigned int	get_color_level(int z, int z_min, int z_max);

void	set_custom_colors(t_map *map)
{
	t_point			**map_points;
	int				x;
	int				y;
	unsigned int	*color;

	map_points = map->map_points;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			color = &map_points[y][x].color;
			if (*color == 0x42424242)
				*color = get_color_level(map_points[y][x].z,
						map->z_min, map->z_max);
			x++;
		}
		y++;
	}
}

static unsigned int	get_color_level(int z, int z_min, int z_max)
{
	double	per;

	per = percentage((double)z_min, (double)z_max, (double)z);
	if (z_min == z_max || per == 0)
		return (DEFAULT_COLOR);
	if (per < 0.1)
		return (COLOR_ONE);
	else if (per < 0.2)
		return (COLOR_TWO);
	else if (per < 0.3)
		return (COLOR_THREE);
	else if (per < 0.4)
		return (COLOR_FOUR);
	else if (per < 0.5)
		return (COLOR_FIVE);
	else if (per < 0.6)
		return (COLOR_SIX);
	else if (per < 0.7)
		return (COLOR_SEVEN);
	else if (per < 0.8)
		return (COLOR_EIGHT);
	else if (per < 0.9)
		return (COLOR_NINE);
	else
		return (COLOR_TEN);
}
