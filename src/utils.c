/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:08:57 by sschelti          #+#    #+#             */
/*   Updated: 2023/04/17 14:14:21 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	error_func(char *str)
{
	perror(str);
	exit(errno);
}

void	error_message(char *str)
{
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}
