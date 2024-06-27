/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 21:21:34 by dyunta            #+#    #+#             */
/*   Updated: 2023/11/02 21:36:55 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Counts the total number of args in **argv.
 */
int	count_args(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}
