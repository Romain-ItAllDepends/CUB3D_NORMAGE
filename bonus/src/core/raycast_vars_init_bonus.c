/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_vars_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 08:55:47 by rgobet            #+#    #+#             */
/*   Updated: 2024/09/23 11:07:48 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	get_directions(t_vars *vars, int i, int j)
{
	if (vars->map[i][j] == 'N')
	{
		vars->raycast->facing = NORTH;
		vars->raycast->dirx = -1;
		vars->raycast->diry = 0;
	}
	else if (vars->map[i][j] == 'S')
	{
		vars->raycast->facing = SOUTH;
		vars->raycast->dirx = 1;
		vars->raycast->diry = 0;
	}
	else if (vars->map[i][j] == 'E')
	{
		vars->raycast->facing = EAST;
		vars->raycast->dirx = 0;
		vars->raycast->diry = 1;
	}
	else if (vars->map[i][j] == 'W')
	{
		vars->raycast->facing = WEST;
		vars->raycast->dirx = 0;
		vars->raycast->diry = -1;
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
				vars->raycast->posx = i;
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
		ft_free_vars(vars);
	vars->images = ft_calloc(1, sizeof(t_images));
	if (!vars->images)
	{
		free(vars->textures);
		vars->textures = NULL;
		ft_free_vars(vars);
	}
	vars->raycast = ft_calloc(1, sizeof(t_raycast));
	if (!vars->raycast)
	{
		free(vars->images);
		free(vars->textures);
		vars->images = NULL;
		vars->textures = NULL;
		ft_free_vars(vars);
	}
	vars->raycast->planex = 0;
	vars->raycast->planey = 2 * atan(0.9 / 1.0);
	vars->weapon_initial_x = 650;
	vars->weapon_initial_y = 650;
	vars->weapon_recoil_x = vars->weapon_initial_x - 10;
	vars->weapon_recoil_y = vars->weapon_initial_y - 10;
}
