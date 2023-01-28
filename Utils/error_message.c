/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 08:47:53 by ahamou            #+#    #+#             */
/*   Updated: 2023/01/25 09:36:12 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

void	error_message(char *str)
{
	write (STDERR_FILENO, str, ft_strlen(str));
	write (STDERR_FILENO, "\n", 1);
	exit(1);
}