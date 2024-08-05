/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:13:49 by dyunta            #+#    #+#             */
/*   Updated: 2024/08/05 14:27:27 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argc, char *argv[])
{
	t_fdf			fdf;
	t_map			map;
	t_projection	projection;

	args_sanitizer(argc, argv);
	if (errno)
	{
		perror("Error message");
		exit(EXIT_FAILURE);
	}
	map_init(argv[1], &map);
	projection_init(&projection, &map);
	fdf_init(&map, &projection, &fdf);
	draw_map(&fdf);
	mlx_loop_hook(fdf.mlx, &hook_window, &fdf);
	mlx_loop(fdf.mlx);
	mlx_terminate(fdf.mlx);
	free_map(&map);
	return (EXIT_SUCCESS);
}
