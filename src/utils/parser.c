/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:27:22 by dyunta            #+#    #+#             */
/*   Updated: 2024/07/06 20:43:22 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static int	get_map_width(const char* file_path);
static	int	get_map_height(const char* file_path);
static int**	matrix_allocation(int x, int y);


int	**parser(const char *file_path)
{
	int**	map;

	map = matrix_allocation(get_map_width(file_path), get_map_height(file_path));
	return (map);
}


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
 * Returns the total number of 'items' in the line.
 * An item is any character divided by whitespace/s.
 * There is always items + 1 items in the line.
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
	return (len + 1);
}

static	int	get_map_height(const char* file_path)
{
	int		y;
	int		fd;
	char*	line;

	fd = open_file(file_path);
	line = get_next_line(fd);
	y = 1;
	while (line)
	{
		if (line[0])
			y++;
		line = get_next_line(fd);
	}
	close_file(fd);
	return (y);
}
