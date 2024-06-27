/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 00:04:15 by dyunta            #+#    #+#             */
/*   Updated: 2023/10/03 19:23:27 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Allocates memory for an array of nmemb elements of size bytes each and
	returns a pointer to the allocated memory. The memory is set to zero.
	If nmemb or size is 0, then calloc() returns either NULL, or a unique
	pointer value that can later be successfully passed to free().
*/
void	*ft_calloc(size_t number, size_t size)
{
	void	*ptr;

	ptr = malloc(number * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, number * size);
	return (ptr);
}
