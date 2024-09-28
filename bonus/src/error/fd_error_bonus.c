/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 10:30:37 by rgobet            #+#    #+#             */
/*   Updated: 2024/09/28 10:27:49 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	error_extention(void)
{
	ft_putstr_fd("Error\nNeed .cub extension! ❌\n", 2);
	exit(1);
}

void	error_fd(void)
{
	ft_putstr_fd("Error\nFile descriptor error! ❌\n", 2);
	exit(1);
}

void	error_read(int fd, char *buffer, char *getter)
{
	if (fd != -1)
		close(fd);
	if (buffer)
		free(buffer);
	if (getter)
	{
		free(getter);
		getter = NULL;
	}
	ft_putstr_fd("Error\nAn error occured while reading file! ❌\n", 2);
	exit(1);
}

void	error_malloc(int fd, char **tab)
{
	if (fd != -1)
		close(fd);
	if (tab)
		ft_free(tab);
	ft_putstr_fd("Error\nMalloc error! ❌\n", 2);
	exit(1);
}
