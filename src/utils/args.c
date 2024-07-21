/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:27:22 by dyunta            #+#    #+#             */
/*   Updated: 2024/07/21 18:38:39 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	args_sanitizer(int argc, char *argv[])
{
	char	*file_path;
	size_t	path_len;

	file_path = NULL;
	if (argc > 2)
	{
		errno = E2BIG;
		return ;
	}
	if (argc < 2)
	{
		errno = EOPNOTSUPP;
		return ;
	}
	file_path = argv[1];
	path_len = ft_strlen(file_path);
	if (file_path[path_len - 1] != 'f' || file_path[path_len - 2] != 'd'
		|| file_path[path_len - 3] != 'f')
		errno = ENOENT;
}
