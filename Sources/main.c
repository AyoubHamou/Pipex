/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 08:41:26 by ahamou            #+#    #+#             */
/*   Updated: 2023/01/30 02:57:02 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

int	main(int ac, char **av, char **env)
{
	int	pid[2];
	int	fd[2];

	if (ac != 5)
		error_message("Error : ./pipex infile \"cmd1\" \"cmd2\" outfile");
	if (pipe(fd) == -1)
		return (1);
	pid[0] = fork();
	if (pid[0] == -1)
		error_message("Error while forking");
	if (!pid[0])
		child1(fd, av, env);
	pid[1] = fork();
	if (pid[1] == -1)
		error_message("Error while forking");
	if (!pid[1])
		child2(fd, av, env);
	close(fd[1]);
	close(fd[0]);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
}
