/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:29:59 by dyunta            #+#    #+#             */
/*   Updated: 2023/11/02 20:30:25 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Takes a pointer to the start of a str populated  with numbers and outputs
	the number as an integer.
	It sets the errno to 1 when the number is larger than INT_MAX or when
 	the char does not represent a number.
*/
int	ft_strtol(const char *s)
{
	int		sign;
	int		number;

	sign = 1;
	number = 0;
	if (*s == '-')
	{
		sign *= -1;
		s++;
	}
	while (*s)
	{
		if ((*s < '0' || *s > '9' || *s == '\n')
			|| (number > (INT_MAX - (*s - '0')) / 10))
		{
			errno = 1;
			return (0);
		}
		number *= 10;
		number += (int)(*s++ - '0');
	}
	return (number * sign);
}
