/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:09:51 by dyunta            #+#    #+#             */
/*   Updated: 2024/07/20 19:10:44 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/fdf.h"

static void	big_slope(int dx, int dy, t_point* a);
static void	small_slope(int dx, int dy, t_point* a);

/*
 * var dx and dy represents de difference between x2 - x1 and y2 - 1
 * respectively.
 */
void	draw_line(t_point* a, t_point* b)
{
	int	dx;
	int dy;

	dx = b->x - a->x;
	dy = b->y - a->y;
	if (abs(dx) > abs(dy))
		small_slope(dx, dy, a);
	else
		big_slope(dx, dy, a);
}

/*
 * Small slope means that slope m <= 1.
 * var p represents the slope error.
 */
static void	small_slope(int dx, int dy, t_point* a)
{
	int	p;
	int i;

	p = 2 * dy - dx;
	i = 0;
	put_pixel(a->x, a->y);
	while (i < dx)
	{
		a->x++;
		if (p < 0)
			p += 2 * dy;
		else
		{
			p += 2 * dy - 2 * dx;
			a->y++;
		}
		put_pixel(a->x, a->y);
		i++;
	}
}

/*
 * big slope means that slope m > 1.
 * var p represents the slope error.
 */
static void	big_slope(int dx, int dy, t_point* a)
{
	int	p;
	int i;

	p = 2 * dx - dy;
	i = 0;
	put_pixel(a->x, a->y);
	while (i < dx)
	{
		a->y++;
		if (p < 0)
			p += 2 * dx;
		else
		{
			p += 2 * dx - 2 * dy;
			a->x++;
		}
		put_pixel(a->x, a->y);
		i++;
	}
}
