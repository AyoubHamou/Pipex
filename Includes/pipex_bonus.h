/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 22:25:34 by ahamou            #+#    #+#             */
/*   Updated: 2023/01/31 03:59:10 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>
# include <fcntl.h>
# include <time.h>
# include <string.h>

// ---------Libft------------
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strrchr(const char *str, int c);
int		ft_strncmp(char *s1, char *s2, size_t n);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char c, char *s2);
char	*ft_strdup(char	*s);
char	**ft_split(char *s, char c);
void	*ft_memset(void	*b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);

// ---------Sources------------
void	child1_here(int *fd1, int *fd2, char **av, char **env);
void	child2_here(int *fd1, int *fd2, char **av, char **env);
void	lastchild_multi(int *fd, char *av, char **env);
void	otherchild_multi(int *fd, char *av, char **env);
char	*get_line(int fd);
void	here_doc(int *fd, char **av);
void	ft_close(int *fd1, int *fd2, int *pid);
int		*here_display(char **av, char **env, int *fd1, int *fd2);
void	here_prompt(char **av, char **env, int *fd1, int *fd2);
void	redirect(char *av, char **env, int *fd1);
void	out_exec(int ac, char **av, int *fd, char **env);
void	multi_pipes(int ac, char **av, int *fd1, char **env);

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
char	*ft_strrchr(const char *str, int c);

#endif