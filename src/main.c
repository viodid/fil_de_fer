/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:13:49 by dyunta            #+#    #+#             */
/*   Updated: 2024/03/15 21:15:40 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_data;

void	my_mlxpixel_put(t_data *data, int x, int y, int color);
void	draw_circle(t_data *data);

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hey there.");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);

	my_mlxpixel_put(&img, 5, 5, 0x00FFFF00);
	draw_circle(&img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);

	return (0);
}

void	draw_circle(t_data *data)
{
	int	i;

	i = 100;
	while (i++ < 1000)
	{
		my_mlxpixel_put(data, 500, i, 0x00FFFF00);
		my_mlxpixel_put(data, 1000, i, 0xFFFFFF00);
	}
}

void	my_mlxpixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));

	*(unsigned int *)dst = color;
}