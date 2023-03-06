/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:12:50 by sschelti          #+#    #+#             */
/*   Updated: 2023/03/06 14:48:43 by sschelti         ###   ########.fr       */
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
	parse_input(argc, argv, &pipex);
	create_process(&pipex);
	return (0);
}
