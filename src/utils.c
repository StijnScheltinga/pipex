/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:08:57 by sschelti          #+#    #+#             */
/*   Updated: 2023/04/03 16:03:18 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	free_func(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		printf("allocated: %s\n", arr[i]);
		free (arr[i]);
		i++;
	}
	free (arr);
	printf("free: %s\n", arr[5]);
}

void	error_func(char *str)
{
	perror(str);
	exit(errno);
}
