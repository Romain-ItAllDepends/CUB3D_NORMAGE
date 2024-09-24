/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:03:22 by rgobet            #+#    #+#             */
/*   Updated: 2024/09/23 11:10:38 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void ft_shoot(t_vars *vars)
{
	int	i;

	i = 0;
	if (vars->is_shooting && vars->images->weapon1->instances->x > 650)
	{
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
	else if (vars->images->weapon1->instances->x < 700 && !vars->is_shooting)
	{
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
}
