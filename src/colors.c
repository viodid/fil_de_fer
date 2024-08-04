/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 10:16:12 by dyunta            #+#    #+#             */
/*   Updated: 2024/08/04 12:28:09 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static double	percentage(double a, double b, double c);

int	get_color_gradient(t_point curr, t_point b, int dx, int dy)
{
	t_point a;
	double	per;
	int 	red;
	int 	green;
	int 	blue;

	if (curr.color == b.color)
		return (curr.color);
	a.x = b.x - dx;
	a.y = b.y - dy;
	a.color = curr.color;
	per = percentage(a.x, b.x, curr.x);
	if (per == 0)
		return (a.color);
	red = (int)(((a.color >> 16) + (b.color >> 16)) * per);
	green = (int)((((a.color & 0x00FFFF) >> 8) + ((b.color & 0x00FFFF) >> 8)) * per);
	blue = (int)(((a.color & 0x0000FF) + (b.color & 0x0000FF)) * per);
	int output = ((red << 16) + (green << 8) + blue);
	return ((red << 16) + (green << 8) + blue);
}

static double	percentage(double a, double b, double c)
{
	return ((c - a) / (b - a));
}
