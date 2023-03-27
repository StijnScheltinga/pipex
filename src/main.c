/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:12:50 by sschelti          #+#    #+#             */
/*   Updated: 2023/03/27 17:49:42 by sschelti         ###   ########.fr       */
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

	pipex.envp = envp;
	atexit(leaks);
	if (invalid_input(argc, argv) == 1)
		exit(EXIT_FAILURE);
	parse_input(argv, &pipex);
	create_process(&pipex);
	return (0);
}
