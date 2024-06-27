/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 00:04:15 by dyunta            #+#    #+#             */
/*   Updated: 2023/10/03 19:22:55 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Writes n zeroed bytes to the string s.
	If n is zero, bzero() does nothing.
*/
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
