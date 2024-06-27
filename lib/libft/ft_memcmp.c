/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 00:04:15 by dyunta            #+#    #+#             */
/*   Updated: 2023/10/03 19:40:13 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://stackoverflow.com/questions/11598361/why-a-pointer-1-add-4-actually

#include "libft.h"

/*
	Compares byte string s1 against byte string s2.
	Both strings are assumed to be n bytes long.
*/
int	ft_memcmp(const void *b1, const void *b2, size_t len)
{
	while (len--)
	{
		if (*(unsigned char *)b1 != *(unsigned char *)b2)
			return (*(unsigned char *)b1 - *(unsigned char *)b2);
		b1++;
		b2++;
	}
	return (0);
}
