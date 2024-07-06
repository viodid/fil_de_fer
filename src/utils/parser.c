/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:27:22 by dyunta            #+#    #+#             */
/*   Updated: 2024/07/06 17:53:48 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static int	line_len(const char *line);

int**	parser(int argc, const char *file_path)
{
	int		fd;
	char	*line;
	int		**map;

	fd = open(file_path, O_RDONLY);
	line = get_next_line(fd);
	map = malloc(sizeof(char) * ft_strlen(line));
	if (!map)
	{
		errno = ENOMEM;
		perror("Error message");
		exit(EXIT_FAILURE);
	}
	while (line)
	{
		line = get_next_line(fd);
	}
	return map;
}

int	**parse_file_to_matrix(const char *file_path)
{
	int		fd;
	int		**map;
	int 	height;
	char	*line;

	fd = open(file_path, O_RDONLY);
	line = get_next_line(fd);
	int test_line_len = line_len(line);
	map = (int **)malloc(sizeof(int *) * line_len(line));
	if (map == NULL)
	{
		errno = ENOMEM;
		perror("Memory allocation");
		exit(EXIT_FAILURE);
	}
	height = 0;
	while (line)
	{
		line = get_next_line(fd);
		height++;
	}
	if (close(fd))
	{
		perror("Close file error");
		exit(EXIT_FAILURE);
	}
	fd = open(file_path, O_RDONLY);
	line = get_next_line(fd);
	return map;
}

/*
 * Custom line length function. Returns the total number of 'items'
 * in the line. An item is any character divided by whitespace/s.
 * There is always items + 1 items in the line.
 */
static int	line_len(const char *line)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
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
	if (len == 0)
		return (0);
	return (len + 1);
}

