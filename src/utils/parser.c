/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:27:22 by dyunta            #+#    #+#             */
/*   Updated: 2024/07/21 18:46:13 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static char***	parser(const char* file_path);

t_fdf*	fdf_struct_generator(const char *file_path)
{
	t_fdf*	fdf_struct;

	fdf_struct = (t_fdf*)malloc(sizeof(t_fdf));
	if (fdf_struct == NULL)
		exit(EXIT_FAILURE);
	fdf_struct->map = parser(file_path);
	fdf_struct->height = get_map_height(file_path);
	fdf_struct->width = get_map_width(fdf_struct->map);
	return (fdf_struct);
}

/*
 * TODO: write docstrings
*/
static char***	parser(const char* file_path)
{
	int		fd;
	int		i;
	char*	line;
	char***	map;

	map = (char ***)malloc(sizeof(char **) * (get_map_height(file_path) + 1));
	if (map == NULL)
		exit(EXIT_FAILURE);
	fd = open_file(file_path);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		map[i++] = ft_split(line, ' ');
		free(line);
		line = get_next_line(fd);
	}
	map[i] = NULL;
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
