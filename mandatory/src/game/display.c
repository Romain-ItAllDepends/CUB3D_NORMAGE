/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 08:55:47 by rgobet            #+#    #+#             */
/*   Updated: 2024/10/02 00:06:47 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	dda(t_vars *vars)
{
	while (vars->raycast->hit == 0)
	{
		if (vars->raycast->side_distx < vars->raycast->side_disty)
		{
			vars->raycast->side_distx += vars->raycast->delta_distx;
			vars->raycast->mapx += vars->raycast->stepx;
			vars->raycast->side = 0;
		}
		else
		{
			vars->raycast->side_disty += vars->raycast->delta_disty;
			vars->raycast->mapy += vars->raycast->stepy;
			vars->raycast->side = 1;
		}
		if (!vars->map[vars->raycast->mapx]
			|| !vars->map[vars->raycast->mapx][vars->raycast->mapy])
			vars->raycast->hit = 1;
		else if (vars->map[vars->raycast->mapx][vars->raycast->mapy] == '1'
			|| vars->map[vars->raycast->mapx][vars->raycast->mapy] == ' ')
			vars->raycast->hit = 1;
	}
}

static void	cam_pos(t_vars *vars, int x)
{
	vars->raycast->camerax = 2 * x / (double)WIDTH - 1;
	vars->raycast->ray_dirx = vars->raycast->dirx
		+ vars->raycast->planex * vars->raycast->camerax;
	vars->raycast->ray_diry = vars->raycast->diry
		+ vars->raycast->planey * vars->raycast->camerax;
}

static void	delta_dist(t_vars *vars)
{
	if (vars->raycast->ray_dirx == 0)
		vars->raycast->delta_distx = MAX;
	else
		vars->raycast->delta_distx = fabs(1 / vars->raycast->ray_dirx);
	if (vars->raycast->ray_diry == 0)
		vars->raycast->delta_disty = MAX;
	else
		vars->raycast->delta_disty = fabs(1 / vars->raycast->ray_diry);
}

static void	side_dist(t_vars *vars)
{
	vars->raycast->hit = 0;
	if (vars->raycast->ray_dirx < 0)
	{
		vars->raycast->stepx = -1;
		vars->raycast->side_distx = (vars->raycast->posx - vars->raycast->mapx)
			* vars->raycast->delta_distx;
	}
	else
	{
		vars->raycast->stepx = 1;
		vars->raycast->side_distx = (vars->raycast->mapx + 1.0
				- vars->raycast->posx) * vars->raycast->delta_distx;
	}
	if (vars->raycast->ray_diry < 0)
	{
		vars->raycast->stepy = -1;
		vars->raycast->side_disty = (vars->raycast->posy
				- vars->raycast->mapy) * vars->raycast->delta_disty;
	}
	else
	{
		vars->raycast->stepy = 1;
		vars->raycast->side_disty = (vars->raycast->mapy + 1.0
				- vars->raycast->posy) * vars->raycast->delta_disty;
	}
}

void	raycast(t_vars *vars, int x)
{
	vars->raycast->mapx = (int)vars->raycast->posx;
	vars->raycast->mapy = (int)vars->raycast->posy;
	cam_pos(vars, x);
	delta_dist(vars);
	side_dist(vars);
	dda(vars);
	if (vars->raycast->side == 0)
	{
		vars->raycast->perp_wall_dist = (vars->raycast->side_distx
				- vars->raycast->delta_distx);
	}
	else
	{
		vars->raycast->perp_wall_dist = (vars->raycast->side_disty
				- vars->raycast->delta_disty);
	}
	vars->raycast->line_height
		= (int)(TEXHEIGHT / vars->raycast->perp_wall_dist);
	wall_start_end(vars);
	texture_coord(vars);
	if (vars->raycast->facing == SOUTH || vars->raycast->facing == WEST)
		x = abs(x - WIDTH - 1);
	put_pixels(vars, x);
}
