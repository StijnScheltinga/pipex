/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:51:01 by sschelti          #+#    #+#             */
/*   Updated: 2023/03/27 18:19:49 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	create_process(t_pipex *pipex)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) < 0)
	{
		perror("pipe error");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
		child_process(pipex, fd);
	else if (pid > 0)
		parent_process(pipex, fd, pid);
}

void	child_process(t_pipex *pipex, int *fd)
{
	close(fd[READ_END]);
	if (dup2(fd[WRITE_END], STDOUT_FILENO) == -1)
	{
		perror("dup2 failed");
		exit(EXIT_FAILURE);
	}
	if (dup2(pipex->fd1, STDIN_FILENO) == -1)
	{
		perror("dup2 failed");
		exit(EXIT_FAILURE);
	}
	execute_command(pipex->paths, pipex->cmd1);
	close(fd[WRITE_END]);
	exit(EXIT_SUCCESS);
}

void	parent_process(t_pipex *pipex, int *fd, pid_t pid)
{
	int		status;
	pid_t	child_process;

	status = 0;
	child_process = waitpid(pid, &status, 0);
	if (child_process == -1)
	{
		perror("wait");
		exit(EXIT_FAILURE);
	}
	close(fd[WRITE_END]);
	if (dup2(fd[READ_END], STDIN_FILENO) == -1)
	{
		perror("dup2 failed");
		exit(EXIT_FAILURE);
	}
	if (dup2(pipex->fd2, STDOUT_FILENO) == -1)
	{
		perror("dup2 failed");
		exit(EXIT_FAILURE);
	}
	execute_command(pipex->paths, pipex->cmd2);
	close(fd[READ_END]);
	exit(EXIT_SUCCESS);
}

void	execute_command(char **paths, char **cmd)
{
	int		i;
	char	*path_cmd;

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
}
