/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 10:16:12 by dyunta            #+#    #+#             */
/*   Updated: 2024/08/04 15:54:44 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static unsigned int	calculate_gradient(t_point a, t_point b, int x);
static double	percentage(double a, double b, double c);

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
		red = (int)(((a.color >> 24) + (b.color >> 24)) * per);
	if (((a.color & 0x00FFFFFF) >> 16) == ((b.color & 0x00FFFFFF) >> 16))
		green = (int)((a.color & 0x00FFFFFF) >> 16);
	else
		green = (int)((((a.color & 0x00FFFFFF) >> 16) + ((b.color & 0x00FFFFFF) >> 16)) * per);
	if (((a.color & 0x0000FFFF) >> 8) == ((b.color & 0x0000FFFF) >> 8))
		blue = (int)((a.color & 0x0000FFFF) >> 8);
	else
		blue = (int)((((a.color & 0x0000FFFF) >> 8) + ((b.color & 0x0000FFFF) >> 8)) * per);
	return (((red << 24) + (green << 16) + (blue << 8)) + 0xFF);
}

static double	percentage(double a, double b, double c)
{
	return ((c - a) / (b - a));
}
