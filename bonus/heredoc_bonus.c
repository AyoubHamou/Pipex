/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 22:29:33 by ahamou            #+#    #+#             */
/*   Updated: 2023/01/31 03:02:40 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex_bonus.h"

void	here_doc(int *fd, char **av)
{
	char	*line;

	while (1)
	{
		write(1, "pipe heredoc> ", 14);
		line = get_line(0);
		if (!ft_strncmp(line, av[2], ft_strlen(av[2]))
			&& !line[ft_strlen(av[2])])
			break ;
		write(fd[1], line, ft_strlen(line));
		write(fd[1], "\n", 1);
		free(line);
	}
	exit(0);
}
