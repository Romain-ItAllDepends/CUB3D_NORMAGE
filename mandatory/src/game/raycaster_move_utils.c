/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_move_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 06:47:42 by vgodart           #+#    #+#             */
/*   Updated: 2024/09/28 15:01:29 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	forward_and_back_utils_w(t_vars *vars, double moveSpeed)
{
	if (vars->map[(int)(vars->raycast->posx + vars->raycast->dirx
			* MOVE_SPEED)][(int)vars->raycast->posy] != '1'
		&& vars->map[(int)(vars->raycast->posx + vars->raycast->dirx
			* MOVE_SPEED)][(int)vars->raycast->posy] != ' ')
		vars->raycast->posx += vars->raycast->dirx * moveSpeed;
	if (vars->map[(int)(vars->raycast->posx)][(int)(vars->raycast->posy
			+ vars->raycast->diry * MOVE_SPEED)] != '1'
		&& vars->map[(int)(vars->raycast->posx)][(int)(vars->raycast->posy
			+ vars->raycast->diry * MOVE_SPEED)] != ' ')
		vars->raycast->posy += vars->raycast->diry * moveSpeed;
}

void	forward_and_back_utils_s(t_vars *vars, double moveSpeed)
{
	if (vars->map[(int)(vars->raycast->posx - vars->raycast->dirx
			* MOVE_SPEED)][(int)(vars->raycast->posy)] != '1'
		&& vars->map[(int)(vars->raycast->posx - vars->raycast->dirx
			* MOVE_SPEED)][(int)(vars->raycast->posy)] != ' ')
		vars->raycast->posx -= vars->raycast->dirx * moveSpeed;
	if (vars->map[(int)(vars->raycast->posx)][(int)(vars->raycast->posy
			- vars->raycast->diry * MOVE_SPEED)] != '1'
		&& vars->map[(int)(vars->raycast->posx)][(int)(vars->raycast->posy
			- vars->raycast->diry * MOVE_SPEED)] != ' ')
		vars->raycast->posy -= vars->raycast->diry * moveSpeed;
}

void	left_utils(t_vars *vars, double moveSpeed)
{
	if (vars->map[(int)(vars->raycast->posx - vars->raycast->planex
			* MOVE_SPEED)][(int)vars->raycast->posy] != '1'
		&& vars->map[(int)(vars->raycast->posx - vars->raycast->planex
			* MOVE_SPEED)][(int)vars->raycast->posy] != ' ')
		vars->raycast->posx -= vars->raycast->planex * moveSpeed;
	if (vars->map[(int)(vars->raycast->posx)][(int)(vars->raycast->posy
			- vars->raycast->planey * MOVE_SPEED)] != '1'
		&& vars->map[(int)(vars->raycast->posx)][(int)(vars->raycast->posy
			- vars->raycast->planey * MOVE_SPEED)] != ' ')
		vars->raycast->posy -= vars->raycast->planey * moveSpeed;
}

void	right_utils(t_vars *vars, double moveSpeed)
{
	if (vars->map[(int)(vars->raycast->posx + vars->raycast->planex
			* MOVE_SPEED)][(int)vars->raycast->posy] != '1'
		&& vars->map[(int)(vars->raycast->posx + vars->raycast->planex
			* MOVE_SPEED)][(int)vars->raycast->posy] != ' ')
		vars->raycast->posx += vars->raycast->planex * moveSpeed;
	if (vars->map[(int)(vars->raycast->posx)][(int)(vars->raycast->posy
			+ vars->raycast->planey * MOVE_SPEED)] != '1'
		&& vars->map[(int)(vars->raycast->posx)][(int)(vars->raycast->posy
			+ vars->raycast->planey * MOVE_SPEED)] != ' ')
		vars->raycast->posy += vars->raycast->planey * moveSpeed;
}
