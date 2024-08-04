/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:06:52 by dyunta            #+#    #+#             */
/*   Updated: 2024/08/04 10:00:46 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	rotate_x(int *y, int *z, double x_angle);
static void	rotate_y(int *x, int *z, double y_angle);
static void	rotate_z(int *x, int *y, double z_angle);

t_point	apply_transformations(int x, int y, t_fdf *fdf)
{
	t_point	point;
	int		temp;
	double	x_offset;
	double	y_offset;

	x_offset = (fdf->map->width - 1) * fdf->projection->interval / 2;
	y_offset = (fdf->map->height - 1) * fdf->projection->interval / 2;
	point.x = x * (fdf->projection->interval) - x_offset;
	point.y = y * (fdf->projection->interval) - y_offset;
	point.z = fdf->map->map_points[y][x].z * (int)fdf->projection->z_scale;
	rotate_z(&point.x, &point.y, fdf->projection->z_rotate);
	rotate_x(&point.y, &point.z, fdf->projection->x_rotate);
	rotate_y(&point.x, &point.z, fdf->projection->y_rotate);
	temp = point.x;
	point.x = (int)((point.x * fdf->projection->zoom - point.y
				* fdf->projection->zoom)
			* cos(fdf->projection->alpha) + fdf->projection->x_offset);
	point.y = (int)(-point.z * fdf->projection->zoom
			+ (temp * fdf->projection->zoom + point.y * fdf->projection->zoom)
			* sin(fdf->projection->beta) + fdf->projection->y_offset);
	point.color = fdf->map->map_points[y][x].color;
	return (point);
}

static void	rotate_x(int *y, int *z, double x_angle)
{
	int	tmp;

	tmp = *y;
	*y = tmp * cos(x_angle) + *z * sin(x_angle);
	*z = tmp * -sin(x_angle) + *z * cos(x_angle);
}

static void	rotate_y(int *x, int *z, double y_angle)
{
	int	tmp;

	tmp = *x;
	*x = tmp * cos(y_angle) + *z * sin(y_angle);
	*z = tmp * -sin(y_angle) + *z * cos(y_angle);
}

static void	rotate_z(int *x, int *y, double z_angle)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = *x;
	tmp_y = *y;
	*x = tmp_x * cos(z_angle) - tmp_y * sin(z_angle);
	*y = tmp_x * sin(z_angle) + tmp_y * cos(z_angle);
}
