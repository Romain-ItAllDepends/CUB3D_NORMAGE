/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parameters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 09:04:19 by rgobet            #+#    #+#             */
/*   Updated: 2024/09/15 09:13:34 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	get_parameters(t_vars *vars, char **file)
{
	int	i;

	i = 0;
	while (file && file[i])
	{
		get_textures(file[i], vars);
		get_colors(file[i], vars);
		i++;
	}
	if (!vars->north || !vars->south || !vars->east || !vars->west)
	{
		ft_putstr_fd("Error\nAn error occured while getting textures! ❌\n", 2);
		ft_free_vars(vars, -1);
	}
}

void	north_south_textures(char *str, t_vars *vars, char dir)
{
	int	i;

	i = skip_space(str);
	if (dir == 'N')
	{
		if (str[i] == 'N' && str[i + 1] == 'O'
			&& (str[i + 2] == ' ' || str[i + 2] == '\t'))
		{
			tmp = skip_space(&str[i + 2]);
			i = tmp + 2;
			i += skip_space(&str[i]);
			vars->north = copy(&str[i + 2]);
		}
	}
	if (dir == 'S')
	{
		if (str[i] == 'S' && str[i + 1] == 'O'
			&& (str[i + 2] == ' ' || str[i + 2] == '\t'))
		{
			tmp = skip_space(&str[i + 2]);
			i = tmp + 2;
			i += skip_space(&str[i]);
			vars->south = copy(&str[i]);
		}
	}
}
