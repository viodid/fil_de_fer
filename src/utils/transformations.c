/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:06:52 by dyunta            #+#    #+#             */
/*   Updated: 2024/07/25 20:33:31 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static void	free_split(char** split);

void	apply_transformations(t_point* a, t_point* b)
{
	int tmp;

	a->x *= ZOOM;
	a->y *= ZOOM;
	a->z *= ZOOM;
	b->x *= ZOOM;
	b->y *= ZOOM;
	b->z *= ZOOM;

	tmp = a->x;
	a->x = (int)((tmp - a->y) * cos(0.523599));
	a->y = (int)((tmp + a->y) * sin(0.523599) - a->z);

	tmp = b->x;
	b->x = (int)((tmp - b->y) * cos(0.523599));
	b->y = (int)((tmp + b->y) * sin(0.523599) - b->z);
}

void	set_z_axis(t_point* a, t_point* b, t_fdf* fdf)
{
	char***	map;
	int 	x;
	int 	y;
	char**	split;

	map = fdf->map;
	x = a->x;
	y = a->y;
	split = ft_split(map[y][x], ',');
	a->z = ft_atoi(split[0]);
	free_split(split);
	x = b->x;
	y = b->y;
	split = ft_split(map[y][x], ',');
	b->z = ft_atoi(split[0]);
	free_split(split);
}

static void	free_split(char** split)
{
	int i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}
