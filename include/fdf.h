/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:12:30 by dyunta            #+#    #+#             */
/*   Updated: 2024/07/20 17:43:06 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "../MLX42/include/MLX42/MLX42.h"
#include "../lib/libft/libft.h"
#include "../lib/GNL/get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

typedef struct s_fdf
{
	int		height;
	int		width;
	char***	map;
}	t_fdf;

typedef struct s_point
{
	int	x;
	int y;
} t_point;

int		open_file(const char *file_pat);
void    close_file(const int fd);
void	args_sanitizer(int argc, char *argv[]);
int		get_map_height(const char* file_path);
int		get_map_width(char*** map);
char***	parser(const char* file_path);
t_fdf*	fdf_struct_generator(const char *file_path);
void	free_map(char*** map);

#endif