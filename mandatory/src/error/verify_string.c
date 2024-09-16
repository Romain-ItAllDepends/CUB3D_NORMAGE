/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 08:38:51 by rgobet            #+#    #+#             */
/*   Updated: 2024/09/16 11:04:28 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	verify_split(char **file, char *getter)
{
	if (!file)
	{
		free(getter);
		ft_free(file);
		return (1);
	}
	free(getter);
	return (0);
}

int	verify_rgb(char **rgb, int i)
{
	ft_free(rgb);
	if (i != 3)
	{
		ft_putstr_fd("Error\nBad format on RGB! ❌\n", 2);
		return (1);
	}
	return (0);
}

void	verify_map(char **map, int i)
{
	if (ft_strlen(map[0]) != i)
	{
		ft_putstr_fd("Error\nInvalid map! ❌\n", 2);
		ft_free(map);
		exit(1);
	}
}
