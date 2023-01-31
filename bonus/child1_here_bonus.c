/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child1_here_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 22:56:23 by ahamou            #+#    #+#             */
/*   Updated: 2023/01/31 02:08:56 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex_bonus.h"

void	child1_here(int *fd1, int *fd2, char **av, char **env)
{
	char	**arg1;
	char	*path1;

	arg1 = ft_split(av[3], ' ');
	path1 = get_path(arg1[0], env);
	close(fd1[1]);
	if (dup2(fd1[0], 0) == -1)
		error_message("Error while duplicating");
	close(fd1[0]);
	close(fd2[0]);
	if (dup2(fd2[1], 1) == -1)
		error_message("Error while duplicating");
	close(fd2[1]);
	execve(path1, arg1, env);
	exit(1);
}
