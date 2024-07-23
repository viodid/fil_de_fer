/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:09:51 by dyunta            #+#    #+#             */
/*   Updated: 2024/07/23 22:10:57 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/fdf.h"

static void	big_slope(int dx, int dy, t_point* p, mlx_image_t* img);
static void	small_slope(int dx, int dy, t_point* p, mlx_image_t* img);
static void	draw_line(t_point* a, t_point* b, mlx_image_t* img);
static void	ft_put_pixel(mlx_image_t* img, t_point* p, uint32_t color);

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
			a->x--;
			b->x = a->x;
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
 * var e represents the slope error.
 * @param dx The difference between x2 - x1
 * @param dy The difference between y2 - y1
 */
static void	small_slope(int dx, int dy, t_point* p, mlx_image_t* img)
{
	int	e;
	int i;
//	int x;
//	int y;
//
//	x = p->x;
//	y = p->y;
	e = 2 * abs(dy) - abs(dx);
	i = 0;
	ft_put_pixel(img, p, 0xFFFFFF);
	while (i < abs(dx))
	{
		if (dx > 0)
			p->x++;
//		else
//			p->x--;
		if (e < 0)
			e += 2 * abs(dy);
		else
		{
			e += 2 * abs(dy) - 2 * abs(dx);
			if (dy > 0)
				p->y++;
			else
				p->y--;
		}
		ft_put_pixel(img, p, 0xFFFFFF);
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
//	int x;
//	int y;
//
//	x = p->x;
//	y = p->y;
	e = 2 * abs(dx) - abs(dy);
	i = 0;
	ft_put_pixel(img, p, 0xFF00FF);
	while (i < abs(dy))
	{
		if (dx > 0)
			p->y++;
//		else
//			p->y--;
		if (e < 0)
			e += 2 * abs(dx);
		else
		{
			e += 2 * abs(dx) - 2 * abs(dy);
			if (dy > 0)
				p->x++;
			else
				p->x--;
		}
		ft_put_pixel(img, p, 0xFF00FF);
		i++;
	}
}

static void	ft_put_pixel(mlx_image_t* img, t_point* p, uint32_t color)
{
	int tmp;
	int x;
	int y;
	int	z;

	tmp = p->x;
	x = p->x;
	y = p->y;
	z = p->z;
	x *= ZOOM;
	x += WIDTH / 2;
	y *= ZOOM;
	y += HEIGHT / 2;
	mlx_put_pixel(img, x, y, color);
}

