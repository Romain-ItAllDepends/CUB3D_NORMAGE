/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_move_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 05:02:12 by vgodart           #+#    #+#             */
/*   Updated: 2024/10/01 09:58:47 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

static void	rc_utils(t_vars *vars, double rotSpeed, double old_dirx,
				double old_planex);

void	forward_and_back(t_vars *vars, double moveSpeed)
{
	if (mlx_is_key_down(vars->window, MLX_KEY_W)
		&& (vars->map[(int)(vars->raycast->posx + vars->raycast->dirx
				* moveSpeed)][(int)vars->raycast->posy] != '1'
			&& vars->map[(int)(vars->raycast->posx + vars->raycast->dirx
				* moveSpeed)][(int)vars->raycast->posy] != ' '))
		forward_and_back_utils_w(vars, moveSpeed);
	if (mlx_is_key_down(vars->window, MLX_KEY_S)
		&& (vars->map[(int)(vars->raycast->posx - vars->raycast->dirx
				* moveSpeed)][(int)vars->raycast->posy] != '1'
			&& vars->map[(int)(vars->raycast->posx - vars->raycast->dirx
				* moveSpeed)][(int)vars->raycast->posy] != ' '))
		forward_and_back_utils_s(vars, moveSpeed);
}

void	right_and_left(t_vars *vars, double moveSpeed)
{
	if (vars->raycast->facing == SOUTH || vars->raycast->facing == WEST)
	{
		right_and_left_south_west(vars, moveSpeed);
	}
	else
	{
		right_and_left_other(vars, moveSpeed);
	}
}

static void	rotate_camera_left_right(t_vars *vars, double rotSpeed,
		double old_dirx, double old_planex)
{
	vars->raycast->dirx = vars->raycast->dirx * cos(-rotSpeed)
		- vars->raycast->diry * sin(-rotSpeed);
	vars->raycast->diry = old_dirx * sin(-rotSpeed)
		+ vars->raycast->diry * cos(-rotSpeed);
	vars->raycast->planex = vars->raycast->planex * cos(-rotSpeed)
		- vars->raycast->planey * sin(-rotSpeed);
	vars->raycast->planey = old_planex * sin(-rotSpeed)
		+ vars->raycast->planey * cos(-rotSpeed);
}

void	rotate_camera(t_vars *vars, double rotSpeed)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = vars->raycast->dirx;
	old_planex = vars->raycast->planex;
	if (mlx_is_key_down(vars->window, MLX_KEY_RIGHT))
		rotate_camera_left_right(vars, rotSpeed, old_dirx, old_planex);
	else if (mlx_is_key_down(vars->window, MLX_KEY_LEFT))
		rc_utils(vars, rotSpeed, old_dirx, old_planex);
}

static void	rc_utils(t_vars *vars, double rotSpeed, double old_dirx,
		double old_planex)
{
	vars->raycast->dirx = vars->raycast->dirx * cos(rotSpeed)
		- vars->raycast->diry * sin(rotSpeed);
	vars->raycast->diry = old_dirx * sin(rotSpeed) + vars->raycast->diry
		* cos(rotSpeed);
	vars->raycast->planex = vars->raycast->planex * cos(rotSpeed)
		- vars->raycast->planey * sin(rotSpeed);
	vars->raycast->planey = old_planex * sin(rotSpeed) + vars->raycast->planey
		* cos(rotSpeed);
}
