/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 03:55:34 by ahamou            #+#    #+#             */
/*   Updated: 2023/01/31 03:56:19 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	*here_display(char **av, char **env, int *fd1, int *fd2)
{
	int	*pid;

	pid = malloc(sizeof(int) * 2);
	if (pipe(fd1) == -1)
		exit(1);
	pid[0] = fork();
	if (pid[0] < 0)
		error_message("Error : while forking");
	if (!pid[0])
		here_doc(fd1, av);
	waitpid(pid[0], NULL, 0);
	if (pipe(fd2) == -1)
		exit(2);
	pid[1] = fork();
	if (pid[1] == -1)
		error_message("Error while forking");
	if (!pid[1])
		child1_here(fd1, fd2, av, env);
	return (pid);
}

void	here_prompt(char **av, char **env, int *fd1, int *fd2)
{
	int	id;
	int	*pd;

	pd = here_display(av, env, fd1, fd2);
	id = fork();
	if (id == -1)
		error_message("Error while forking");
	if (!id)
		child2_here(fd1, fd2, av, env);
	ft_close(fd1, fd2, pd);
}

void	redirect(char *av, char **env, int *fd1)
{
	int	pid;

	pipe(fd1);
	pid = fork();
	if (pid == -1)
		error_message("Error while forking");
	if (!pid)
		otherchild_multi(fd1, av, env);
	close(fd1[1]);
	dup2(fd1[0], 0);
	waitpid(pid, NULL, 0);
}

void	out_exec(int ac, char **av, int *fd, char **env)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		error_message("Error while forking");
	if (!pid)
		lastchild_multi(fd, av[ac - 2], env);
	close(fd[1]);
	close(fd[0]);
	waitpid(pid, NULL, 0);
}

void	multi_pipes(int ac, char **av, int *fd1, char **env)
{
	char	**arg1;
	char	*path1;
	int		i;
	int		in;
	int		out;

	i = 2;
	arg1 = ft_split(av[2], ' ');
	in = open(av[1], O_RDONLY);
	out = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	path1 = get_path(arg1[0], env);
	if (access(av[1], R_OK) == -1)
	{
		if (in == -1)
			error_message("Can't open the file");
		exit(0);
	}
	if (dup2(in, 0) == -1)
		error_message("Error while duping");
	while (i < ac - 2)
		redirect(av[i++], env, fd1);
	if (dup2(out, 1) == -1)
		error_message("Error while duping");
	out_exec(ac, av, fd1, env);
}
