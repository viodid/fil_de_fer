/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:00:44 by dyunta            #+#    #+#             */
/*   Updated: 2024/02/19 22:29:45 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/*   Locates the first occurrence of c (converted to a
    char) in the string pointed to by s.  The terminating null character is
    considered part of the string; therefore if c is `\0', the functions
    locate the terminating `\0'.
    The functions strchr() and strrchr() return a pointer to the located
    character, or NULL if the character does not appear in the string.	*/

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return (&((char *)s)[i]);
		i++;
	}
	if (s[i] == (char) c)
		return (&((char *)s)[i]);
	return (0);
}
