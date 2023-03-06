/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:51:01 by sschelti          #+#    #+#             */
/*   Updated: 2023/03/06 15:58:30 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	create_process(t_pipex *pipex)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		exit(EXIT_FAILURE);
	else if (pid == 0)
		child_process(pipex);
	else if (pid > 0)
		parent_process(pipex);
}

void	child_process(t_pipex *pipex)
{
	int		i;
	char	*path_cmd;

	i = 0;
	path_cmd = NULL;
	while (pipex->paths[i])
	{
		path_cmd = ft_strjoin(pipex->paths[i], pipex->cmd1[0]);
		if (!path_cmd[0])
			exit(EXIT_FAILURE);
		if (access(path_cmd, X_OK) == 0)
			break ;
		i++;
	}
	if (execve(path_cmd, pipex->cmd1, NULL) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
}

void	parent_process(t_pipex *pipex)
{
	printf("jo");
}
