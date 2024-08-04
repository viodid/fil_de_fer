/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 10:16:12 by dyunta            #+#    #+#             */
/*   Updated: 2024/08/04 12:50:30 by dyunta           ###   ########.fr       */
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
	red = (int)(((a.color >> 24) + (b.color >> 24)) * per);
	green = (int)((((a.color & 0x00FFFFFF) >> 16) + ((b.color & 0x00FFFFFF) >> 16)) * per);
	blue = (int)(((a.color & 0x0000FFFF >> 8) + (b.color & 0x0000FFFF >> 8)) * per);
	return (((red << 24) + (green << 16) + (blue << 8)) + 0xFF);
}

static double	percentage(double a, double b, double c)
{
	return ((c - a) / (b - a));
}
