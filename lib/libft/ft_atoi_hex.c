/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 09:39:04 by dyunta            #+#    #+#             */
/*   Updated: 2024/08/04 10:27:35 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_hex(char *str)
{
	int		output;
	char	*hex;
	int 	i;
	int 	offset;

	output = 0;
	offset = 0;
	hex = "0123456789ABCDEF";
	if (ft_strncmp(str, "0x", 3) != 0)
		offset = 2;
	while (str[offset])
	{
		i = 0;
		while (hex[i])
		{
			if (hex[i] == ft_toupper(str[offset]))
				output = (output * 16) + i;
			i++;
		}
		offset++;
	}
	return (output);
}
