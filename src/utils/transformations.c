/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:06:52 by dyunta            #+#    #+#             */
/*   Updated: 2024/07/27 13:01:49 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static void	free_split(char** split);

t_point apply_transformations(int x, int y, t_fdf *fdf)
{
	int tmp;
	t_point point;

	point.x = x * ZOOM;
	point.y = y * ZOOM;
	point.z = get_z_axis(x, y, fdf->map) * ZOOM;

	return (point);
}

int get_z_axis(int x, int y, char ***map)
{
	int 	z;
	char**	split;

	split = ft_split(map[y][x], ',');
	z = ft_atoi(split[0]);
	free_split(split);
	return (z);
}

static void	free_split(char** split)
{
	int i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}
