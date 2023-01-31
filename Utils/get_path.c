/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 09:49:33 by ahamou            #+#    #+#             */
/*   Updated: 2023/01/31 02:42:27 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

static void	ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

char	**secure_paths(char **env)
{
	char	*path;
	char	**tree;
	int		i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			break ;
		i++;
	}
	if (!env[i])
		return (NULL);
	path = ft_strdup(env[i] + 5);
	tree = ft_split(path, ':');
	free(path);
	return (tree);
}

int	search_path(char **path, char **all_paths, char *cmd)
{
	int	i;

	i = 0;
	while (all_paths[i])
	{	
		*path = ft_strjoin(all_paths[i], '/', cmd);
		if (!access(*path, F_OK))
		{
			if (!access(*path, X_OK))
			{
				ft_free(all_paths);
				return (1);
			}
			without_exit("Permission Denied");
		}
		free(*path);
		i++;
	}
	return (0);
}

char	*get_path(char	*cmd, char	**env)
{
	char	**all_paths;
	char	*path;
	size_t	i;

	i = 0;
	if (!access(cmd, F_OK))
		return (cmd);
	if (!cmd)
		error_message("Error : permission denied");
	else if (ft_strrchr(cmd, '/'))
		error_message("Error : no such file or directory");
	all_paths = secure_paths(env);
	if (search_path(&path, all_paths, cmd))
		return (path);
	free(all_paths);
	without_exit("Error : command not found");
	return (NULL);
}
