/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:46:41 by sschelti          #+#    #+#             */
/*   Updated: 2023/04/03 18:22:36 by sschelti         ###   ########.fr       */
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
		perror ("infile");
	pipex->fd2 = open(argv[4], O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (pipex->fd2 < 0)
		error_func("outfile");
	if (access(argv[4], W_OK) < 0 || access(argv[4], R_OK) < 0)
		error_func("outfile");
}

void	get_paths(t_pipex *pipex, char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
		{
			pipex->paths = ft_split((envp[i] + 5), ':');
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
	// free_func(pipex->paths);
	// free_func(pipex->cmd1);
	// free_func(pipex->cmd2);
}

void	check_command(t_pipex *pipex, char **cmd)
{
	char	*path_command;
	int		i;

	i = 0;
	while (pipex->paths[i])
	{
		path_command = ft_strjoin(pipex->paths[i], cmd[0]);
		if (access(path_command, F_OK) == 0)
			break ;
		i++;
	}
	if (access(path_command, F_OK) == -1)
		error_func("error");
}
