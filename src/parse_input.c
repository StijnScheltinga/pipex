/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:46:41 by sschelti          #+#    #+#             */
/*   Updated: 2023/04/04 12:41:54 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	parse_input(char **argv, t_pipex *pipex)
{
	pipex->cmd1 = ft_split(argv[2], ' ');
	if (pipex->cmd1 == NULL)
		error_message("Malloc fail");
	pipex->cmd2 = ft_split(argv[3], ' ');
	if (pipex->cmd2 == NULL)
		error_message("Malloc fail");
	pipex->fd1 = open(argv[1], O_RDONLY);
	if (pipex->fd1 < 0)
		perror ("infile");
	pipex->fd2 = open(argv[4], O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (pipex->fd2 < 0)
		error_func("outfile");
	if (access(argv[4], W_OK | R_OK) < 0)
		error_func("outfile");
}

void	get_paths(t_pipex *pipex, char **envp)
{
	int		i;
	char	*temp;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
		{
			pipex->paths = ft_split((envp[i] + 5), ':');
			if (!pipex->paths)
				error_message("Malloc fail");
		}
		i++;
	}
	i = 0;
	while (pipex->paths[i])
	{
		temp = ft_strjoin(pipex->paths[i], "/");
		if (!temp)
			error_message("Malloc fail");
		free (pipex->paths[i]);
		pipex->paths[i] = ft_strdup(temp);
		free (temp);
		i++;
	}
}
