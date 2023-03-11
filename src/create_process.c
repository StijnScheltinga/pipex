/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stijn <stijn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:51:01 by sschelti          #+#    #+#             */
/*   Updated: 2023/03/11 18:28:46 by stijn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	create_process(t_pipex *pipex)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) < 0)
		exit(EXIT_FAILURE);
	pid = fork();
	if (pid < 0)
		exit(EXIT_FAILURE);
	else if (pid == 0)
		child_process(pipex, fd);
	else if (pid > 0)
		parent_process(pipex, fd);
}

void	child_process(t_pipex *pipex, int *fd)
{
	close(fd[READ_END]);
	dup2(fd[WRITE_END], STDOUT_FILENO);
	dup2(pipex->fd1, STDIN_FILENO);
	execute_command(pipex->paths, pipex->cmd1);
	
}

void	parent_process(t_pipex *pipex, int *fd)
{
	int		status;

	status = 0;
	wait(&status);
	close(fd[WRITE_END]);
	dup2(fd[READ_END], STDIN_FILENO);
	dup2(pipex->fd2, STDOUT_FILENO);
	execute_command(pipex->paths, pipex->cmd2);
}

void	execute_command(char **paths, char **cmd)
{
	int		i;
	char *	path_cmd;

	i = 0;
	while (paths[i])
	{
		path_cmd = ft_strjoin(paths[i], cmd[0]);
		if (!path_cmd)
			exit(EXIT_FAILURE);
		if (access(path_cmd, X_OK) == 0)
			break ;
		i++;
	}
	if (execve(path_cmd, cmd, NULL) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
		exit (EXIT_SUCCESS);
}
