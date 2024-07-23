/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:09:51 by dyunta            #+#    #+#             */
/*   Updated: 2024/07/23 21:45:28 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/fdf.h"

static void	big_slope(int dx, int dy, t_point* a, mlx_image_t* img);
static void	small_slope(int dx, int dy, t_point* a, mlx_image_t* img);
static void	draw_line(t_point* a, t_point* b, mlx_image_t* img);
static void	ft_put_pixel(mlx_image_t* img, uint32_t x, uint32_t y, uint32_t color);

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
			b->x = a->x;
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
 * @param dy The difference between y2 - y1
 */
static void	small_slope(int dx, int dy, t_point* a, mlx_image_t* img)
{
	int	p;
	int i;
	int x;
	int y;

	x = a->x;
	y = a->y;
	p = 2 * abs(dy) - abs(dx);
	i = 0;
	ft_put_pixel(img, x, y, 0xFFFFFF);
	while (i < abs(dx))
	{
		if (dx > 0)
			x++;
//		else
//			a->x--;
		if (p < 0)
			p += 2 * abs(dy);
		else
		{
			p += 2 * abs(dy) - 2 * abs(dx);
			if (dy > 0)
				y++;
			else
				y--;
		}
		mlx_put_pixel(img, x, y, 0xFFFFFF);
		i++;
	}
}

/**
 * big slope means that slope m > 1.
 * var p represents the slope error.
 * @param dx The difference between x2 - x1
 * @param dy The difference between y2 - y1
 */
static void	big_slope(int dx, int dy, t_point* a, mlx_image_t* img)
{
	int	p;
	int i;
	int x;
	int y;

	x = a->x;
	y = a->y;
	p = 2 * abs(dx) - abs(dy);
	i = 0;
	ft_put_pixel(img, x, y, 0xFFFFFF);
	while (i < abs(dy))
	{
		if (dx > 0)
			y++;
//		else
//			a->y--;
		if (p < 0)
			p += 2 * abs(dx);
		else
		{
			p += 2 * abs(dx) - 2 * abs(dy);
			if (dy > 0)
				x++;
			else
				x--;
		}
		mlx_put_pixel(img, x, y, 0xFFFFFF);
		i++;
	}
}

static void	ft_put_pixel(mlx_image_t* img, uint32_t x, uint32_t y, uint32_t color)
{
	x *= ZOOM;
	x += WIDTH / 2;
	y *= ZOOM;
	y += HEIGHT / 2;
	mlx_put_pixel(img, x, y, color);
}

