/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 01:54:40 by ahamou            #+#    #+#             */
/*   Updated: 2023/01/28 08:05:44 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

void	child1(int *fd, char **av, char **env)
{
	char	**arg1;
	char	*path1;
	int		infile;

	arg1 = ft_split(av[2], ' ');
	path1 = get_path(arg1[0], env);
	infile = open(av[1], O_RDONLY);
	if (infile == -1)
		error_message("Can't open the file");
	close(fd[0]);
	if (dup2(infile, 0) == -1)
		error_message("Error while duplicating");
	if (dup2(fd[1], 1) == -1)
		error_message("Error while duplicating");
	close(fd[1]);
	execve(path1, arg1, env);
	exit(1);
}
