/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_move_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 06:47:42 by vgodart           #+#    #+#             */
/*   Updated: 2024/09/17 06:47:45 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	forward_and_back_utils_e(t_vars *vars, double moveSpeed)
{
	if (vars->map[(int)(vars->raycast->posx + vars->raycast->dirx
			* MOVE_SPEED)][(int)vars->raycast->posy] == '0'
		|| vars->map[(int)(vars->raycast->posx + vars->raycast->dirx
			* MOVE_SPEED)][(int)vars->raycast->posy] == 'N')
		vars->raycast->posx += vars->raycast->dirx * (moveSpeed * 2);
	if (vars->map[(int)(vars->raycast->posx)][(int)(vars->raycast->posy
			+ vars->raycast->diry * MOVE_SPEED)] == '0'
		|| vars->map[(int)(vars->raycast->posx)][(int)(vars->raycast->posy
			+ vars->raycast->diry * MOVE_SPEED)] == 'N')
		vars->raycast->posy += vars->raycast->diry * (moveSpeed * 2);
}

void	forward_and_back_utils_w(t_vars *vars, double moveSpeed)
{
	if (vars->map[(int)(vars->raycast->posx + vars->raycast->dirx
			* MOVE_SPEED)][(int)vars->raycast->posy] == '0'
		|| vars->map[(int)(vars->raycast->posx + vars->raycast->dirx
			* MOVE_SPEED)][(int)vars->raycast->posy] == 'N')
		vars->raycast->posx += vars->raycast->dirx * moveSpeed;
	if (vars->map[(int)(vars->raycast->posx)][(int)(vars->raycast->posy
			+ vars->raycast->diry * MOVE_SPEED)] == '0'
		|| vars->map[(int)(vars->raycast->posx)][(int)(vars->raycast->posy
			+ vars->raycast->diry * MOVE_SPEED)] == 'N')
		vars->raycast->posy += vars->raycast->diry * moveSpeed;
}

void	forward_and_back_utils_s(t_vars *vars, double moveSpeed)
{
	if (vars->map[(int)(vars->raycast->posx - vars->raycast->dirx
			* MOVE_SPEED)][(int)(vars->raycast->posy)] == '0'
		|| vars->map[(int)(vars->raycast->posx - vars->raycast->dirx
			* MOVE_SPEED)][(int)(vars->raycast->posy)] == 'N')
		vars->raycast->posx -= vars->raycast->dirx * moveSpeed;
	if (vars->map[(int)(vars->raycast->posx)][(int)(vars->raycast->posy
			- vars->raycast->diry * MOVE_SPEED)] == '0'
		|| vars->map[(int)(vars->raycast->posx)][(int)(vars->raycast->posy
			- vars->raycast->diry * MOVE_SPEED)] == 'N')
		vars->raycast->posy -= vars->raycast->diry * moveSpeed;
}

void	right_and_left_utils(t_vars *vars, double moveSpeed)
{
	if (vars->map[(int)(vars->raycast->posx + vars->raycast->planex
			* MOVE_SPEED)][(int)vars->raycast->posy] == '0'
		|| vars->map[(int)(vars->raycast->posx + vars->raycast->planex
			* MOVE_SPEED)][(int)vars->raycast->posy] == 'N')
		vars->raycast->posx += vars->raycast->planex * moveSpeed;
	if (vars->map[(int)(vars->raycast->posx)][(int)(vars->raycast->posy
			+ vars->raycast->planey * MOVE_SPEED)] == '0'
		|| vars->map[(int)(vars->raycast->posx)][(int)(vars->raycast->posy
			+ vars->raycast->planey * MOVE_SPEED)] == 'N')
		vars->raycast->posy += vars->raycast->planey * moveSpeed;
}
