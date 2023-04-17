/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:12:50 by sschelti          #+#    #+#             */
/*   Updated: 2023/04/17 15:53:23 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	pipex.envp = envp;
	if (argc != 5)
		error_message("incorrect amount of parameters\n");
	if (!argv[1][0] || !argv[2][0] || !argv[3][0] || !argv[4][0])
		error_message("empty input\n");
	parse_input(argv, &pipex);
	get_paths(&pipex, envp);
	double_command_check(&pipex);
	create_process(&pipex);
	return (0);
}
