/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:46:41 by sschelti          #+#    #+#             */
/*   Updated: 2023/03/28 18:23:39 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	parse_input(char **argv, t_pipex *pipex)
{
	pipex->cmd1 = ft_split(argv[2], ' ');
	if (pipex->cmd1 == NULL)
		exit(EXIT_FAILURE);
	pipex->cmd2 = ft_split(argv[3], ' ');
	if (pipex->cmd2 == NULL)
		exit(EXIT_FAILURE);
	pipex->fd1 = open(argv[1], O_RDONLY);
	if (pipex->fd1 < 0)
		error_func("incorrect input file");
	pipex->fd2 = open(argv[4], O_CREAT | O_TRUNC | O_WRONLY);
	if (pipex->fd2 < 0)
		error_func("incorrect output file");
}

void	get_paths(t_pipex *pipex)
{
	int		i;

	i = 0;
	while (pipex->envp[i])
	{
		if (ft_strnstr(pipex->envp[i], "PATH=", 5))
		{
			pipex->paths = ft_split((pipex->envp[i] + 5), ':');
			if (!pipex->paths)
				exit(EXIT_FAILURE);
		}
		i++;
	}
	i = 0;
	while (pipex->paths[i])
	{
		pipex->paths[i] = ft_strjoin(pipex->paths[i], "/");
		if (!pipex->paths[i])
			exit(EXIT_FAILURE);
		i++;
	}
}

void	error_func(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}
