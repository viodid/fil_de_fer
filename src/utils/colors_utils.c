/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 21:34:54 by dyunta            #+#    #+#             */
/*   Updated: 2024/08/04 21:49:28 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/fdf.h"

unsigned int	compute_color(unsigned int color_a, unsigned int color_b, double per, int bitshift)
{
	unsigned int	output_color;
	color_a = (color_a >> bitshift) & 0xFF;
	color_b = (color_b >> bitshift) & 0xFF;
	if ((color_a) == (color_b))
		 return (color_a);
	if (color_a < color_b)
		output_color = color_a + ((unsigned int)((color_b - color_a) * per));
	else
		output_color = color_a - ((unsigned int)((color_a - color_b) * per));
	if (output_color > 0xFF)
		output_color = 0xFF;
	return (output_color);
}
