/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 00:04:15 by dyunta            #+#    #+#             */
/*   Updated: 2024/08/03 18:30:26 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Compares the two strings s1 and s2. It returns an integer less than,
	equal to, or greater than zero if s1 is found, respectively, to be less
	than, equal, or be greater than s2.
*/
int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && i < len)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i == len)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
