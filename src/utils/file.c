/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 19:51:33 by dyunta            #+#    #+#             */
/*   Updated: 2024/08/05 12:37:41 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

int	open_file(const char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		perror("open file error");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	close_file(int fd)
{
	int	result;

	result = close(fd);
	if (result == -1)
	{
		perror("Error closing file");
		exit(EXIT_FAILURE);
	}
}
