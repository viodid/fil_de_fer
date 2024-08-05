/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:57:34 by dyunta            #+#    #+#             */
/*   Updated: 2024/08/05 23:10:04 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

/*
 * Returns the total number of elements that exist in the first row
 * of a 2-dimensional array.
 */
int	get_map_width(const char *file_path)
{
	int		len;
	int		fd;
	char	*line;
	char	**split;

	fd = open_file(file_path);
	line = get_next_line(fd);
	split = ft_split(line, ' ');
	len = get_map_width_line(split);
	free_split(split);
	free(line);
	return (len);
}

/*
 * NOTE: this function does NOT free the allocated memory.
 */
int	get_map_width_line(char **str_arr)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str_arr[i])
	{
		if (str_arr[i][0] != '\n')
			len++;
		i++;
	}
	return (len);
}

/*
 * Returns the height (y-axis) of the input map_points file.
*/
int	get_map_height(const char *file_path)
{
	int		y;
	int		fd;
	char	*line;

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

void	reset_canvas(mlx_image_t *img)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			mlx_put_pixel(img, x, y, BACKGROUND);
			x++;
		}
		y++;
	}
}
