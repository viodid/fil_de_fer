/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:09:51 by dyunta            #+#    #+#             */
/*   Updated: 2024/07/21 18:48:44 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/fdf.h"

static void	big_slope(int dx, int dy, t_point* a, mlx_image_t* img);
static void	small_slope(int dx, int dy, t_point* a, mlx_image_t* img);
static void	draw_line(t_point* a, t_point* b, mlx_image_t* img);

void draw_map(mlx_image_t* img, t_fdf *map)
{
	t_point* a;
	t_point* b;

	a = (t_point*) malloc(sizeof(t_point));
	b = (t_point*) malloc(sizeof(t_point));
	a->x = 0;
	while (a->x < map->height)
	{
		a->y = 0;
		while (a->y < map->width)
		{
			b->x = a->x + 1;
			b->y = a->y;
			draw_line(a, b, img);
			b->y++;
			draw_line(a, b, img);
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
static void	draw_line(t_point* a, t_point* b, mlx_image_t* img)
{
	int	dx;
	int dy;

	dx = b->x - a->x;
	dy = b->y - a->y;
	if (abs(dx) > abs(dy))
		small_slope(dx, dy, a, img);
	else
		big_slope(dx, dy, a, img);
}

/**
 * Small slope means that slope m <= 1.
 * var p represents the slope error.
 * @param dx The difference between x2 - x1
 */
static void	small_slope(int dx, int dy, t_point* a, mlx_image_t* img)
{
	int	p;
	int i;

	p = 2 * abs(dy) - abs(dx);
	i = 0;
	// TODO: CREATE HELPER FUNCTION ft_put_pixel to add zoom, offset and isometric projection
	mlx_put_pixel(img, a->x, a->y, 0xFFFFFF);
	while (i < abs(dx))
	{
		if (dx > 0)
			a->x++;
//		else
//			a->x--;
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
		mlx_put_pixel(img, a->x, a->y, 0xFFFFFF);
		i++;
	}
}

/*
 * big slope means that slope m > 1.
 * var p represents the slope error.
 */
static void	big_slope(int dx, int dy, t_point* a, mlx_image_t* img)
{
	int	p;
	int i;

	p = 2 * abs(dx) - abs(dy);
	i = 0;
	mlx_put_pixel(img, a->x, a->y, 0xFFFFFF);
	while (i < abs(dy))
	{
		if (dx > 0)
			a->y++;
//		else
//			a->y--;
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
		mlx_put_pixel(img, a->x, a->y, 0xFFFFFF);
		i++;
	}
}
