/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 01:57:32 by ahamou            #+#    #+#             */
/*   Updated: 2023/01/28 08:06:07 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

void	child2(int *fd, char **av, char **env)
{
	char	**arg2;
	char	*path2;
	int		outfile;

	arg2 = ft_split(av[3], ' ');
	path2 = get_path(arg2[0], env);
	outfile = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
		error_message("Can't open the file");
	close(fd[1]);
	if (dup2(fd[0], 0) == -1)
		error_message("Error while duplicating");
	close(fd[0]);
	if (dup2(outfile, 1) == -1)
		error_message("Error while duplicating");
	close(outfile);
	execve(path2, arg2, env);
	exit(1);
}
