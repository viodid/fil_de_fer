/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 00:04:15 by dyunta            #+#    #+#             */
/*   Updated: 2023/10/05 20:23:48 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_subs(const char *haystack, const char *needle, size_t len);

/*
	The strnstr() function locates the first occurrence of the null-termi-
	nated string needle in the string haystack, where not more than len characters
	are searched.  Characters that appear after a `\0' character are not
	searched.

	If needle is an empty string, haystack is returned; if needle occurs nowhere
	in haystack, NULL is returned; otherwise a pointer to the first character of
	the first occurrence of needle in haystack is returned.
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (!*needle)
		return ((char *)haystack);
	while (len-- && *haystack)
	{
		if (*haystack == *needle)
		{
			if (check_subs(haystack, needle, len + 1))
				return ((char *)haystack);
		}
		haystack++;
	}
	return (0);
}

static int	check_subs(const char *haystack, const char *needle, size_t len)
{
	while (len-- && *needle)
	{
		if (*needle++ != *haystack++)
			return (0);
	}
	if (*needle)
		return (0);
	return (1);
}
