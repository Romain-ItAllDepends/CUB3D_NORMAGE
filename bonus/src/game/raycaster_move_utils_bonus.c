/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_move_utils_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 06:47:42 by vgodart           #+#    #+#             */
/*   Updated: 2024/09/28 10:29:35 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	forward_and_back_utils_w(t_vars *vars, double moveSpeed)
{
	if (vars->map[(int)(vars->raycast->posx + vars->raycast->dirx
			* MOVE_SPEED)][(int)vars->raycast->posy] == '0'
			|| vars->map[(int)(vars->raycast->posx + vars->raycast->dirx
			* MOVE_SPEED)][(int)vars->raycast->posy] == 'S'
			|| vars->map[(int)(vars->raycast->posx + vars->raycast->dirx
			* MOVE_SPEED)][(int)vars->raycast->posy] == 'N'
			|| vars->map[(int)(vars->raycast->posx + vars->raycast->dirx
			* MOVE_SPEED)][(int)vars->raycast->posy] == 'W'
			|| vars->map[(int)(vars->raycast->posx + vars->raycast->dirx
			* MOVE_SPEED)][(int)vars->raycast->posy] == 'E')
		vars->raycast->posx += vars->raycast->dirx * moveSpeed;
	if (vars->map[(int)(vars->raycast->posx)][(int)(vars->raycast->posy
			+ vars->raycast->diry * MOVE_SPEED)] == '0'
			|| vars->map[(int)(vars->raycast->posx)][(int)(vars->raycast->posy
			+ vars->raycast->diry * MOVE_SPEED)] == 'S'
			|| vars->map[(int)(vars->raycast->posx)][(int)(vars->raycast->posy
			+ vars->raycast->diry * MOVE_SPEED)] == 'N'
			|| vars->map[(int)(vars->raycast->posx)][(int)(vars->raycast->posy
			+ vars->raycast->diry * MOVE_SPEED)] == 'W'
			|| vars->map[(int)(vars->raycast->posx)][(int)(vars->raycast->posy
			+ vars->raycast->diry * MOVE_SPEED)] == 'E')
		vars->raycast->posy += vars->raycast->diry * moveSpeed;
}

void	forward_and_back_utils_s(t_vars *vars, double moveSpeed)
{
	if (vars->map[(int)(vars->raycast->posx - vars->raycast->dirx
			* MOVE_SPEED)][(int)(vars->raycast->posy)] == '0'
			|| vars->map[(int)(vars->raycast->posx - vars->raycast->dirx
			* MOVE_SPEED)][(int)(vars->raycast->posy)] == 'S'
			|| vars->map[(int)(vars->raycast->posx - vars->raycast->dirx
			* MOVE_SPEED)][(int)(vars->raycast->posy)] == 'N'
			|| vars->map[(int)(vars->raycast->posx - vars->raycast->dirx
			* MOVE_SPEED)][(int)(vars->raycast->posy)] == 'W'
			|| vars->map[(int)(vars->raycast->posx - vars->raycast->dirx
			* MOVE_SPEED)][(int)(vars->raycast->posy)] == 'E')
		vars->raycast->posx -= vars->raycast->dirx * moveSpeed;
	if (vars->map[(int)(vars->raycast->posx)][(int)(vars->raycast->posy
			- vars->raycast->diry * MOVE_SPEED)] == '0'
			|| vars->map[(int)(vars->raycast->posx)][(int)(vars->raycast->posy
			- vars->raycast->diry * MOVE_SPEED)] == 'S'
			|| vars->map[(int)(vars->raycast->posx)][(int)(vars->raycast->posy
			- vars->raycast->diry * MOVE_SPEED)] == 'N'
			|| vars->map[(int)(vars->raycast->posx)][(int)(vars->raycast->posy
			- vars->raycast->diry * MOVE_SPEED)] == 'W'
			|| vars->map[(int)(vars->raycast->posx)][(int)(vars->raycast->posy
			- vars->raycast->diry * MOVE_SPEED)] == 'E')
		vars->raycast->posy -= vars->raycast->diry * moveSpeed;
}

void	left_utils(t_vars *vars, double moveSpeed)
{
	if (vars->map[(int)(vars->raycast->posx - vars->raycast->planex
			* MOVE_SPEED)][(int)vars->raycast->posy] == '0'
			|| vars->map[(int)(vars->raycast->posx - vars->raycast->planex
			* MOVE_SPEED)][(int)vars->raycast->posy] == 'S'
			|| vars->map[(int)(vars->raycast->posx - vars->raycast->planex
			* MOVE_SPEED)][(int)vars->raycast->posy] == 'N'
			|| vars->map[(int)(vars->raycast->posx - vars->raycast->planex
			* MOVE_SPEED)][(int)vars->raycast->posy] == 'W'
			|| vars->map[(int)(vars->raycast->posx - vars->raycast->planex
			* MOVE_SPEED)][(int)vars->raycast->posy] == 'E')
		vars->raycast->posx -= vars->raycast->planex * moveSpeed;
	if (vars->map[(int)(vars->raycast->posx)][(int)(vars->raycast->posy
			- vars->raycast->planey * MOVE_SPEED)] == '0'
			|| vars->map[(int)(vars->raycast->posx)][(int)(vars->raycast->posy
			- vars->raycast->planey * MOVE_SPEED)] == 'S'
			|| vars->map[(int)(vars->raycast->posx)][(int)(vars->raycast->posy
			- vars->raycast->planey * MOVE_SPEED)] == 'N'
			|| vars->map[(int)(vars->raycast->posx)][(int)(vars->raycast->posy
			- vars->raycast->planey * MOVE_SPEED)] == 'W'
			|| vars->map[(int)(vars->raycast->posx)][(int)(vars->raycast->posy
			- vars->raycast->planey * MOVE_SPEED)] == 'E')
		vars->raycast->posy -= vars->raycast->planey * moveSpeed;
}

void	right_utils(t_vars *vars, double moveSpeed)
{
	if (vars->map[(int)(vars->raycast->posx + vars->raycast->planex
			* MOVE_SPEED)][(int)vars->raycast->posy] == '0'
			|| vars->map[(int)(vars->raycast->posx + vars->raycast->planex
			* MOVE_SPEED)][(int)vars->raycast->posy] == 'S'
			|| vars->map[(int)(vars->raycast->posx + vars->raycast->planex
			* MOVE_SPEED)][(int)vars->raycast->posy] == 'N'
			|| vars->map[(int)(vars->raycast->posx + vars->raycast->planex
			* MOVE_SPEED)][(int)vars->raycast->posy] == 'W'
			|| vars->map[(int)(vars->raycast->posx + vars->raycast->planex
			* MOVE_SPEED)][(int)vars->raycast->posy] == 'E')
		vars->raycast->posx += vars->raycast->planex * moveSpeed;
	if (vars->map[(int)(vars->raycast->posx)][(int)(vars->raycast->posy
			+ vars->raycast->planey * MOVE_SPEED)] == '0'
			|| vars->map[(int)(vars->raycast->posx)][(int)(vars->raycast->posy
			+ vars->raycast->planey * MOVE_SPEED)] == 'S'
			|| vars->map[(int)(vars->raycast->posx)][(int)(vars->raycast->posy
			+ vars->raycast->planey * MOVE_SPEED)] == 'N'
			|| vars->map[(int)(vars->raycast->posx)][(int)(vars->raycast->posy
			+ vars->raycast->planey * MOVE_SPEED)] == 'W'
			|| vars->map[(int)(vars->raycast->posx)][(int)(vars->raycast->posy
			+ vars->raycast->planey * MOVE_SPEED)] == 'E')
		vars->raycast->posy += vars->raycast->planey * moveSpeed;
}
