/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 20:35:49 by dyunta            #+#    #+#             */
/*   Updated: 2023/11/29 21:03:14 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *  Tests for any printing character, including space (' ').  The value of the
 *  argument must be representable as an unsigned char or the value of EOF.
 *  Returns zero if the character tests false and returns non-zero if the
 *  character tests true.
 */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
