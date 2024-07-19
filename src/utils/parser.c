/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:27:22 by dyunta            #+#    #+#             */
/*   Updated: 2024/07/19 20:21:02 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"


/*
 * Allocates enough memory to store all the elements in a 2-dimensional
 * array denoted by x and y.
*/
static int**	matrix_allocation(int x, int y)
{
	int	i;
	int**	map;

	map = (int **)malloc(sizeof(int *) * x);
	if (map == NULL)
	{
		errno = ENOMEM;
		perror("Memory allocation");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (!errno && i < x)
	{
		map[i] = (int *)malloc(sizeof(int) * y);
		if (map[i] == NULL)
			errno = ENOMEM;
		i++;
	}
	if (errno)
	{
		x = 0;
		perror("Memory allocation error.");
		while (map[x])
			free(map[x++]);
		free(map);
		exit(EXIT_FAILURE);
	}
	return (map);
}

/*
 * Returns the total number of elements that exist in the first row
 * of a 2-dimensional array.
 */
int	get_map_width(char*** map)
{
	int	i;
	int len;

	i = 0;
	len = 0;
	while (map[0][i])
	{
		if (map[0][i][0] != '\n')
			len++;
		i++;
	}
	return (len);
}

/*
 * Returns the height (y-axis) of the input map file.
*/
int	get_map_height(const char* file_path)
{
	int		y;
	int		fd;
	char*	line;

	fd = open_file(file_path);
	line = get_next_line(fd);
	y = 0;
	while (line)
	{
		if (line[0])
			y++;
		free(line);
		line = get_next_line(fd);
	}
	close_file(fd);
	return (y);
}
