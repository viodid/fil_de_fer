/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:20:10 by dyunta            #+#    #+#             */
/*   Updated: 2024/08/05 14:19:05 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"

char	*get_next_line(int fd);
size_t	list_len_check_nl(t_list *node, int check);
t_list	*create_and_append_node(char *content, t_list *header);
char	*ft_strdup(const char *str);
void	free_list(t_list *node);

#endif
