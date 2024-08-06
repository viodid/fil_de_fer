/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:06:52 by dyunta            #+#    #+#             */
/*   Updated: 2024/08/06 12:47:09 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	rotate_x(double *y, double *z, double x_angle);
static void	rotate_y(double *x, double *z, double y_angle);
static void	rotate_z(double *x, double *y, double z_angle);

t_point	apply_transformations(int x, int y, t_fdf *fdf)
{
	t_point			point;
	t_point_double	point_d;
	double			temp;
	double			x_offset;
	double			y_offset;

	x_offset = (fdf->map->width - 1) * fdf->projection->interval / 2;
	y_offset = (fdf->map->height - 1) * fdf->projection->interval / 2;
	point_d.x = x * (fdf->projection->interval) - x_offset;
	point_d.y = y * (fdf->projection->interval) - y_offset;
	point_d.z = fdf->map->map_points[y][x].z * (int)fdf->projection->z_scale;
	rotate_z(&point_d.x, &point_d.y, fdf->projection->z_rotate);
	rotate_x(&point_d.y, &point_d.z, fdf->projection->x_rotate);
	rotate_y(&point_d.x, &point_d.z, fdf->projection->y_rotate);
	temp = point_d.x;
	point.x = (int)((point_d.x * fdf->projection->zoom - point_d.y
				* fdf->projection->zoom)
			* cos(fdf->projection->alpha) + fdf->projection->x_offset);
	point.y = (int)(-point_d.z * fdf->projection->zoom
			+ (temp * fdf->projection->zoom + point_d.y * fdf->projection->zoom)
			* sin(fdf->projection->beta) + fdf->projection->y_offset);
	point.color = fdf->map->map_points[y][x].color;
	return (point);
}

static void	rotate_x(double *y, double *z, double x_angle)
{
	double	tmp;

	tmp = *y;
	*y = tmp * cos(x_angle) + *z * sin(x_angle);
	*z = tmp * -sin(x_angle) + *z * cos(x_angle);
}

static void	rotate_y(double *x, double *z, double y_angle)
{
	double	tmp;

	tmp = *x;
	*x = tmp * cos(y_angle) + *z * sin(y_angle);
	*z = tmp * -sin(y_angle) + *z * cos(y_angle);
}

static void	rotate_z(double *x, double *y, double z_angle)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = *x;
	tmp_y = *y;
	*x = tmp_x * cos(z_angle) - tmp_y * sin(z_angle);
	*y = tmp_x * sin(z_angle) + tmp_y * cos(z_angle);
}
