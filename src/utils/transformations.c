/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:06:52 by dyunta            #+#    #+#             */
/*   Updated: 2024/07/28 21:01:30 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static int get_z_axis(int x, int y, char ***map);
static void	rotate_x(int* y, int* z, double x_angle);
static void	rotate_y(int* x, int* z, double y_angle);
static void	rotate_z(int* x, int* y, double z_angle);

t_point apply_transformations(int x, int y, t_fdf *fdf)
{
	t_point point;

	point.x = x * fdf->projection->zoom;
	point.y = y * fdf->projection->zoom;
	point.z = get_z_axis(x, y, fdf->map->arr);
	point.z *= fdf->projection->zoom / fdf->projection->z_height;

	point.x -= (fdf->map->width * fdf->projection->zoom) / 2;
	point.y -= (fdf->map->height * fdf->projection->zoom) / 2;

	rotate_x(&point.y, &point.z, fdf->projection->x_angle);
	rotate_y(&point.x, &point.z, fdf->projection->y_angle);
	rotate_z(&point.x, &point.y, fdf->projection->z_angle);

	point.x += WIDTH / 2 + fdf->projection->x_offset;
	point.y += (HEIGHT + fdf->map->height / 2 * fdf->projection->zoom) / 2
			+ fdf->projection->y_offset;

	return (point);
}

static void	rotate_x(int* y, int* z, double x_angle)
{
	int 	tmp;

	tmp = *y;
	*y = tmp * cos(x_angle) + *z * sin(x_angle);
	*z = tmp * -sin(x_angle) + *z * cos(x_angle);
}

static void	rotate_y(int* x, int* z, double y_angle)
{
	int 	tmp;

	tmp = *x;
	*x = tmp * cos(y_angle) + *z * sin(y_angle);
	*z = tmp * -sin(y_angle) + *z * cos(y_angle);
}

static void	rotate_z(int* x, int* y, double z_angle)
{
	int 	tmp_x;
	int 	tmp_y;

	tmp_x = *y;
	tmp_y = *y;
	*x = tmp_x * cos(z_angle) - tmp_y * sin(z_angle);
	*y = tmp_x * sin(z_angle) + tmp_y * cos(z_angle);
}

static int get_z_axis(int x, int y, char ***map)
{
	int 	z;
	char**	split;

	split = ft_split(map[y][x], ',');
	z = ft_atoi(split[0]);
	free_split(split);
	return (z);
}

void	free_split(char** split)
{
	int i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}
