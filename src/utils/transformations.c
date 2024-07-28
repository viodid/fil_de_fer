/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:06:52 by dyunta            #+#    #+#             */
/*   Updated: 2024/07/28 19:14:34 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static int get_z_axis(int x, int y, char ***map);
static void	rotate_x(int* y, int* z);
static void	rotate_y(int* x, int* z);
static void	rotate_z(int* x, int* y);

t_point apply_transformations(int x, int y, t_fdf *fdf)
{
	t_point point;

	point.x = x * ZOOM;
	point.y = y * ZOOM;
	point.z = get_z_axis(x, y, fdf->map->arr) * ZOOM;

//	rotate_x(&point.y, &point.z);
//	rotate_y(&point.x, &point.z);
//	rotate_z(&point.x, &point.y);

	return (point);
}

static void	rotate_x(int* y, int* z)
{
	int 	tmp;
	double 	x_angle;

	tmp = *y;
	x_angle = -0.615472907;
	*y = tmp * cos(x_angle) + *z * sin(x_angle);
	*z = tmp * -sin(x_angle) + *z * cos(x_angle);
}

static void	rotate_y(int* x, int* z)
{
	int 	tmp;
	double 	y_angle;

	tmp = *x;
	y_angle = -0.523599;
	*x = tmp * cos(y_angle) + *z * sin(y_angle);
	*z = tmp * -sin(y_angle) + *z * cos(y_angle);
}

static void	rotate_z(int* x, int* y)
{
	int 	tmp_x;
	int 	tmp_y;
	double 	z_angle;

	tmp_x = *y;
	tmp_y = *y;
	z_angle = 0.615472907;
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
