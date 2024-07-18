/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:27:22 by dyunta            #+#    #+#             */
/*   Updated: 2024/07/18 18:17:21 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static int	get_map_width(const char* file_path);
int	get_map_height(const char* file_path);
static int**	matrix_allocation(int x, int y);

/*
 * Parses the map the points 'file_path' and returns a two-dimensional array
 * containing all the map elements.
*/
int**	old_parser(const char *file_path)
{
	int**	map;
	int		fd;
	int		i;
	int		j;
	char*	line;

	map = matrix_allocation(get_map_width(file_path), get_map_height(file_path));
	fd = open_file(file_path);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		j = 0;
		while(line[j])
		{
			map[i][j] = (int)line[j++];
			if (line[j] != ' ')
				map[i][j] = (int)line[i++];

		}
		line = get_next_line(fd);
	}
	close_file(fd);
	return (map);
}

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
 * of the map.
 * An element is any character divided by whitespace/s.
 * There is always items + 1 items in the line.
 * Elements are multiplied by 2 to allocate space for number and color.
 */
static int	get_map_width(const char* file_path)
{
	int		len;
	int		i;
	int		fd;
	char*	line;

	len = 0;
	i = 0;
	fd = open_file(file_path);
	line = get_next_line(fd);
	while (line[i])
	{
		if (line[i++] == ' ')
		{
			len++;
			while (line[i++] == ' ')
				i++;
		}
		i++;
	}
	close_file(fd);
	if (len == 0)
		return (0);
	return ((len + 1) * 2);
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
