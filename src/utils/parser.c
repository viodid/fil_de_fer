/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:27:22 by dyunta            #+#    #+#             */
/*   Updated: 2024/07/03 20:29:55 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	args_sanitizer(int argc, char *argv[])
{
	char	*file_path;
	size_t	path_len;

	file_path = NULL;
	if (argc > 2)
		errno = E2BIG;
	else if (argc < 2)
		errno = EOPNOTSUPP;
	file_path = argv[1];
	path_len = ft_strlen(file_path);
	if (ft_strncmp(".fdf", file_path, path_len) != 0)
		errno = ENOENT;
}

char	**parser(int argc, const char *file_path)
{
	int		fd;
	char	*line;
	char	**map;

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
	return "hey";
}
