/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 01:17:40 by vgodart           #+#    #+#             */
/*   Updated: 2024/10/01 08:44:47 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

static int	is_unknown_char(char c)
{
	if (c != '1' && c != '0' && c != 'N' && c != ' ' && c != 'S' && c != 'E'
		&& c != 'W')
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

static void	check_diff_wall_case1(char **map, char *tab, int x)
{
	int	i;
	int	j;

	i = ft_strlen(map[x]) - 1;
	j = ft_strlen(map[x - 1]) - 1;
	while (i != j)
	{
		if (map[x][i] != '1')
		{
			free(map);
			free(tab);
			ft_putstr_fd("Error\nMap isn't closed! ❌\n", 2);
			exit(1);
		}
		i--;
	}
}

static void	check_diff_wall_case2(char **map, char *tab, int x)
{
	int	i;
	int	j;

	i = ft_strlen(map[x]) - 1;
	j = ft_strlen(map[x - 1]) - 1;
	while (j != i)
	{
		if (map[x - 1][j] != '1')
		{
			free(map);
			free(tab);
			ft_putstr_fd("Error\nMap isn't closed! ❌\n", 2);
			exit(1);
		}
		j--;
	}
}

void	check_diff_wall(char **map, char *tab, int x)
{
	int	i;
	int	j;

	i = ft_strlen(map[x]) - 1;
	j = ft_strlen(map[x - 1]) - 1;
	if (i > j)
	{
		check_diff_wall_case1(map, tab, x);
	}
	else
	{
		check_diff_wall_case2(map, tab, x);
	}
}
