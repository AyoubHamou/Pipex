/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lastchild_multi_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 01:35:35 by ahamou            #+#    #+#             */
/*   Updated: 2023/01/31 02:12:51 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex_bonus.h"

void	lastchild_multi(int *fd, char *av, char **env)
{
	char	**arg2;
	char	*path2;

	arg2 = ft_split(av, ' ');
	path2 = get_path(arg2[0], env);
	close(fd[1]);
	if (dup2(fd[0], 0) == -1)
		error_message("Error while duplicating");
	close(fd[0]);
	execve(path2, arg2, env);
	exit(1);
}
