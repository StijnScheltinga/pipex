/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:50:36 by sschelti          #+#    #+#             */
/*   Updated: 2023/04/14 16:58:35 by sschelti         ###   ########.fr       */
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

int		error_handling(int argc, char **argv);
void	parse_input(char **argv, t_pipex *pipex);
void	get_paths(t_pipex *pipex, char **envp);
void	create_process(t_pipex *pipex);
void	child_process(t_pipex *pipex, int *fd);
void	parent_process(t_pipex *pipex, int *fd);
void	execute_command(char **paths, char **cmd, t_pipex *pipex);
void	double_command_check(t_pipex *pipex);
int		command_check(char **paths, char **cmd);
void	error_func(char *str);
void	print_func(t_pipex *pipex);
void	free_func(char **arr);
void	free_all(t_pipex *pipex);
void	error_message(char *str);
void	append_slash(t_pipex *pipex);

#endif