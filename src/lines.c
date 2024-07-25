/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:09:51 by dyunta            #+#    #+#             */
/*   Updated: 2024/07/25 18:57:41 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/fdf.h"

static void	big_slope(int dx, int dy, t_point* p, mlx_image_t* img);
static void	small_slope(int dx, int dy, t_point* p, mlx_image_t* img);
static void	draw_line(t_point* a, t_point* b, mlx_image_t* img);
static void	ft_put_pixel(mlx_image_t* img, int x, int y, uint32_t color);
static void	set_point(int x, int y, t_point* a, t_point* b);


void draw_map(mlx_image_t* img, t_fdf *map)
{
	t_point	a;
	t_point	b;
	int		x;
	int 	y;

	x = 0;
	while (x < map->width)
	{
		y = 0;
		while (y < map->height)
		{
			set_point(x, y, &a, &b);
			b.x++;
			if (x + 1 < map->width)
				draw_line(&a, &b, img);
			set_point(x, y, &a, &b);
			b.y++;
			if (y + 1 < map->height)
				draw_line(&a, &b, img);
			y++;
		}
		x++;
	}
}

static void	set_point(int x, int y, t_point* a, t_point* b)
{
	a->x = x;
	a->y = y;
	b->x = x;
	b->y = y;
}

/*
 * var dx and dy represents de difference between x2 - x1 and y2 - 1
 * respectively.
 */
static void	draw_line(t_point* a, t_point* b, mlx_image_t* img)
{
	int	dx;
	int dy;

	a->x *= ZOOM;
	a->y *= ZOOM;
	b->x *= ZOOM;
	b->y *= ZOOM;
	dx = b->x - a->x;
	dy = b->y - a->y;
	printf("x1: %d - y1: %d | x2: %d - y2: %d | dx: %d - dy: %d\n", a->x, a->y, b->x, b->y, dx, dy);
	if (abs(dx) > abs(dy))
		small_slope(dx, dy, a, img);
	else
		big_slope(dx, dy, a, img);
}

/**
 * Small slope means that slope m <= 1.
 * var e represents the slope error.
 * @param dx The difference between x2 - x1
 * @param dy The difference between y2 - y1
 */
static void	small_slope(int dx, int dy, t_point* p, mlx_image_t* img)
{
	int	e;
	int i;
	int x;
	int y;

	x = p->x;
	y = p->y;
	e = 2 * abs(dy) - abs(dx);
	i = 0;
	ft_put_pixel(img, x, y, 0xFFFFFF);
	while (i < abs(dx))
	{
		if (dx >= 0)
			x++;
		else
			x--;
		if (e < 0)
			e += 2 * abs(dy);
		else
		{
			e += 2 * abs(dy) - 2 * abs(dx);
			if (dy >= 0)
				y++;
			else
				y--;
		}
		ft_put_pixel(img, x, y, 0xFFFFFF);
		i++;
	}
}

/**
 * big slope means that slope m > 1.
 * var e represents the slope error.
 * @param dx The difference between x2 - x1
 * @param dy The difference between y2 - y1
 */
static void	big_slope(int dx, int dy, t_point* p, mlx_image_t* img)
{
	int	e;
	int i;
	int x;
	int y;

	x = p->x;
	y = p->y;
	e = 2 * abs(dx) - abs(dy);
	i = 0;
	ft_put_pixel(img, x, y, 0xFF00FF);
	while (i < abs(dy))
	{
		if (dx >= 0)
			y++;
		else
			y--;
		if (e < 0)
			e += 2 * abs(dx);
		else
		{
			e += 2 * abs(dx) - 2 * abs(dy);
			if (dy >= 0)
				x++;
			else
				x--;
		}
		ft_put_pixel(img, x, y, 0xFF00FF);
		i++;
	}
}

static void	ft_put_pixel(mlx_image_t* img, int x, int y, uint32_t color)
{
	int tmp;

	tmp = x;
	x += WIDTH / 2;
	y += HEIGHT / 2;
//	x = (int)((tmp - y) * cos(0.523599));
//	y = (int)((tmp + y) * sin(0.523599) - z);
	mlx_put_pixel(img, x, y, color);
}

