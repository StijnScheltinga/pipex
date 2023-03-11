/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stijn <stijn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:12:50 by sschelti          #+#    #+#             */
/*   Updated: 2023/03/11 18:38:59 by stijn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	leaks(void)
{
	if (system("leaks /Users/stijn/projects/pipex/pipex > /Users/stijn/projects/pipex/leaks.txt") == -1)
		printf("fail");
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
