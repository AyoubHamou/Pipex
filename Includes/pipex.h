/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 08:28:51 by ahamou            #+#    #+#             */
/*   Updated: 2023/01/28 08:04:20 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>
# include <fcntl.h>
# include <time.h>
# include <string.h>

// ---------Sources------------
void	child1(int fd[2], char **av, char **env);
void	child2(int fd[2], char **av, char **env);

// ----------Utils-------------
void	error_message(char *str);
size_t	ft_strlen(char *s);
char	*ft_strdup(char	*s);
char	*ft_substr(char *s, unsigned int start, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	**ft_split(char *s, char c);
char	*get_path(char	*cmd, char	**env);
int		ft_strncmp(char *str1, char *str2, size_t n);
char	*ft_strjoin(char *s1, char c, char *s2);
void	*ft_memset(void	*b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	without_exit(char *str);

#endif