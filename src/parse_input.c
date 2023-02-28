/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:46:41 by sschelti          #+#    #+#             */
/*   Updated: 2023/02/28 13:28:102 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	parse_input(int argc, char **argv, t_pipex *pipex)
{
	argc = 0;
	pipex->cmd1 = ft_split(argv[2], ' ');
	pipex->cmd2 = ft_split(argv[3], ' ');
	open_files(argv, pipex);
	return (0);
}

void	open_files(char **argv, t_pipex *pipex)
{
	pipex->fd1 = open(argv[1], O_RDONLY);
	pipex->fd2 = open(argv[4], O_WRONLY);
	if (pipex->fd1 < 0 || pipex->fd2 < 0)
		exit(EXIT_FAILURE);
	printf("%d\n%d\n", pipex->fd1, pipex->fd2);
}

void	get_paths(char **envp, t_pipex *pipex)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
			pipex->paths = ft_split((envp[i] + 5), ':');
		i++;
	}
	pipex->paths = append_slash(pipex->paths);
}

char	**append_slash(char **old_paths)
{
	char	**new_paths;
	int		size;
	int		i;

	i = 0;
	while (old_paths[i])
		i++;
	new_paths = malloc(i * sizeof(char *));
	i = 0;
	while (old_paths[i])
	{
		size = ft_strlen(old_paths[i]);
		new_paths[i] = malloc(sizeof(char) * (size + 2));
		ft_strlcpy(new_paths[i], old_paths[i], size + 1);
		new_paths[i][size] = '/';
		new_paths[i][size + 1] = '\0';
		i++;
	}
	new_paths[i] = NULL;
	while (i-- != 0)
		free (old_paths[i]);
	free (old_paths);
	return (new_paths);
}
