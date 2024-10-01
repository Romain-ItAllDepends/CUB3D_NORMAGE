/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_move_more_utils_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:11:28 by vgodart           #+#    #+#             */
/*   Updated: 2024/10/01 14:11:30 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	right_and_left_south_west(t_vars *vars, double moveSpeed)
{
	if (mlx_is_key_down(vars->window, MLX_KEY_D)
		&& (vars->map[(int)vars->raycast->posx][(int)(vars->raycast->posy
			- vars->raycast->planey * moveSpeed)] != '1'
			&& vars->map[(int)vars->raycast->posx][(int)(vars->raycast->posy
				- vars->raycast->planey * moveSpeed)] != ' '))
		left_utils(vars, MOVE_SPEED);
	if (mlx_is_key_down(vars->window, MLX_KEY_A)
		&& (vars->map[(int)(vars->raycast->posx + vars->raycast->planex
				* moveSpeed)][(int)vars->raycast->posy] != '1'
			&& vars->map[(int)(vars->raycast->posx + vars->raycast->planex
				* moveSpeed)][(int)vars->raycast->posy] != ' '))
		right_utils(vars, MOVE_SPEED);
}

void	right_and_left_other(t_vars *vars, double moveSpeed)
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
