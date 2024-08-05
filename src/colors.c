/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 10:16:12 by dyunta            #+#    #+#             */
/*   Updated: 2024/08/05 14:26:43 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static unsigned int	calculate_gradient(t_point a, t_point b, int x);
static unsigned int	compute_color(unsigned int color_a,
						unsigned int color_b, double per, int bitshift);

unsigned int	get_color_gradient(t_point curr, t_point b, int dx)
{
	t_point	a;

	if (curr.color == b.color)
		return (curr.color);
	a.x = b.x - dx;
	a.color = curr.color;
	return (calculate_gradient(a, b, curr.x));
}

static unsigned int	calculate_gradient(t_point a, t_point b, int x)
{
	double			per;
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;

	per = percentage(a.x, b.x, x);
	red = compute_color(a.color, b.color, per, 24);
	green = compute_color(a.color, b.color, per, 16);
	blue = compute_color(a.color, b.color, per, 8);
	return ((red << 24) | (green << 16) | (blue << 8) | 0xFF);
}

double	percentage(double a, double b, double c)
{
	return ((c - a) / (b - a));
}

static unsigned int	compute_color(unsigned int color_a,
						unsigned int color_b, double per, int bitshift)
{
	unsigned int	output_color;

	color_a = (color_a >> bitshift) & 0xFF;
	color_b = (color_b >> bitshift) & 0xFF;
	if ((color_a) == (color_b))
		return (color_a);
	if (color_a < color_b)
		output_color = color_a + ((unsigned int)((color_b - color_a) * per));
	else
		output_color = color_a - ((unsigned int)((color_a - color_b) * per));
	if (output_color > 0xFF)
		output_color = 0xFF;
	return (output_color);
}
