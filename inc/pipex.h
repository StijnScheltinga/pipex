/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stijn <stijn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:50:36 by sschelti          #+#    #+#             */
/*   Updated: 2023/03/10 16:22:28 by stijn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define READ_END 0
# define WRITE_END 1

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>

# include "../lib/libft/libft.h"

typedef struct s_pipex{
	char	**cmd1;
	char	**cmd2;
	char	**paths;
	char	**envp;
	int		fd1;
	int		fd2;
}	t_pipex;

void	parse_input(int argc, char **argv, t_pipex *pipex);
void	get_paths(t_pipex *pipex);
void	create_process(t_pipex *pipex);
void	child_process(t_pipex *pipex, int *fd);
void	parent_process(t_pipex *pipex, int *fd);
void	execute_command(char **paths, char **cmd);

#endif