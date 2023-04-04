/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:36:16 by sschelti          #+#    #+#             */
/*   Updated: 2023/04/04 15:16:08 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	double_command_check(t_pipex *pipex)
{
	if (command_check(pipex->paths, pipex->cmd2) == 1)
	{
		write(2, "command not found: ", 20);
		write(2, pipex->cmd2[0], ft_strlen(pipex->cmd2[0]));
		write(2, "\n", 1);
		exit(EXIT_FAILURE);
	}	
	if (command_check(pipex->paths, pipex->cmd1) == 1)
	{
		write(2, "command not found: ", 20);
		write(2, pipex->cmd1[0], ft_strlen(pipex->cmd1[0]));
		write(2, "\n", 1);
	}	
}

int	command_check(char **paths, char **cmd)
{
	char	*path_cmd;
	int		i;

	i = 0;
	while (paths[i])
	{
		path_cmd = ft_strjoin(paths[i], cmd[0]);
		if (access(path_cmd, X_OK | F_OK) == 0)
		{
			free (path_cmd);
			return (0);
		}
		else
			free (path_cmd);
		i++;
	}
	return (1);
}
