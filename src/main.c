/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:13:49 by dyunta            #+#    #+#             */
/*   Updated: 2024/03/16 18:24:16 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int 	width;
	int 	height;
}	t_data;

void	my_mlxpixel_put(t_data *data, int x, int y, int color);
void	draw_circle(t_data *data);
int	square_root(int n);


int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	img.width = 1920;
	img.height = 1080;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, img.width, img.height, "Hey there.");
	img.img = mlx_new_image(mlx, img.width, img.height);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);

	my_mlxpixel_put(&img, 5, 5, 0x00FFFF00);
	draw_circle(&img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);

//	int	i = 0;
//	while (i < 100)
//	{
//		printf("sqroot: %d ~= %d\n", i, square_root(i));
//		i++;
//	}

	return (0);
}

void	draw_circle(t_data *data)
{
	int	i;
	int y;

	i = 0;
	y = 0;
	while (i++ < data->width)
	{
		while (y++ < data->height)
		{

		}
	}
}

//int	get_radius(int x, int y)

int	square_root(int n)
{
	int	i = 0;
	while (i < n/2)
	{
		if (i * i >= n)
			return (i);
		i++;
	}
	return (i);
}

void	my_mlxpixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));

	*(unsigned int *)dst = color;
}