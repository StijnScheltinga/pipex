/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:51:01 by sschelti          #+#    #+#             */
/*   Updated: 2023/04/17 16:09:27 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	create_process(t_pipex *pipex)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) < 0)
		error_func("pipe");
	pid = fork();
	if (pid < 0)
		error_func("fork");
	else if (pid == 0)
		child_process(pipex, fd);
	else if (pid > 0)
		parent_process(pipex, fd);
}

void	child_process(t_pipex *pipex, int *fd)
{
	if (pipex->fd1 < 0)
		exit(errno);
	close(fd[READ_END]);
	if (dup2(fd[WRITE_END], STDOUT_FILENO) == -1)
		error_func("dup2");
	if (dup2(pipex->fd1, STDIN_FILENO) == -1)
		error_func("dup2");
	execute_command(pipex->paths, pipex->cmd1, pipex);
	close(fd[WRITE_END]);
	exit(EXIT_FAILURE);
}

void	parent_process(t_pipex *pipex, int *fd)
{
	close(fd[WRITE_END]);
	if (dup2(fd[READ_END], STDIN_FILENO) == -1)
		error_func("dup2");
	if (dup2(pipex->fd2, STDOUT_FILENO) == -1)
		error_func("dup2");
	execute_command(pipex->paths, pipex->cmd2, pipex);
	close(fd[READ_END]);
	exit(EXIT_FAILURE);
}

void	execute_command(char **paths, char **cmd, t_pipex *pipex)
{
	int		i;
	char	*path_cmd;

	i = 0;
	while (paths[i])
	{
		path_cmd = ft_strjoin(paths[i], cmd[0]);
		if (!path_cmd)
			error_message("Malloc failed");
		if (access(path_cmd, F_OK) == 0)
		{
			if (execve(path_cmd, cmd, pipex->envp) == -1)
				error_func("error");
		}
		else
			free (path_cmd);
		i++;
	}
}
