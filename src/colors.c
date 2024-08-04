/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 10:16:12 by dyunta            #+#    #+#             */
/*   Updated: 2024/08/04 21:56:21 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static unsigned int	calculate_gradient(t_point a, t_point b, int x);
static double	percentage(double a, double b, double c);
static unsigned int	get_color_level(int z, int z_min, int z_max);

unsigned int	get_color_gradient(t_point curr, t_point b, int dx)
{
	t_point a;

	if (curr.color == b.color)
		return (curr.color);
	a.x = b.x - dx;
	a.color = curr.color;
	return (calculate_gradient(a, b, curr.x));
}

static unsigned int	calculate_gradient(t_point a, t_point b, int x)
{
	double	per;
	unsigned int 	red;
	unsigned int 	green;
	unsigned int 	blue;

	per = percentage(a.x, b.x, x);
	red = compute_color(a.color, b.color, per, 24);
	green = compute_color(a.color, b.color, per, 16);
	blue = compute_color(a.color, b.color, per, 8);

	return ((red << 24) | (green << 16) | (blue << 8) | 0xFF);
}

static double	percentage(double a, double b, double c)
{
	return ((c - a) / (b - a));
}

void	set_custom_colors(t_map *map)
{
	t_point **map_points;
	int		x;
	int 	y;
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
				*color = get_color_level(map_points[y][x].z, map->z_min, map->z_max);
			x++;
		}
		y++;
	}
}

static unsigned int	get_color_level(int z, int z_min, int z_max)
{
	double	per;

	per = percentage((double)z_min, (double)z_max, (double)z);
	if (per == 0)
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
