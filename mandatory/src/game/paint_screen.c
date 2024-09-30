/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:49:46 by rgobet            #+#    #+#             */
/*   Updated: 2024/09/28 15:13:58 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	paint_on_screen(t_vars *vars)
{
	int	x;

	x = 0;
	mlx_delete_image(vars->window, vars->images->screen);
	vars->images->screen = mlx_new_image(vars->window, WIDTH, HEIGHT);
	while (x < WIDTH)
	{
		raycast(vars, x);
		x++;
	}
	mlx_image_to_window(vars->window, vars->images->screen, 0, 0);
	mlx_set_instance_depth(vars->images->screen->instances, (int32_t)1);
}
