/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:39:16 by dyunta            #+#    #+#             */
/*   Updated: 2024/08/05 14:51:13 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

int	bresenham_utils(int *coordinate, int e, int dx, int dy)
{
	e += 2 * abs(dx) - 2 * abs(dy);
	if (dx >= 0)
		*coordinate = *coordinate + 1;
	else
		*coordinate = *coordinate - 1;
	return (e);
}
