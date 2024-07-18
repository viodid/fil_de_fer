/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:27:22 by dyunta            #+#    #+#             */
/*   Updated: 2024/07/18 18:27:42 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	args_sanitizer(int argc, char *argv[])
{
	char	*file_path;
	size_t	path_len;

	file_path = NULL;
	if (argc > 2)
	{
		errno = E2BIG;
		return ;
	}
	if (argc < 2)
	{
		errno = EOPNOTSUPP;
		return ;
	}
	file_path = argv[1];
	path_len = ft_strlen(file_path);
	if (file_path[path_len - 1] != 'f' || file_path[path_len - 2] != 'd'
		|| file_path[path_len - 3] != 'f')
		errno = ENOENT;
}

/*
 * TODO: write docstrings
*/
char***	parser(const char* file_path)
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

t_fdf*	fdf_struct_generator(const char *file_path)
{
	t_fdf*	fdf_struct;

	fdf_struct = (t_fdf*)malloc(sizeof(t_fdf));
	if (fdf_struct == NULL)
		exit(EXIT_FAILURE);
	fdf_struct->map = parser(file_path);
	fdf_struct->height = get_map_height(file_path);
	fdf_struct->width = get_map_width(file_path);
	return (fdf_struct);
}
