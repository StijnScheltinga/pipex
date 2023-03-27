/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:46:41 by sschelti          #+#    #+#             */
/*   Updated: 2023/03/27 15:42:10 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	invalid_input(int argc, char **argv)
{
	if (argc != 5)
	{
		write(1, "incorrect amount of argmuments\n", 30);
		return (1);
	}	
	if (access(argv[1], R_OK | F_OK) == -1)
	{
		perror("file1 error");
		return (1);
	}
	if (access(argv[4], W_OK | F_OK) == -1)
	{
		perror("file2 error");
		return (1);
	}
	return (0);
}

void	parse_input(char **argv, t_pipex *pipex)
{
	pipex->cmd1 = ft_split(argv[2], ' ');
	if (pipex->cmd1 == NULL)
	{
		write(1, "malloc failed\n", 15);
		exit(EXIT_FAILURE);
	}
	pipex->cmd2 = ft_split(argv[3], ' ');
	if (pipex->cmd2 == NULL)
	{
		write(1, "malloc failed\n", 15);
		exit(EXIT_FAILURE);
	}
	pipex->fd1 = open(argv[1], O_RDONLY);
	if (pipex->fd1 < 0)
	{
		perror("invalid input file");
		exit(EXIT_FAILURE);
	}
	pipex->fd2 = open(argv[4], O_WRONLY);
	if (pipex->fd2 < 0)
	{
		perror("invalid output file");
		exit(EXIT_FAILURE);
	}
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
			{
				write(1, "malloc failed\n", 15);
				exit(EXIT_FAILURE);
			}
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
