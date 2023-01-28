/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 09:49:33 by ahamou            #+#    #+#             */
/*   Updated: 2023/01/28 07:59:46 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

static void	ft_free(char **tab)
{
	int i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

char	*get_path(char	*cmd, char	**env)
{
	size_t	i;

	i = 0;
	if (!access(cmd, F_OK))
		return (cmd);
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			break;
		i++;
	}
	if (!env[i])
		return (NULL);
	char	*s_paths ;
	char	**all_paths;

	s_paths = ft_strdup(env[i] + 5);
	all_paths = ft_split(s_paths, ':');
	free(s_paths);
	i = 0;
	while (all_paths[i])
	{
		char	*path;
		
		path = ft_strjoin(all_paths[i], '/', cmd);
		if (!access(path, F_OK))
		{
			if (!access(path, X_OK))
			{
				ft_free(all_paths);
				return(path);
			}
			without_exit("Permission Denied");
		}
		free(path);
		i++;
	}
	free(all_paths);
	without_exit("Error : command not found");
	return (NULL);
}
