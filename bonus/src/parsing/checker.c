/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:17:49 by rgobet            #+#    #+#             */
/*   Updated: 2024/09/18 12:07:54 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	textures_checker(char *str)
{
	int				i;
	mlx_texture_t	*texture;

	if (!str)
	{
		ft_putstr_fd("Error\nThe path of a texture is missing! ❌\n", 2);
		return (1);
	}
	i = skip_space(str);
	texture = mlx_load_png(&str[i]);
	if (!texture)
	{
		ft_putstr_fd("Error\nSomething is wrong about your texture! ❌\n", 2);
		return (1);
	}
	mlx_delete_texture(texture);
	return (0);
}

static int	rgb_checker(char *str)
{
	int		i;
	int		color;
	char	**rgb;

	i = skip_space(str);
	rgb = ft_split(&str[i], ',');
	i = 0;
	while (rgb && rgb[i])
	{
		if (ft_isalpha(rgb[i]) == 1)
			color = ft_atoi(rgb[i]);
		else
		{
			ft_free(rgb);
			ft_putstr_fd("Error\nRGB can't be an alpha! ❌\n", 2);
			return (1);
		}
		if (!(color >= 0 && color < 256 && ft_strlen(rgb[1]) < 4))
			break ;
		i++;
	}
	if (verify_rgb(rgb, i) == 1)
		return (1);
	return (0);
}

static int	info_checker(char *str)
{
	static int	i;
	int			exit_code;

	i++;
	exit_code = 0;
	if (str && str[0] && str[1] && str[2]
		&& ((str[0] == 'S' && str[1] == 'O')
			|| (str[0] == 'W' && str[1] == 'E')
			|| (str[0] == 'N' && str[1] == 'O')
			|| (str[0] == 'E' && str[1] == 'A'))
		&& (str[2] == ' ' || str[2] == '\t'))
		exit_code = textures_checker(&str[2]);
	else if (str && str[0] && str[1]
		&& (str[0] == 'F' || str[0] == 'C')
		&& (str[1] == ' ' || str[1] == '\t'))
		exit_code = rgb_checker(&str[1]);
	return (exit_code);
}

void	check_data(char **file)
{
	int	i;
	int	start;

	i = 0;
	while (file && file[i])
	{
		start = skip_space(file[i]);
		if (file[i][start] == '1' || file[i][start] == ' ')
		{
			i++;
			continue ;
		}
		if (file[i][start] && file[i][start] != '\0')
		{
			if (info_checker(&file[i][start]) == 1)
			{
				ft_free(file);
				exit(1);
			}
		}
		i++;
	}
}

void	check_map(char **map)
{
	if (!map)
	{
		ft_putstr_fd("Error\nAny map in the file! ❌\n", 2);
		exit(1);
	}
	if (check_player_char(map) == 1)
	{
		ft_free(map);
		exit(1);
	}
	if (check_closed_map(map) == 1)
	{
		ft_putstr_fd("Error\nThe map isn't closed! ❌\n", 2);
		ft_free(map);
		exit(1);
	}
}
