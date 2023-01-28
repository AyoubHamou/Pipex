/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 08:56:05 by ahamou            #+#    #+#             */
/*   Updated: 2023/01/27 02:37:10 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strncmp(char *str1, char *str2, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
		{
			if (s1[i] - s2[i] > 0)
				return (1);
			return (-1);
		}
		i++;
	}
	return (0);
}

char	*ft_strdup(char	*s)
{
	char	*dup;
	size_t	strlen;
	size_t	i;

	strlen = ft_strlen(s);
	i = 0;
	dup = malloc(sizeof(char) * strlen + 1);
	if (!dup)
		return (0);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*dest;

	if (!s)
		return (0);
	j = ft_strlen(s);
	i = 0;
	k = start;
	if (start >= j)
		return (ft_strdup(""));
	while (i < len && k++ < j)
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (0);
	i = 0;
	while (s[start] && i < len)
	{
		dest[i++] = s[start++];
	}
	dest[i] = '\0';
	return (dest);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	if (size != 0 && count > SIZE_MAX / size)
		return (0);
	str = malloc(count * size);
	if (!str)
		return (NULL);
	ft_bzero(str, count * size);
	return (str);
}


void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_memset(void	*b, int c, size_t len)
{
	unsigned char	*s;
	size_t			i;

	s = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		s[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

char	*ft_strjoin(char	*s1, char	c, char	*s2)
{
	char	*str;
	
	str = malloc(sizeof(char) * (strlen(s1) + strlen(s2) + 2));
	size_t	i;
	size_t	j;
	i = 0;
	j = 0;
	while (s1[i])
		str[j++] = s1[i++];
	str[j++] = c; 
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}

static size_t	ft_wc(char const *s, char c)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			k++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (k);
}

static void	*ft_free(char	**strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		free (strs[i]);
		i++;
	}
	free (strs);
	return (NULL);
}

char	**ft_split(char *s, char c)
{
	char	**strs;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	strs = ft_calloc((ft_wc(s, c) + 1), sizeof(char *));
	if (!strs)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (s[j])
		{
			strs[k] = ft_substr(s, j, i - j);
			if (!strs[k++])
				return (ft_free(strs));
		}
	}
	return (strs);
}
