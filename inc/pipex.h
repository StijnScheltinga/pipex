/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:50:36 by sschelti          #+#    #+#             */
/*   Updated: 2023/02/28 15:45:44 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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

int		parse_input(int argc, char **argv, t_pipex *pipex);
void	open_files(char **argv, t_pipex *pipex);
void	get_paths(char **envp, t_pipex *pipex);
char	**append_slash(char **old_paths);
int		create_process(t_pipex *pipex);
void	child_process(t_pipex *pipex);
void	parent_process(t_pipex *pipex);

#endif