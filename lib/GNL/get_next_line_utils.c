/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 22:53:31 by dyunta            #+#    #+#             */
/*   Updated: 2024/07/06 18:57:25 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Return the length of the list, or the length of the list
 * until the first \n character is found*/
size_t	list_len_check_nl(t_list *node, int check)
{
	size_t	len;
	size_t	i;

	if (!node)
		return (0);
	len = 0;
	while (node)
	{
		i = 0;
		while (((char *)node->content)[i])
		{
			len++;
			if (((char *)node->content)[i++] == '\n')
				return (len);
		}
		node = node->next;
	}
	if (!check)
		return (len);
	return (0);
}

/* Create a new node and append it to the end of the list.
 * Return only the new node if no header is received*/
t_list	*create_and_append_node(char *content, t_list *header)
{
	t_list	*node;
	t_list	*tmp;

	if (!content)
		return (NULL);
	node = (t_list *) malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = ft_strdup((const char *)content);
	node->next = NULL;
	if (!header)
		return (node);
	tmp = header;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	return (header);
}

/* Linked list error proof free function */
void	free_list(t_list *node)
{
	if (!node)
		return ;
	free_list(node->next);
	if (*((char *)node->content))
		free(node->content);
	free(node);
}

/* Receive a pointer to a str and return a new pointer to the same content
 * if no content is received, return a new pointer to '\0'*/
char	*ft_strdup(const char *str)
{
	int		len;
	char	*ptr;
	char	*start_ptr;

	len = 0;
	while (*str && str[len])
		len++;
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (NULL);
	start_ptr = ptr;
	while (*str)
		*ptr++ = *(char *)str++;
	*ptr = '\0';
	return (start_ptr);
}
