/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 07:15:58 by rgobet            #+#    #+#             */
/*   Updated: 2024/09/28 10:27:43 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

static void	floor_color(char *str, t_vars *vars)
{
	int		i;
	int		j;
	char	**rgb;

	j = 0;
	rgb = NULL;
	i = skip_space(str);
	if (str[i] == 'F'
		&& (str[i + 1] == ' ' || str[i + 1] == '\t'))
	{
		i++;
		i += skip_space(&str[i]);
		rgb = ft_split(&str[i], ',');
		while (rgb && rgb[j])
		{
			vars->floor[j] = ft_atoi((char *)rgb[j]);
			j++;
		}
	}
	if (!rgb && str[i] != '\0'
		&& !(str[skip_space(str)] == 'C' || str[skip_space(str)] == 'F'))
		color_error(vars);
	ft_free(rgb);
}

void	get_colors(char *str, t_vars *vars)
{
	int		i;
	int		j;
	char	**rgb;

	j = 0;
	rgb = NULL;
	i = skip_space(str);
	if (str[i] == 'C'
		&& (str[i + 1] == ' ' || str[i + 1] == '\t'))
	{
		i++;
		i += skip_space(&str[i]);
		rgb = ft_split(&str[i], ',');
		while (rgb && rgb[j])
		{
			vars->ceiling[j] = ft_atoi((char *)rgb[j]);
			j++;
		}
	}
	ft_free(rgb);
	floor_color(str, vars);
}

void	get_textures(char *str, t_vars *vars)
{
	int	i;
	int	tmp;

	i = skip_space(str);
	north_south_textures(str, vars, str[i]);
	if (str[i] == 'E' && str[i + 1] == 'A'
		&& (str[i + 2] == ' ' || str[i + 2] == '\t'))
	{
		tmp = skip_space(&str[i + 2]);
		i = tmp + 2;
		i += skip_space(&str[i]);
		vars->east = copy(&str[i]);
	}
	if (str[i] == 'W' && str[i + 1] == 'E'
		&& (str[i + 2] == ' ' || str[i + 2] == '\t'))
	{
		tmp = skip_space(&str[i + 2]);
		i = tmp + 2;
		i += skip_space(&str[i]);
		vars->west = copy(&str[i]);
	}
}

void	initialize_mini_map(t_vars *vars)
{
	vars->images->mini_map = mlx_new_image(vars->window,
			len_db_char(vars->map) * 100,
			WIDTH);
	if (!vars->images->mini_map)
	{
		ft_putstr_fd("Error\n occurred while creating the mini map image!\n",
			2);
		ft_free_vars(vars);
		exit(1);
	}
}

void	init(t_vars *vars, char *str)
{
	int		fd;
	char	**file;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		error_fd();
	file = get_file(fd);
	if (!file)
	{
		free(vars);
		error_malloc(fd, NULL);
	}
	close(fd);
	vars->map = get_map(file);
	if (!vars->map)
	{
		free(vars);
		error_malloc(fd, file);
	}
	raycast_vars_init(vars);
	get_player_pos(vars);
	get_parameters(vars, file);
	ft_free(file);
}
