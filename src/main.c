/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:12:50 by sschelti          #+#    #+#             */
/*   Updated: 2023/02/28 18:20:09 by sschelti         ###   ########.fr       */
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

	atexit(leaks);
	if (parse_input(argc, argv, &pipex) == 1)
		return (1);
	pipex.envp = envp;
	get_paths(envp, &pipex);
	printf("%s\n%s\n", pipex.cmd1[0], pipex.cmd1[1]); 
	if (create_process(&pipex) == 1)
		return (1);
	return (0);
}
