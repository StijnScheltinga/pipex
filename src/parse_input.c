/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stijn <stijn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:46:41 by sschelti          #+#    #+#             */
/*   Updated: 2023/03/13 14:11:06 by stijn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	parse_input(char **argv, t_pipex *pipex)
{
	pipex->cmd1 = ft_split(argv[2], ' ');
	pipex->cmd2 = ft_split(argv[3], ' ');
	pipex->fd1 = open(argv[1], O_RDONLY);
	pipex->fd2 = open(argv[4], O_WRONLY);
	if (pipex->fd1 < 0 || pipex->fd2 < 0)
		exit(EXIT_FAILURE);
	get_paths(pipex);
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
