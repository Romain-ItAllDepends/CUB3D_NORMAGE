/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 05:02:12 by vgodart           #+#    #+#             */
/*   Updated: 2024/09/28 15:25:00 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

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
	if (mlx_is_key_down(vars->window, MLX_KEY_A)
		&& (vars->map[(int)vars->raycast->posx][(int)(vars->raycast->posy
			- vars->raycast->planey * moveSpeed)] != '1'
			&& vars->map[(int)vars->raycast->posx][(int)(vars->raycast->posy
				- vars->raycast->planey * moveSpeed)] != ' '))
		left_utils(vars, MOVE_SPEED);
	if (mlx_is_key_down(vars->window, MLX_KEY_D)
		&& (vars->map[(int)(vars->raycast->posx + vars->raycast->planex
				* moveSpeed)][(int)vars->raycast->posy] != '1'
			&& vars->map[(int)(vars->raycast->posx + vars->raycast->planex
				* moveSpeed)][(int)vars->raycast->posy] != ' '))
		right_utils(vars, MOVE_SPEED);
}

void	rotate_camera(t_vars *vars, double rotSpeed)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = vars->raycast->dirx;
	old_planex = vars->raycast->planex;
	if ((mlx_is_key_down(vars->window, MLX_KEY_RIGHT) && vars->raycast->facing == NORTH)
		|| (mlx_is_key_down(vars->window, MLX_KEY_LEFT) && vars->raycast->facing == SOUTH))
	{
		vars->raycast->dirx = vars->raycast->dirx * cos(-rotSpeed)
			- vars->raycast->diry * sin(-rotSpeed);
		vars->raycast->diry = old_dirx * sin(-rotSpeed) + vars->raycast->diry
			* cos(-rotSpeed);
		vars->raycast->planex = vars->raycast->planex * cos(-rotSpeed)
			- vars->raycast->planey * sin(-rotSpeed);
		vars->raycast->planey = old_planex * sin(-rotSpeed)
			+ vars->raycast->planey * cos(-rotSpeed);
	}
	else if ((mlx_is_key_down(vars->window, MLX_KEY_LEFT) && vars->raycast->facing == NORTH)
		|| (mlx_is_key_down(vars->window, MLX_KEY_RIGHT) && vars->raycast->facing == SOUTH))
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
