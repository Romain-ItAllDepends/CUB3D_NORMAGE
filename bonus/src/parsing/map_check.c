/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 17:31:13 by rgobet            #+#    #+#             */
/*   Updated: 2024/09/15 08:53:46 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	is_unknown_char(char c)
{
	if (c != '1' && c != '0' && c != 'N' && c != ' '
		&& c != 'S' && c != 'E' && c != 'W')
	{
		ft_putstr_fd("Error\nUnknown character on the map! ❌\n", 2);
		return (1);
	}
	return (0);
}

int	check_player_char(char **map)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	while (map && map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_unknown_char(map[i][j]) == 1)
				return (1);
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
				player++;
			j++;
		}
		i++;
	}
	if (player != 1)
		ft_putstr_fd("Error\nToo many or any player on the map! ❌\n", 2);
	if (player != 1)
		return (1);
	return (0);
}

static void	check_first_last_line(char **map)
{
	int	i;
	int	last;

	i = skip_space(map[0]);
	last = len_db_char(map) - 1;
	while (map && map[0] && map[0][i])
	{
		if (map[0][i] != '1' && map[0][i] != ' ')
			break ;
		i++;
	}
	verify_map(map, i);
	i = skip_space(map[last]);
	while (map && map[last] && map[last][i])
	{
		if (map[last][i] != '1' && map[last][i] != ' ')
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

static int	verification_of_border(char *borders)
{
	int	i;

	i = 0;
	while (borders && (borders[i] == '1' || borders[i] == ' '))
		i++;
	if (i != ft_strlen(borders))
	{
		free(borders);
		return (1);
	}
	free(borders);
	return (0);
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
		j = skip_space(map[i]);
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
