/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child2_here_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 22:57:43 by ahamou            #+#    #+#             */
/*   Updated: 2023/01/31 02:09:07 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex_bonus.h"

void	child2_here(int *fd1, int *fd2, char **av, char **env)
{
	char	**arg2;
	char	*path2;
	int		outfile;

	arg2 = ft_split(av[4], ' ');
	path2 = get_path(arg2[0], env);
	outfile = open(av[5], O_RDWR | O_CREAT | O_APPEND, 0644);
	if (outfile == -1)
		error_message("Can't open the file");
	close(fd1[1]);
	close(fd2[1]);
	if (dup2(fd2[0], 0) == -1)
		error_message("Error while duplicating");
	close(fd1[0]);
	close(fd2[0]);
	if (dup2(outfile, 1) == -1)
		error_message("Error while duplicating");
	close(outfile);
	execve(path2, arg2, env);
	exit(1);
}
