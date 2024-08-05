/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 09:37:46 by dyunta            #+#    #+#             */
/*   Updated: 2024/08/05 23:43:43 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	reset_map(t_projection *projection);

void	hooks(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *) param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_I))
		reset_map(fdf->projection);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fdf->mlx);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT))
		fdf->projection->x_offset -= 5;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT))
		fdf->projection->x_offset += 5;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_DOWN))
		fdf->projection->y_offset += 5;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP))
		fdf->projection->y_offset -= 5;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_EQUAL))
		scroll_hook(0, 1, param);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_MINUS))
		scroll_hook(0, -1, param);
}

static void	reset_map(t_projection *projection)
{
	projection->alpha = 0.5 / 2;
	projection->beta = 0.5;
	projection->x_rotate = 0;
	projection->y_rotate = 0;
	projection->z_rotate = 0;
	projection->x_offset = WIDTH / 2;
	projection->y_offset = HEIGHT / 2;
	projection->zoom = 2;
	projection->z_scale = 2;
}

void	scroll_hook(double x_delta, double y_delta, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (y_delta > 0)
		fdf->projection->zoom *= 1.02;
	else if (y_delta < 0 && fdf->projection->zoom * 0.98 > 0)
		fdf->projection->zoom *= 0.98;
	x_delta++;
}

void	rotation_hooks(void *param)
{
	t_fdf	*fdf;
	int 	sign;

	fdf = (t_fdf *)param;
	sign = 0;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_COMMA))
		sign = -1;
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_PERIOD))
		sign = 1;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_Q))
		fdf->projection->alpha += sign * 0.03;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_W))
		fdf->projection->beta += sign * 0.03;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_S))
		fdf->projection->z_scale += sign * 0.1;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_X))
		fdf->projection->x_rotate += sign * 0.02;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_Y))
		fdf->projection->y_rotate += sign * 0.02;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_Z))
		fdf->projection->z_rotate += sign * 0.02;
}
