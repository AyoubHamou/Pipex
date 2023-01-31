/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 22:31:32 by ahamou            #+#    #+#             */
/*   Updated: 2023/01/31 03:52:20 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex_bonus.h"

int	line_exist(char *s)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*return_line(char **s)
{
	char	*line;

	line = ft_substr(*s, 0, ft_strlen(*s) - 1);
	free(*s);
	*s = NULL;
	return (line);
}

char	*ft_free(char *copy, char **str)
{
	if (*str)
	{
		free (*str);
		*str = NULL;
	}
	free (copy);
	return (NULL);
}

static char	*ft_strjoins(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*a;

	if (!s1)
	{
		s1 = malloc(1);
		*s1 = '\0';
	}
	i = 0;
	j = 0;
	a = malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!a)
		return (NULL);
	while (s1[i])
		a[i++] = s1[j++];
	j = 0;
	while (s2[j])
		a[i++] = s2[j++];
	a[i] = '\0';
	free(s1);
	return (a);
}

char	*get_line(int fd)
{
	char		*copy;
	char		*str;
	ssize_t		n;

	str = NULL;
	copy = malloc (sizeof(char) * 2);
	if (!copy)
		return (NULL);
	n = 1337;
	while (line_exist(str) == -1 && n > 0)
	{
		n = read(fd, copy, 1);
		if (n < 0)
			return (ft_free(copy, &str));
		copy[n] = '\0';
		str = ft_strjoins(str, copy);
		if (!str)
			return (ft_free(copy, &str));
		if (!str[0])
			return (ft_free(copy, &str));
	}
	free (copy);
	return (return_line(&str));
}
