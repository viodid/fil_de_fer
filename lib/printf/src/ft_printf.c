/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 00:04:20 by dyunta            #+#    #+#             */
/*   Updated: 2024/02/19 22:28:18 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_char_str_cases(va_list args, const char format)
{
	char	*str;

	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
	{
		str = va_arg(args, char *);
		if (str == NULL)
			return (ft_putstr("(null)"));
		return (ft_putstr(str));
	}
	return (-1);
}

static int	ft_other_cases(va_list args, const char format)
{
	unsigned long	ptr;

	if (format == 'p')
	{
		ptr = (unsigned long)va_arg(args, void *);
		if (ptr == 0)
			return (ft_putstr("0x0"));
		ft_putstr("0x");
		return (ft_puthex(ptr, 'x') + 2);
	}
	else if (format == 'd' || format == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	else if (format == 'u')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789"));
	else if (format == 'x' || format == 'X')
		return (ft_puthex(va_arg(args, unsigned int), format));
	else if (format == '%')
		return (ft_putchar('%'));
	return (-1);
}

static int	ft_allcases(va_list args, const char format)
{
	int		result;

	result = ft_char_str_cases(args, format);
	if (result != -1)
		return (result);
	return (ft_other_cases(args, format));
}

/*
• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.L
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.
*/

// BONUS
/* Field minimum width:

• %- Left-justify within the given field width; Right justification is the
default (see width sub-specifier).

• %0 Left-pads the number with zeroes (0) instead of spaces when padding is
specified (see width sub-specifier).

• %. For integer specifiers (d, i, u, x, X) − precision specifies
the minimum number of digits to be written. If the value to be written is
shorter than this number, the result is padded with leading zeros. The value
is not truncated even if the result is longer. A precision of 0 means that no
character is written for the value 0. For s − this is the maximum number of
characters to be printed. For c type − it has no effect. 
By default all characters are printed until the ending null character is
encountered. If The period is specified without an explicit value for
precision, 0 is assumed.
*/

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%' && ft_strchr("cspdiuxX%", s[i + 1]) != NULL)
		{
			length += ft_allcases(args, s[i + 1]);
			i++;
		}
		else
			length += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (length);
}
