/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:27:22 by dyunta            #+#    #+#             */
/*   Updated: 2024/06/27 18:42:37 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	args_sanitizer(int argc, char *argv[])
{
	char	*file_path;
	int		path_len;

	file_path = NULL;
	if (argc > 2)
		errno = 7;
	else if (argc < 2)
		errno = 95;
	file_path = argv[1];
	path_len = ft_strlen(file_path);
	if (ft_strncmp(".fdf", file_path, path_len) != 0)
		errno = 2;
}

char	**parser(int argc, char *argv[], char **map)
{
}
