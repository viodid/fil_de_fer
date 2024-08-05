/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:00:48 by dyunta            #+#    #+#             */
/*   Updated: 2024/08/05 15:01:26 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	args_sanitizer(int argc, char *argv[])
{
	char	*file_path;
	char	*line;
	size_t	path_len;

	file_path = NULL;
	if (argc != 2)
	{
		ft_putstr_fd("Wrong number of arguments\n"
			"Usage: ./fdf [map_points.fdf]\n", 2);
		exit(EXIT_FAILURE);
	}
	file_path = argv[1];
	path_len = ft_strlen(file_path);
	if (file_path[path_len - 1] != 'f' || file_path[path_len - 2] != 'd'
		|| file_path[path_len - 3] != 'f')
		errno = ENOENT;
	line = get_next_line(open_file(file_path));
	if (line == NULL)
	{
		ft_putstr_fd("Empty file\n", 2);
		exit(EXIT_FAILURE);
	}
	free(line);
}
