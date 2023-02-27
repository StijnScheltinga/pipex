/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:51:01 by sschelti          #+#    #+#             */
/*   Updated: 2023/02/27 17:32:59 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	create_process(t_pipex *pipex)
{
	pid_t	pid;
	pipex = NULL;

	pid = fork();
	// if (pid < 0)
	// 	exit (EXIT_FAILURE);
	// // else if (pid == 0)
	// // {
	// // 	execve();
	// // }
	// else
	// {
	// 	wait(NULL);
	// }
	return (0);
}
	