/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:46:41 by sschelti          #+#    #+#             */
/*   Updated: 2023/02/27 16:35:07 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	parse_input(int argc, char **argv, t_pipex *pipex)
{
	argc = 0;
	pipex->cmd1 = argv[2];
	pipex->cmd2 = argv[3];
	open_files(argv, pipex);
	return (0);
}

void	open_files(char **argv, t_pipex *pipex)
{
	pipex->fd1 = open(argv[1], O_RDONLY);
	pipex->fd2 = open(argv[4], O_WRONLY);
	if (pipex->fd1 < 0 || pipex->fd2 < 0)
		exit(EXIT_FAILURE);
	printf("%d\n%d\n", pipex->fd1, pipex->fd2);
}
