/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:50:36 by sschelti          #+#    #+#             */
/*   Updated: 2023/02/27 16:44:46 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_pipex{
	char	*cmd1;
	char	*cmd2;
	char	*cmd1_path;
	char	*cmd2_path;
	int		fd1;
	int		fd2;
}	t_pipex;

int		parse_input(int argc, char **argv, t_pipex *pipex);
void	open_files(char **argv, t_pipex *pipex);
int		create_process(t_pipex *pipex);

#endif