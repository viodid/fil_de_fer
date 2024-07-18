/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:13:49 by dyunta            #+#    #+#             */
/*   Updated: 2024/07/18 18:35:48 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#define WIDTH 256
#define HEIGHT 256

static void	ft_error(void);
static void	ft_hook(void* param);

int	main(int argc, char *argv[])
{
	t_fdf*	fdf_struct;

	fdf_struct = NULL;
	args_sanitizer(argc, argv);
	if (errno)
	{
		perror("Error message");
		exit(EXIT_FAILURE);
	}
	// TODO: pyramid map gives 0 width size, check get_map_width func
	fdf_struct = fdf_struct_generator(argv[1]);
	free_map(map);

	// mlx_set_setting(MLX_MAXIMIZED, true);
	// mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
	// if (!mlx)
	// 	ft_error();

	// mlx_image_t*	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	// if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
	// 	ft_error();

	// mlx_put_pixel(img, 0, 0, 0xFF0000FF);

	// mlx_loop_hook(mlx, ft_hook, mlx);
	// mlx_loop(mlx);
	// mlx_terminate(mlx);

	return (EXIT_SUCCESS);
}

static void	ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

static void	ft_hook(void* param)
{
	const mlx_t* mlx = param;
	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}
