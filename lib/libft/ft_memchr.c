/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 00:04:15 by dyunta            #+#    #+#             */
/*   Updated: 2023/10/03 19:35:43 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	The memchr() function locates the first occurrence of c (converted to an
	unsigned char) in string b.

	The memchr() function returns a pointer to the byte located, or NULL if no
	such byte exists within n bytes.
*/
void	*ft_memchr(const void *b, int c, size_t len)
{
	while (len--)
	{
		if (*(unsigned char *)b == (unsigned char)c)
			return ((void *)b);
		b++;
	}
	return (0);
}
