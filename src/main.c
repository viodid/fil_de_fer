/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:13:49 by dyunta            #+#    #+#             */
/*   Updated: 2024/07/28 18:35:56 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	ft_error(void);
static void	ft_hook(void* param);

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
	fdf_init(&map, &fdf);
	projection_init(&projection, &fdf);

//	 mlx_set_setting(MLX_MAXIMIZED, true);

	draw_map(&fdf);

//	 mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(fdf.mlx);
	mlx_terminate(fdf.mlx);
	free_map(map.arr);

	return (EXIT_SUCCESS);
}

static void	ft_hook(void* param)
{
	const mlx_t* mlx = param;
	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}
