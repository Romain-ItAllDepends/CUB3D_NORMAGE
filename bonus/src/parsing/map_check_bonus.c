/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 17:31:13 by rgobet            #+#    #+#             */
/*   Updated: 2024/10/01 08:44:09 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

static int	verification_of_border(char *borders)
{
	int	i;

	i = 0;
	while (borders && borders[i] == '1')
		i++;
	if (i != ft_strlen(borders))
	{
		free(borders);
		return (1);
	}
	free(borders);
	return (0);
}

static void	check_first_last_line(char **map)
{
	int	i;
	int	last;

	i = 0;
	last = len_db_char(map) - 1;
	while (map && map[0] && map[0][i])
	{
		if (map[0][i] != '1')
			break ;
		i++;
	}
	verify_map(map, i);
	i = 0;
	while (map && map[last] && map[last][i])
	{
		if (map[last][i] != '1')
			break ;
		i++;
	}
	if (ft_strlen(map[last]) != i)
	{
		ft_putstr_fd("Error\nInvalid map! ❌\n", 2);
		ft_free(map);
		exit(1);
	}
}

int	check_closed_map(char **map)
{
	int		i;
	int		j;
	char	*tab;

	i = 1;
	check_first_last_line(map);
	tab = ft_calloc(2 * len_db_char(map), sizeof(char));
	if (!tab)
		error_malloc(-1, map);
	while (map[i])
	{
		j = 0;
		if (abs(ft_strlen(map[i]) - ft_strlen(map[i - 1])) >= 2 && i != 0)
			check_diff_wall(map, tab, i);
		while (map[i][j])
		{
			get_borders(tab, map[i], j);
			if (j == ft_strlen(map[i]) - 1)
				break ;
			j++;
		}
		i++;
	}
	return (verification_of_border(tab));
}
