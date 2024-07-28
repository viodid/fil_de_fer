/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:09:51 by dyunta            #+#    #+#             */
/*   Updated: 2024/07/28 19:01:08 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/fdf.h"

static void	big_slope(int dx, int dy, t_point* p, mlx_image_t* img);
static void	small_slope(int dx, int dy, t_point* p, mlx_image_t* img);
static void	draw_line(t_point a, t_point b, mlx_image_t* img);
static void	ft_put_pixel(mlx_image_t* img, int x, int y, uint32_t color);


void	draw_map(t_fdf *fdf)
{
	int		x;
	int 	y;

	y = 0;
	if (fdf->projection->x_angle > 0)
		y = fdf->map->height - 1;
	while (y < fdf->map->height && y >= 0)
	{
		x = 0;
		if (fdf->projection->y_angle > 0)
			x = fdf->map->width - 1;
		while (x < fdf->map->width && x >= 0)
		{
			if (x + 1 < fdf->map->width)
				draw_line(apply_transformations(x, y, fdf), apply_transformations(x + 1, y, fdf), fdf->img);
			if (y + 1 < fdf->map->height)
				draw_line(apply_transformations(x, y, fdf), apply_transformations(x, y + 1, fdf), fdf->img);
			x += -2 * (fdf->projection->x_angle > 0) + 1;
		}
		y += -2 * (fdf->projection->x_angle > 0) + 1;
	}
}

/*
 * var dx and dy represents de difference between x2 - x1 and y2 - 1
 * respectively.
 */
static void	draw_line(t_point a, t_point b, mlx_image_t* img)
{
	int	dx;
	int dy;

	dx = b.x - a.x;
	dy = b.y - a.y;
	if (abs(dx) > abs(dy))
		small_slope(dx, dy, &a, img);
	else
		big_slope(dx, dy, &a, img);
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
	x += WIDTH / 2;
	y += HEIGHT / 2;
	mlx_put_pixel(img, x, y, color);
}

