/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 00:04:20 by dyunta            #+#    #+#             */
/*   Updated: 2024/08/03 15:23:55 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/* Prints an unsigned integer (n) in a given base specified by the character
array base. It calculates and returns the length of the printed number.
It does this by recursively dividing n by the length of the base and printing
the remainder as a digit from the base until the quotient becomes zero.
The length of the printed number is incremented with each digit printed,
and the total length is returned.
Example:	ft_putnbr_base(16, "01"); */

int	ft_putnbr_base(unsigned int n, char *base)
{
	int	len;

	len = 1;
	if (n / ft_strlen(base) > 0)
		len += ft_putnbr_base(n / ft_strlen(base), base);
	ft_putchar(base[n % ft_strlen(base)]);
	return (len);
}
