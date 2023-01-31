/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otherchild_multi_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 01:40:20 by ahamou            #+#    #+#             */
/*   Updated: 2023/01/31 03:57:14 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

void	otherchild_multi(int *fd, char *av, char **env)
{
	char	**arg1;
	char	*path1;

	arg1 = ft_split(av, ' ');
	path1 = get_path(arg1[0], env);
	close(fd[0]);
	if (dup2(fd[1], 1) == -1)
		error_message("Error while duplicating");
	close(fd[1]);
	execve(path1, arg1, env);
	exit(1);
}
