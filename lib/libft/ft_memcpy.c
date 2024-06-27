/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 00:04:15 by dyunta            #+#    #+#             */
/*   Updated: 2023/10/05 19:37:19 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Copies n bytes from memory area src to memory area dst.
	The memory areas must not overlap.
*/
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)dst;
	while (n--)
	{
		if (!dst && !src)
			return (dst);
		*ptr++ = *(unsigned char *)src++;
	}
	return (dst);
}
