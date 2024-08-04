/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 10:16:12 by dyunta            #+#    #+#             */
/*   Updated: 2024/08/04 17:36:48 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static unsigned int	calculate_gradient(t_point a, t_point b, int x);
static double	percentage(double a, double b, double c);
static unsigned int	get_color_level(int z, int z_min, int z_max);

unsigned int	get_color_gradient(t_point curr, t_point b, int dx, int is_big_slope)
{
	t_point a;

	if (curr.color == b.color)
		return (curr.color);
	a.x = b.x - dx;
	a.color = curr.color;
	if (is_big_slope)
		return (calculate_gradient(a, b, curr.x));
	return (calculate_gradient(b, a, curr.x));
}

static unsigned int	calculate_gradient(t_point a, t_point b, int x)
{
	double	per;
	unsigned int 	red;
	unsigned int 	green;
	unsigned int 	blue;

	per = percentage(a.x, b.x, x);
	if (per == 0)
		return (a.color);

	if ((a.color >> 24) == (b.color >> 24))
		red = (int)a.color >> 24;
	else
	{
		red = (int)(((a.color >> 24) + (b.color >> 24)) * per);
		if (red > 0xFF)
			red = 0xFF;
		else if (red < (a.color >> 24))
			red = a.color >> 24;
	}


	if (((a.color & 0x00FFFFFF) >> 16) == ((b.color & 0x00FFFFFF) >> 16))
		green = (int)((a.color & 0x00FFFFFF) >> 16);
	else
	{
		green = (int)((((a.color & 0x00FFFFFF) >> 16) + ((b.color & 0x00FFFFFF) >> 16)) * per);
		if (green > 0xFF)
			green = 0xFF;
		else if (green < ((a.color & 0xFFFFFF) >> 16))
			green = green < ((a.color & 0xFFFFFF) >> 16);
	}


	if (((a.color & 0x0000FFFF) >> 8) == ((b.color & 0x0000FFFF) >> 8))
		blue = (int)((a.color & 0x0000FFFF) >> 8);
	else
	{
		blue = (int)((((a.color & 0x0000FFFF) >> 8) + ((b.color & 0x0000FFFF) >> 8)) * per);
		if (blue > 0xFF)
			blue = 0xFF;
		else if (blue < ((a.color & 0xFFFF) >> 8))
			green = green < ((a.color & 0xFFFF) >> 8);
	}
	unsigned int output = (((red << 24) + (green << 16) + (blue << 8)) + 0xFF);
	return (((red << 24) + (green << 16) + (blue << 8)) + 0xFF);
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
