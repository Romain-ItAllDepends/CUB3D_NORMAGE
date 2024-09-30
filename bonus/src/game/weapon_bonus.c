/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:03:22 by rgobet            #+#    #+#             */
/*   Updated: 2024/09/30 15:32:26 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

static void	ft_shooting(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < 500000)
	{
		if (i % 10000 == 0)
		{
			vars->images->weapon1->instances->x -= 1;
			vars->images->weapon1->instances->y -= 1;
		}
		i++;
	}
}

static void	ft_reloading(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < 500000)
	{
		if (i % 10000 == 0)
		{
			vars->images->weapon1->instances->x += 1;
			vars->images->weapon1->instances->y += 1;
		}
		i++;
	}
}

void	ft_shoot(t_vars *vars)
{
	if (vars->is_shooting && vars->images->weapon1->instances->x > 650)
	{
		ft_shooting(vars);
	}
	else if (vars->images->weapon1->instances->x < 700 && !vars->is_shooting)
	{
		ft_reloading(vars);
	}
}

static void	rotate_raycast(t_vars *vars, double angle)
{
	double	olddirx;
	double	oldplanex;

	olddirx = vars->raycast->dirx;
	oldplanex = vars->raycast->planex;
	vars->raycast->dirx = vars->raycast->dirx * cos(angle)
		- vars->raycast->diry * sin(angle);
	vars->raycast->diry = olddirx * sin(angle)
		+ vars->raycast->diry * cos(angle);
	vars->raycast->planex = vars->raycast->planex * cos(angle)
		- vars->raycast->planey * sin(angle);
	vars->raycast->planey = oldplanex * sin(angle)
		+ vars->raycast->planey * cos(angle);
}

void	update_raycast(t_vars *vars, int x, double rotspeed)
{
	double	angle;

	angle = (WIDTH / 2 - x) * rotspeed / WIDTH;
	rotate_raycast(vars, angle);
}
