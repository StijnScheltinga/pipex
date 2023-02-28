/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:51:01 by sschelti          #+#    #+#             */
/*   Updated: 2023/02/28 17:04:43 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	create_process(t_pipex *pipex)
{
	// pid_t	pid;

	// pid = fork();
	// if (pid == 0)
		child_process(pipex);
	// else if (pid > 0)
	// 	parent_process(pipex);
	return (0);
}

void	child_process(t_pipex *pipex)
{
	int		i;
	// char	*path_cmd;

	i = 0;
	while (pipex->paths[i])
	{
		printf("%s\n", pipex->paths[1]);
		// path_cmd = ft_strjoin(pipex->paths[i], pipex->cmd1[0]);
		// if (!path_cmd)
		// 	exit(EXIT_FAILURE);
		// if (execve(path_cmd, pipex->cmd1, pipex->envp) != -1)
		// 	printf("jo");
		// perror("execve");
		// printf("%s\n", path_cmd);
		i++;
	}
}

// void	parent_process(t_pipex *pipex)
// {
// 	t_pipex	*ok;

// 	ok = pipex;
// 	wait(NULL);
// }
