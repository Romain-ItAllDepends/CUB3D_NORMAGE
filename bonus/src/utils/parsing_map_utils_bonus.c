/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 09:10:42 by rgobet            #+#    #+#             */
/*   Updated: 2024/09/28 10:30:27 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

int	verif_map_split(char *s)
{
	int	i;
	int	j;

	i = 0;
	while (s && s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	j = 0;
	while (s && s[i])
	{
		if (s[i] == '\n' && j == 1)
		{
			ft_putstr_fd(
				"Error\nBlank line in the map or too much parameters!\n", 2);
			return (1);
		}
		else if (s[i] == '\n')
			j = 0;
		i++;
		j++;
	}
	return (0);
}

int	is_parameter(char *s)
{
	int	i;

	i = 0;
	if (s && s[i] && s[i + 1] && s[i + 2]
		&& ((s[i] == 'S' && s[i + 1] == 'O')
			|| (s[i] == 'W' && s[i + 1] == 'E')
			|| (s[i] == 'N' && s[i + 1] == 'O')
			|| (s[i] == 'E' && s[i + 1] == 'A'))
		&& (s[i + 2] == ' ' || s[i + 2] == '\t'))
		return (1);
	else if (s && s[i] && s[i + 1]
		&& (s[i] == 'F' || s[i] == 'C')
		&& (s[i + 1] == ' ' || s[i + 1] == '\t'))
		return (1);
	return (0);
}
