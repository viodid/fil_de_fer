/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:06:52 by dyunta            #+#    #+#             */
/*   Updated: 2024/08/03 19:01:31 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static int	get_z_axis(int x, int y, char ***map);
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
//	point.z = get_z_axis(x, y, fdf->map->arr) * (int)fdf->projection->z_scale;
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

static int	get_z_axis(int x, int y, char ***map)
{
	int		z;
	char	**split;

	split = ft_split(map[y][x], ',');
	z = ft_atoi(split[0]);
	free_split(split);
	return (z);
}
