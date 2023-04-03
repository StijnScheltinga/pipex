/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:12:50 by sschelti          #+#    #+#             */
/*   Updated: 2023/04/03 18:22:14 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	leaks(void)
{
	system("leaks -s pipex");
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	// atexit(leaks);
	pipex.envp = envp;
	if (argc != 5)
	{
		write(1, "incorrect amount of argmuments\n", 30);
		return (1);
	}
	parse_input(argv, &pipex);
	get_paths(&pipex, envp);
	check_command(&pipex, pipex.cmd1);
	check_command(&pipex, pipex.cmd2);
	// create_process(&pipex);
	return (0);
}
