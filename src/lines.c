/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:09:51 by dyunta            #+#    #+#             */
/*   Updated: 2024/07/20 19:35:57 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/fdf.h"

static void	big_slope(int dx, int dy, t_point* a);
static void	small_slope(int dx, int dy, t_point* a);
static void	draw_line(t_point* a, t_point* b);

void draw_map()
{
	int x;
	int y;
	t_point* a;
	t_point* b;

	a = (t_point*) malloc(sizeof(t_point));
	b = (t_point*) malloc(sizeof(t_point));
	a->x = 0;
	while (a->x < WIDTH)
	{
		a->y = 0;
		b->x = a->x + 1;
		while (a->y < HEIGHT)
		{
			a->y = a->y + 1;
			draw_line(a, b);
			a->y++;
		}
		a->x++;
	}
	free(a);
	free(b);
}

/*
 * var dx and dy represents de difference between x2 - x1 and y2 - 1
 * respectively.
 */
static void	draw_line(t_point* a, t_point* b)
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

	p = 2 * abs(dy) - abs(dx);
	i = 0;
	put_pixel(a->x, a->y);
	while (i < abs(dx))
	{
		if (dx > 0)
			a->x++;
		else
			a->x--;
		if (p < 0)
			p += 2 * abs(dy);
		else
		{
			p += 2 * abs(dy) - 2 * abs(dx);
			if (dy > 0)
				a->y++;
			else
				a->y--;
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

	p = 2 * abs(dx) - abs(dy);
	i = 0;
	put_pixel(a->x, a->y);
	while (i < abs(dy))
	{
		if (dx > 0)
			a->y++;
		else
			a->y--;
		if (p < 0)
			p += 2 * abs(dx);
		else
		{
			p += 2 * abs(dx) - 2 * abs(dy);
			if (dy > 0)
				a->x++;
			else
				a->x--;
		}
		put_pixel(a->x, a->y);
		i++;
	}
}
