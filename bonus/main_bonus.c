/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 22:33:20 by ahamou            #+#    #+#             */
/*   Updated: 2023/01/31 03:56:10 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_close(int *fd1, int *fd2, int *pid)
{
	close(fd1[1]);
	close(fd1[0]);
	close(fd2[1]);
	close(fd2[0]);
	waitpid(pid[1], NULL, 0);
	waitpid(pid[2], NULL, 0);
	free(pid);
}

int	main(int ac, char **av, char **env)
{
	int	fd1[2];
	int	fd2[2];

	if (ac < 5)
		error_message
		("Error: ./pipex_bonus file1 \"cmd1\" \"cmd2\" ... \"cmdn\" file2");
	if (!ft_strncmp(av[1], "here_doc", 8))
		here_prompt(av, env, fd1, fd2);
	else
		multi_pipes(ac, av, fd1, env);
	return (0);
}
