/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:50:36 by sschelti          #+#    #+#             */
/*   Updated: 2023/03/06 13:24:49 by sschelti         ###   ########.fr       */
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

void	parse_input(int argc, char **argv, t_pipex *pipex);
void	get_paths(t_pipex *pipex);
void	create_process(t_pipex *pipex);
void	child_process(t_pipex *pipex);
void	parent_process(t_pipex *pipex);

#endif