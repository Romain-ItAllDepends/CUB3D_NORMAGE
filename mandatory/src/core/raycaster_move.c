/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 05:02:12 by vgodart           #+#    #+#             */
/*   Updated: 2024/09/15 10:25:08 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	forward_and_back(t_vars *vars, double moveSpeed)
{
	if (mlx_is_key_down(vars->window, MLX_KEY_W)
		&& (vars->map[(int)(vars->raycast->posx + vars->raycast->dirx * moveSpeed)][(int)vars->raycast->posy] != '1'
			&& vars->map[(int)(vars->raycast->posx + vars->raycast->dirx * moveSpeed)][(int)vars->raycast->posy] != ' '))
	{
		if (mlx_is_key_down(vars->window, MLX_KEY_E))
		{
			if(vars->map[(int)(vars->raycast->posx + vars->raycast->dirx * MOVE_SPEED)][(int)vars->raycast->posy] == '0' || vars->map[(int)(vars->raycast->posx + vars->raycast->dirx * MOVE_SPEED)][(int)vars->raycast->posy] == 'N')
				vars->raycast->posx += vars->raycast->dirx * (moveSpeed * 2);
			if(vars->map[(int)(vars->raycast->posx)][(int)(vars->raycast->posy + vars->raycast->diry * MOVE_SPEED)] == '0' || vars->map[(int)(vars->raycast->posx)][(int)(vars->raycast->posy + vars->raycast->diry * MOVE_SPEED)] == 'N')
				vars->raycast->posy += vars->raycast->diry * (moveSpeed * 2);
		}
		else
		{
			if(vars->map[(int)(vars->raycast->posx + vars->raycast->dirx * MOVE_SPEED)][(int)vars->raycast->posy] == '0' || vars->map[(int)(vars->raycast->posx + vars->raycast->dirx * MOVE_SPEED)][(int)vars->raycast->posy] == 'N')
				vars->raycast->posx += vars->raycast->dirx * moveSpeed;
			if(vars->map[(int)(vars->raycast->posx)][(int)(vars->raycast->posy + vars->raycast->diry * MOVE_SPEED)] == '0' || vars->map[(int)(vars->raycast->posx)][(int)(vars->raycast->posy + vars->raycast->diry * MOVE_SPEED)] == 'N')
				vars->raycast->posy += vars->raycast->diry * moveSpeed;
		}
	}
	if (mlx_is_key_down(vars->window, MLX_KEY_S)
		&& (vars->map[(int)(vars->raycast->posx - vars->raycast->dirx * moveSpeed)][(int)vars->raycast->posy] != '1'
			&& vars->map[(int)(vars->raycast->posx - vars->raycast->dirx * moveSpeed)][(int)vars->raycast->posy] != ' '))
	{
		if(vars->map[(int)(vars->raycast->posx - vars->raycast->dirx * MOVE_SPEED)][(int)(vars->raycast->posy)] == '0' 
			|| vars->map[(int)(vars->raycast->posx - vars->raycast->dirx * MOVE_SPEED)][(int)(vars->raycast->posy)] == 'N')
			vars->raycast->posx -= vars->raycast->dirx * moveSpeed;
		if(vars->map[(int)(vars->raycast->posx)][(int)(vars->raycast->posy - vars->raycast->diry * MOVE_SPEED)] == '0'
			|| vars->map[(int)(vars->raycast->posx)][(int)(vars->raycast->posy - vars->raycast->diry * MOVE_SPEED)] == 'N')
			vars->raycast->posy -= vars->raycast->diry * moveSpeed;
	}
}

void	right_and_left(t_vars *vars, double moveSpeed)
{
	if (mlx_is_key_down(vars->window, MLX_KEY_A)
		&& (vars->map[(int)vars->raycast->posx][(int)(vars->raycast->posy - vars->raycast->planey * moveSpeed)] != '1'
			&& vars->map[(int)vars->raycast->posx][(int)(vars->raycast->posy - vars->raycast->planey * moveSpeed)] != ' '))
	{
		if (vars->map[(int)(vars->raycast->posx - vars->raycast->planex * MOVE_SPEED)][(int)vars->raycast->posy] == '0' || vars->map[(int)(vars->raycast->posx - vars->raycast->planex * MOVE_SPEED)][(int)vars->raycast->posy] == 'N')
			vars->raycast->posx -= vars->raycast->planex * moveSpeed;
		if(vars->map[(int)(vars->raycast->posx)][(int)(vars->raycast->posy - vars->raycast->planey * MOVE_SPEED)] == '0' || vars->map[(int)(vars->raycast->posx)][(int)(vars->raycast->posy - vars->raycast->planey * MOVE_SPEED)] == 'N')
			vars->raycast->posy -= vars->raycast->planey * moveSpeed;
	}
	if (mlx_is_key_down(vars->window, MLX_KEY_D)
		&& (vars->map[(int)(vars->raycast->posx + vars->raycast->planex * moveSpeed)][(int)vars->raycast->posy] != '1'
			&& vars->map[(int)(vars->raycast->posx + vars->raycast->planex * moveSpeed)][(int)vars->raycast->posy] != ' '))
	{
		if(vars->map[(int)(vars->raycast->posx + vars->raycast->planex * MOVE_SPEED)][(int)vars->raycast->posy] == '0' || vars->map[(int)(vars->raycast->posx + vars->raycast->planex * MOVE_SPEED)][(int)vars->raycast->posy] == 'N')
			vars->raycast->posx += vars->raycast->planex * moveSpeed;
		if(vars->map[(int)(vars->raycast->posx)][(int)(vars->raycast->posy + vars->raycast->planey * MOVE_SPEED)] == '0' || vars->map[(int)(vars->raycast->posx)][(int)(vars->raycast->posy + vars->raycast->planey * MOVE_SPEED)] == 'N')
			vars->raycast->posy += vars->raycast->planey * moveSpeed;
	}
}

void	rotate_camera(t_vars *vars, double rotSpeed)
{
	double oldDirX;
	double oldPlaneX;

	oldDirX = vars->raycast->dirx;
	oldPlaneX = vars->raycast->planex;
	if (mlx_is_key_down(vars->window, MLX_KEY_RIGHT))
	{
		vars->raycast->dirx = vars->raycast->dirx * cos(-rotSpeed) - vars->raycast->diry * sin(-rotSpeed);
		vars->raycast->diry = oldDirX * sin(-rotSpeed) + vars->raycast->diry * cos(-rotSpeed);
		vars->raycast->planex = vars->raycast->planex * cos(-rotSpeed) - vars->raycast->planey * sin(-rotSpeed);
		vars->raycast->planey = oldPlaneX * sin(-rotSpeed) + vars->raycast->planey * cos(-rotSpeed);
	}
	if (mlx_is_key_down(vars->window, MLX_KEY_LEFT))
	{
		vars->raycast->dirx = vars->raycast->dirx * cos(rotSpeed) - vars->raycast->diry * sin(rotSpeed);
		vars->raycast->diry = oldDirX * sin(rotSpeed) + vars->raycast->diry * cos(rotSpeed);
		vars->raycast->planex = vars->raycast->planex * cos(rotSpeed) - vars->raycast->planey * sin(rotSpeed);
		vars->raycast->planey = oldPlaneX * sin(rotSpeed) + vars->raycast->planey * cos(rotSpeed);
	}
}
