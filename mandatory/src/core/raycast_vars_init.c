/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_vars_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 08:55:47 by rgobet            #+#    #+#             */
/*   Updated: 2024/09/15 09:51:39 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	get_directions(t_vars *vars, int i, int j)
{
	if (vars->map[i][j] == 'N')
	{
		vars->facing = NORTH;
		vars->dirX = -1;
		vars->dirY = 0;
	}
	else if (vars->map[i][j] == 'S')
	{
		vars->facing = SOUTH;
		vars->dirX = 1;
		vars->dirY = 0;
	}
	else if (vars->map[i][j] == 'E')
	{
		vars->facing = EAST;
		vars->dirX = 0;
		vars->dirY = 1;
	}
	else if (vars->map[i][j] == 'W')
	{
		vars->facing = WEST;
		vars->dirX = 0;
		vars->dirY = -1;
	}
}

void	get_player_pos(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'N' || vars->map[i][j] == 'S'
				|| vars->map[i][j] == 'E' || vars->map[i][j] == 'W')
			{
				vars->->raycast->posx = i;
				vars->raycast->posy = j;
				get_directions(vars, i, j);
			}
			j++;
		}
		i++;
	}
}

void	raycast_vars_init(t_vars *vars)
{
	vars->textures = ft_calloc(1, sizeof(t_textures));
	if (!vars->textures)
		ft_free_vars(vars, -1);
	vars->images = ft_calloc(1, sizeof(t_images));
	if (!vars->images)
	{
		free(vars->textures);
		ft_free_vars(vars, -1);
	}
	vars->raycast = ft_calloc(1, sizeof(t_raycast));
	if (!vars->raycast)
	{
		free(vars->images);
		free(vars->textures);
		ft_free_vars(vars, -1);
	}
	vars->raycast->planex = 0;
	vars->raycast->planey = 2 * atan(0.9 / 1.0);
}
