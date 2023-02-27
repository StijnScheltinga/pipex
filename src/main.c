/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:12:50 by sschelti          #+#    #+#             */
/*   Updated: 2023/02/27 17:32:14 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int argc, char **argv)
{
	t_pipex	pipex;

	if (parse_input(argc, argv, &pipex) == 1)
		return (1);
	printf("%s\n%s\n", pipex.cmd1, pipex.cmd2);
	// if (create_process(&pipex) == 1)
	// 	return (1);
	return (0);
}
